<?php
	// Functions

	function notification_email_text($subject, $body) {
		global $imsUseEmail, $imsBotEmail, $imsAdminEmail;

		if (!empty($imsUseEmail)) {
			$to = $imsAdminEmail;
			$headers = "From: $imsBotEmail";
			return mail($to, $subject, $body, $headers);
		}
		else {
			return false;
		}
	}

	function yp_file_get_contents($url, $timeout = 30, $referer = '', $user_agent = ''){
		global $imsUseCurl;

		if (!empty($imsUseCurl)) {
			$curl = curl_init();
			if(strstr($referer, '://')) {
				curl_setopt ($curl, CURLOPT_REFERER, $referer);
			}
			curl_setopt ($curl, CURLOPT_URL, $url);
			curl_setopt ($curl, CURLOPT_TIMEOUT, $timeout);
			if (strlen($user_agent) == 0) {
				$user_agent = ini_get('user_agent');
			}
			curl_setopt ($curl, CURLOPT_USERAGENT, $user_agent);
			curl_setopt ($curl, CURLOPT_RETURNTRANSFER, 1);
			curl_setopt ($curl, CURLOPT_SSL_VERIFYPEER, 0);
			$html = curl_exec ($curl);
			curl_close ($curl);
			return $html;
		}
		else {
			return file_get_contents($url);
		}
	}

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

	// http://www.weberdev.com/get_example-4291.html
	// --- BEGIN ---
	function selfURL() {
		$s = empty($_SERVER['HTTPS']) ? '' : ($_SERVER['HTTPS'] == 'on') ? 's' : '';
		$protocol = strleft(strtolower($_SERVER['SERVER_PROTOCOL']), '/') . $s;
		$port = ($_SERVER['SERVER_PORT'] == '80') ? '' : (':' . $_SERVER['SERVER_PORT']);
		return $protocol . '://' . $_SERVER['SERVER_NAME'] . $port . $_SERVER['REQUEST_URI'];
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
		$string = ' ' . $string;
		$ini = strpos($string, $start);
		if ($ini == 0)
			return '';
		$ini += strlen($start);
		$len = strpos($string, $end, $ini) - $ini;
		return substr($string, $ini, $len);
	}

	function wholeURLforTheExecutedFile() {
		$s = empty($_SERVER['HTTPS']) ? '' : ($_SERVER['HTTPS'] == 'on') ? 's' : '';
		$protocol = strleft(strtolower($_SERVER['SERVER_PROTOCOL']), '/') . $s;
		$port = ($_SERVER['SERVER_PORT'] == '80') ? '' : (':' . $_SERVER['SERVER_PORT']);
		return $protocol . '://' . $_SERVER['SERVER_NAME'] . $port . $_SERVER['SCRIPT_NAME'];
	}

	function myImage($imgName, $imgDir = ''){
		global $imagePrefix;

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

		return ($imagePrefix . 'default.jpg');
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
?>
