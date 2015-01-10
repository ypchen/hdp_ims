<?php
	// Functions

	function notification_email_text($subject, $body) {
		global $imsOnMailGun, $imsUseEmail, $imsBotEmail, $imsAdminEmail;

		if (!empty($imsUseEmail)) {
			$to = $imsAdminEmail;
			// Make the message body Unix-compliant
			$body = str_replace("\r\n", "\n", $body);
			if (!empty($imsOnMailGun)) {
				$ch = curl_init();

				curl_setopt($ch, CURLOPT_HTTPAUTH, CURLAUTH_BASIC);
				curl_setopt($ch, CURLOPT_USERPWD, 'api:' . @getenv('MAILGUN_API_KEY'));
				curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);

				curl_setopt($ch, CURLOPT_CUSTOMREQUEST, 'POST');
				$mailgun_domain  = explode('@', @getenv('MAILGUN_SMTP_LOGIN'));
				curl_setopt($ch, CURLOPT_URL, 'https://api.mailgun.net/v2/' . $mailgun_domain[1] . '/messages');
				curl_setopt($ch, CURLOPT_POSTFIELDS,
					array(
						'from'    => $imsBotEmail,
						'to'      => $to,
						'subject' => $subject,
						'text'    => $body
					));
				$result = curl_exec($ch);
				curl_close($ch);

				return $result;
			}
			else {
				$headers = "From: $imsBotEmail";
				return mail($to, $subject, $body, $headers);
			}
		}
		else {
			return false;
		}
	}

// http://www.php.net/manual/en/function.curl-setopt.php#95027
// http://stackoverflow.com/questions/3890631/php-curl-with-curlopt-followlocation-error
	function curl_redirect_exec($ch, $url_array, &$redirects, $curlopt_header = false) {
		curl_setopt($ch, CURLOPT_HEADER, true);
		curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
		$data = curl_exec($ch);
		$http_code = curl_getinfo($ch, CURLINFO_HTTP_CODE);
		if ($http_code == 301 || $http_code == 302) {
			list($header) = explode("\r\n\r\n", $data, 2);
			$matches = array();
			//this part has been changes from the original
			preg_match("/(Location:|URI:)[^(\n)]*/", $header, $matches);
			$url_redir = trim(str_replace($matches[1],"",$matches[0]));
			//end changes
			$url_redir_parsed = parse_url($url_redir);
			if (isset($url_redir_parsed)) {
				// No modification on a valud url
				if (isset($url_redir_parsed['scheme']) && isset($url_redir_parsed['host'])) {
					$url = $url_redir;
					$url_array = $url_redir_parsed;
				}
				else {
					// replace the component for redir
					foreach ($url_redir_parsed as $k => $v) {
						$url_array[$k] = $v;
					}
					if (isset($url_array['scheme']))
						$url = $url_array['scheme'];
					else
						$url = 'http';
					$url .= '://';
					if (isset($url_array['user']))
						$url .= $url_array['user'];
					if (isset($url_array['pass']))
						$url .= ':' . $url_array['pass'];
					if (isset($url_array['user']))
						$url .= '@' . $url_array['host'];
					else
						$url .= $url_array['host'];
					if (isset($url_array['port']))
						$url .= ':' . $url_array['port'];
					if (isset($url_array['path']))
						$url .= $url_array['path'];
					if (isset($url_array['query']))
						$url .= '?' . $url_array['query'];
					if (isset($url_array['fragment']))
						$url .= '#' . $url_array['fragment'];
				}
				curl_setopt($ch, CURLOPT_URL, $url);
				$redirects ++;
				return curl_redirect_exec($ch, $url_array, $redirects);
			}
		}
		if ($curlopt_header)
			return $data;
		else {
			list(,$body) = explode("\r\n\r\n", $data, 2);
			return $body;
		}
	}

	function yp_file_get_contents($url, $data_to_post = null,
		$http_header = null, $user_agent = null, $timeout = 30) {

		global $imsUseCurl;

		if (empty($user_agent))
			$user_agent = ini_get('user_agent');

		if (!empty($imsUseCurl)) {
			$curl = curl_init();
			if (!empty($http_header)) {
				curl_setopt($curl, CURLOPT_HTTPHEADER, $http_header);
			}
			curl_setopt ($curl, CURLOPT_USERAGENT, $user_agent);
			curl_setopt ($curl, CURLOPT_TIMEOUT, $timeout);
			curl_setopt ($curl, CURLOPT_SSL_VERIFYPEER, false);
			curl_setopt ($curl, CURLOPT_FOLLOWLOCATION, false);
			if (!empty($data_to_post)) {
				curl_setopt ($curl, CURLOPT_POST, true);
				curl_setopt ($curl, CURLOPT_POSTFIELDS, $data_to_post);
			}
			curl_setopt ($curl, CURLOPT_URL, $url);
			// The first one must be a complete url
			$redirects = 0;
			$html = curl_redirect_exec($curl, parse_url($url), $redirects);
			curl_close ($curl);
			return $html;
		}
		else {
			if (!empty($http_header))
				$header = $http_header;
			else
				$header = array();

			$header[] = 'User-Agent: ' . $user_agent;
			if (!empty($data_to_post)) {
				$header[] = 'Content-type: application/x-www-form-urlencoded';
				$options = array(
					'http' => array(
						'method' => 'POST',
						'header'  => $header,
						'content' => http_build_query($data_to_post)
					)
				);
			}
			else {
				$options = array(
					'http' => array(
						'header'  => $header
					)
				);
			}
			return file_get_contents($url, false, stream_context_create($options));
		}
	}

	// Use to get the content of a local file
	// No need to consider doing POST
	function local_file_get_contents($file) {
		return file_get_contents($file);
	}

	function yp_log10($x) {
		return (($x > 0) ? log10($x) : 0);
	}

	function yp_cmp_strings_length_first($a, $b) {
		$aLen = strlen($a);
		$bLen = strlen($b);

		if ($aLen < $bLen)
			return (-1);

		if ($aLen > $bLen)
			return (1);

		return strcmp($a, $b);
	}

	// This function is obtained from
	// http://www.php.net/manual/en/function.shell-exec.php#52826
	function runExternal($cmd, &$code, $working_dir = '/') {
		$descriptorspec = array(
			0 => array("pipe", "r"),  // stdin is a pipe that the child will read from
			1 => array("pipe", "w"),  // stdout is a pipe that the child will write to
			2 => array("pipe", "w")   // stderr is a file to write to
		);

		$pipes = array();
		$process = proc_open($cmd, $descriptorspec, $pipes, $working_dir);

		$output = "";

		if (!is_resource($process)) return false;

		#close child's input imidiately
		fclose($pipes[0]);

		stream_set_blocking($pipes[1],false);
		stream_set_blocking($pipes[2],false);

		$todo = array($pipes[1],$pipes[2]);

		while( true ) {
			$read = array();
			if( !feof($pipes[1]) ) $read[]= $pipes[1];
			if( !feof($pipes[2]) ) $read[]= $pipes[2];

			if (!$read) break;

			$ready = stream_select($read, $write = NULL, $ex = NULL, 2);

			if ($ready === false) {
				break; #should never happen - something died
			}

			foreach ($read as $r) {
				$s = fread($r, 1024);
				$output .= $s;
			}
		}

		fclose($pipes[1]);
		fclose($pipes[2]);

		$code = proc_close($process);

		return $output;
	}

	function convertUnicodePoints($s) {
		global $supportedUnicodePoints;

		$retStr = $s;
		if ((($numMatches = preg_match_all('/&\w+;/', $retStr, $matches, PREG_SET_ORDER)) === false) ||
			($numMatches == 0))
			return $retStr;

		foreach ($matches as $match) {
			$retStr = str_replace($match[0], $supportedUnicodePoints[$match[0]], $retStr);
		}

		return $retStr;
	}

	function cleanFragments($pregFrag, $s) {
		$retStr = $s;
		if ((($numMatches = preg_match_all($pregFrag, $retStr, $matches, PREG_SET_ORDER)) === false) ||
			($numMatches == 0))
			return $retStr;

		foreach ($matches as $match) {
			$retStr = str_replace($match[0], '', $retStr);
		}

		return $retStr;
	}

	// http://www.weberdev.com/get_example-4291.html
	// --- BEGIN ---
	function baseURL() {
		$s = empty($_SERVER['HTTPS']) ? '' : ($_SERVER['HTTPS'] == 'on') ? 's' : '';
		$protocol = strleft(strtolower($_SERVER['SERVER_PROTOCOL']), '/') . $s;
		$port = ($_SERVER['SERVER_PORT'] == '80') ? '' : (':' . $_SERVER['SERVER_PORT']);
		return $protocol . '://' . $_SERVER['HTTP_HOST'] . $port;
	}

	function selfURL() {
		return (baseURL() . $_SERVER['REQUEST_URI']);
	}

	function strleft($s1, $s2) {
	    return substr($s1, 0, strpos($s1, $s2));
	}
	// --- END ---

	function strrleft($s1, $s2) {
	    return substr($s1, 0, strrpos($s1, $s2));
	}

	function strrright($s1, $s2) {
	    return substr($s1, strrpos($s1, $s2) + strlen($s2));
	}

	function str_between($string, $start, $end) {
		if (($ini = strpos($string, $start)) === false)
			return '';
		$ini += strlen($start);
		$len = ($endExists = strpos($string, $end, $ini)) - $ini;
		if ($endExists === false)
			return substr($string, $ini);
		else
			return substr($string, $ini, $len);
	}

	function wholeURLforTheExecutedFile() {
		return (baseURL() . $_SERVER['SCRIPT_NAME']);
	}

	function myImage($imgName, $imgDir = ''){
		global $imagePrefix;

		// Try the given ($imgName, $imgDir) first, then try ('default', '')
		foreach (array(array($imgName, $imgDir), array('default', '')) as $imgNameDir) {
			$imgName = $imgNameDir[0];
			$imgDir  = $imgNameDir[1];
			// image file
			$testExtensions = array('.jpg', '.gif', '.png');
			foreach ($testExtensions as $ext) {
				if (file_exists('../image/' . $imgDir . $imgName . $ext)) {
					return ($imagePrefix . $imgDir . $imgName . $ext);
				}
			}

			// image url
			$testExtensions = array('.url', '.txt');
			foreach ($testExtensions as $ext) {
				$txtFile = '../image/' . $imgDir . $imgName . $ext;
				if (file_exists($txtFile)) {
					return (trim(local_file_get_contents($txtFile)));
				}
			}
		}

		// Last resort
		return ($imagePrefix . 'not_found.png');
	}

	function myLogo($name){
		return ('<image>' . myImage($name) . '</image>' .
			'<media:thumbnail url="' . myImage($name) .'" />');
	}

	function siteImage($site){
		return (myImage($site, 'site/'));
	}

	function siteLogo($site){
		return ('<image>' . siteImage($site) . '</image>' .
			'<media:thumbnail url="' . siteImage($site) .'" />');
	}

	function extractArguments($statement, $leftDelim = '(', $rightDelim = ')', $sep = '|') {
		$args = explode($sep, str_between($statement, $leftDelim, $rightDelim));
		for ($i = 0 ; $i < count($args) ; $i++) {
			$args[$i] = trim($args[$i]);
		}
		return ($args);
	}

	// http://stackoverflow.com/questions/3422759/php-aes-encrypt-decrypt
	function fnEncrypt($sValue, $sSecretKey) {
		return trim(
			base64_encode(
				mcrypt_encrypt(
					MCRYPT_RIJNDAEL_256,
					$sSecretKey, $sValue,
					MCRYPT_MODE_ECB,
					mcrypt_create_iv(
						mcrypt_get_iv_size(
							MCRYPT_RIJNDAEL_256,
							MCRYPT_MODE_ECB
						),
						MCRYPT_RAND
					)
				)
			)
		);
	}

	// http://stackoverflow.com/questions/3422759/php-aes-encrypt-decrypt
	function fnDecrypt($sValue, $sSecretKey) {
		return trim(
			mcrypt_decrypt(
				MCRYPT_RIJNDAEL_256,
				$sSecretKey,
				base64_decode($sValue),
				MCRYPT_MODE_ECB,
				mcrypt_create_iv(
					mcrypt_get_iv_size(
						MCRYPT_RIJNDAEL_256,
						MCRYPT_MODE_ECB
					),
					MCRYPT_RAND
				)
			)
		);
	}

	// http://zyzzsky.iteye.com/blog/1681188
	function youku_getSid() {
		$sid = time() . (rand(0, 9000) + 10000);
		return $sid;
	}

	function youku_getKey($key1, $key2){
		$a = hexdec($key1);
		$b = $a ^ 0xA55AA5A5;
		$b = dechex($b);
		return $key2 . $b;
	}

	function youku_getFileID($fileId, $seed) {
		$mixed = youku_getMixString($seed);
		$ids = explode('*', $fileId);
		unset($ids[count($ids)-1]);
		$realId = '';
		$realId_part1 = '';
		$realId_part2 = '';
		$realId_part3 = '';
		for ($i = 0 ; $i < count($ids) ; ++ $i) {
			$idx = $ids[$i];
			$char_to_append = substr($mixed, $idx, 1);
			$realId .= $char_to_append;
			if ($i < 8)
				$realId_part1 .= $char_to_append;
			else if ($i < 10)
				$realId_part2 .= $char_to_append;
			else
				$realId_part3 .= $char_to_append;
		}
		return array($realId, $realId_part1, $realId_part2, $realId_part3);
	}

	function youku_getMixString($seed) {
		$mixed = '';
		$source = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ/\\:._-1234567890";
		$len = strlen($source);
		for($i = 0 ; $i < $len ; ++ $i){
			$seed = ($seed * 211 + 30031) % 65536;
			$index = ($seed / 65536 * strlen($source));
			$c = substr($source, $index, 1);
			$mixed .= $c;
			$source = str_replace($c, '', $source);
		}
		return $mixed;
	}

	// http://www.dzone.com/snippets/get-remote-ip-address-php
	function getRemoteIPAddress() {
		$ip = isset($_SERVER['REMOTE_ADDR']) ? $_SERVER['REMOTE_ADDR'] : '';
		return $ip;
	}
	/* If your visitor comes from proxy server you have use another function to get a real IP address: */
	function getRealIPAddress() {
		if (!empty($_SERVER['HTTP_CLIENT_IP'])) {
			// Check ip from share internet
			$ip = $_SERVER['HTTP_CLIENT_IP'];
		}
		else if (!empty($_SERVER['HTTP_X_FORWARDED_FOR'])) {
			// Check ip passed from proxy
			$ip = $_SERVER['HTTP_X_FORWARDED_FOR'];
		}
		else {
			$ip = $_SERVER['REMOTE_ADDR'];
		}
		return $ip;
	}

	function booleanValuefromString($s) {
		// true if not '0' or 'false'
		return ((strcmp($s, '0') != 0) && (strcasecmp($s, 'false') != 0));
	}
?>
