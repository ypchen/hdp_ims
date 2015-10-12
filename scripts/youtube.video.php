<?php
	// Partial unicode points
	// http://www.htmlcodetutorial.com/characterentities_famsupp_69.html
	// http://www.w3.org/TR/REC-html40/sgml/entities.html
	// '--- BEGIN ---
	$supportedUnicodePoints = array(
		'&quot;' => '"', '&amp;' => '&', '&nbsp;' => ' ', '&cent;' => '¢',
		'&pound;' => '£', '&yen;' => '¥', '&brvbar;' => '¦', '&copy;' => '©',
		'&laquo;' => '«', '&not;' => '¬', '&shy;' => '­', '&reg;' => '®',
		'&macr;' => '¯', '&deg;' => '°', '&plusmn;' => '±', '&sup2;' => '²',
		'&sup3;' => '³', '&acute;' => '´', '&micro;' => 'µ', '&para;' => '¶',
		'&middot;' => '·', '&sup1;' => '¹', '&ordm;' => 'º', '&raquo;' => '»',
		'&frac14;' => '¼', '&frac12;' => '½', '&frac34;' => '¾', '&iquest;' => '¿',
		'&fnof;' => 'ƒ', '&circ;' => 'ˆ', '&tilde;' => '˜', '&Alpha;' => 'Α',
		'&Beta;' => 'Β', '&Gamma;' => 'Γ', '&Delta;' => 'Δ', '&Epsilon;' => 'Ε',
		'&Zeta;' => 'Ζ', '&Eta;' => 'Η', '&Theta;' => 'Θ', '&Iota;' => 'Ι',
		'&Kappa;' => 'Κ', '&Lambda;' => 'Λ', '&Mu;' => 'Μ', '&Nu;' => 'Ν',
		'&Xi;' => 'Ξ', '&Omicron;' => 'Ο', '&Pi;' => 'Π', '&Rho;' => 'Ρ',
		'&Sigma;' => 'Σ', '&Tau;' => 'Τ', '&Upsilon;' => 'Υ', '&Phi;' => 'Φ',
		'&Chi;' => 'Χ', '&Psi;' => 'Ψ', '&Omega;' => 'Ω', '&alpha;' => 'α',
		'&beta;' => 'β', '&gamma;' => 'γ', '&delta;' => 'δ', '&epsilon;' => 'ε',
		'&zeta;' => 'ζ', '&eta;' => 'η', '&theta;' => 'θ', '&iota;' => 'ι',
		'&kappa;' => 'κ', '&lambda;' => 'λ', '&mu;' => 'μ', '&nu;' => 'ν',
		'&xi;' => 'ξ', '&omicron;' => 'ο', '&pi;' => 'π', '&rho;' => 'ρ',
		'&sigmaf;' => 'ς', '&sigma;' => 'σ', '&tau;' => 'τ', '&upsilon;' => 'υ',
		'&phi;' => 'φ', '&chi;' => 'χ', '&psi;' => 'ψ', '&omega;' => 'ω',
		'&thetasym;' => 'ϑ', '&upsih;' => 'ϒ', '&piv;' => 'ϖ', '&ndash;' => '–',
		'&mdash;' => '—', '&lsquo;' => '‘', '&rsquo;' => '’', '&sbquo;' => '‚',
		'&ldquo;' => '“', '&rdquo;' => '”', '&bdquo;' => '„', '&dagger;' => '†',
		'&Dagger;' => '‡', '&bull;' => '•', '&hellip;' => '…', '&permil;' => '‰',
		'&prime;' => '′', '&Prime;' => '″', '&lsaquo;' => '‹', '&rsaquo;' => '›',
		'&oline;' => '‾', '&frasl;' => '⁄', '&euro;' => '€', '&trade;' => '™',
		'&larr;' => '←', '&uarr;' => '↑', '&rarr;' => '→', '&darr;' => '↓',
		'&harr;' => '↔', '&crarr;' => '↵', '&lArr;' => '⇐', '&uArr;' => '⇑',
		'&rArr;' => '⇒', '&dArr;' => '⇓', '&hArr;' => '⇔', '&forall;' => '∀',
		'&part;' => '∂', '&exist;' => '∃', '&empty;' => '∅', '&nabla;' => '∇',
		'&isin;' => '∈', '&notin;' => '∉', '&ni;' => '∋', '&prod;' => '∏',
		'&sum;' => '∑', '&minus;' => '−', '&lowast;' => '∗', '&radic;' => '√',
		'&prop;' => '∝', '&infin;' => '∞', '&ang;' => '∠', '&and;' => '∧',
		'&or;' => '∨', '&cap;' => '∩', '&cup;' => '∪', '&int;' => '∫',
		'&there4;' => '∴', '&sim;' => '∼', '&cong;' => '≅', '&asymp;' => '≈',
		'&ne;' => '≠', '&equiv;' => '≡', '&le;' => '≤', '&ge;' => '≥',
		'&sub;' => '⊂', '&sup;' => '⊃', '&nsub;' => '⊄', '&sube;' => '⊆',
		'&supe;' => '⊇', '&oplus;' => '⊕', '&otimes;' => '⊗', '&perp;' => '⊥',
		'&sdot;' => '⋅', '&lceil;' => '⌈', '&rceil;' => '⌉', '&lfloor;' => '⌊',
		'&rfloor;' => '⌋', '&lang;' => '〈', '&rang;' => '〉', '&loz;' => '◊',
		'&spades;' => '♠', '&clubs;' => '♣', '&hearts;' => '♥', '&diams;' => '♦'
	);
	// '--- END ---

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

	$evalLevel = 0;

// <md5sum>HERE: md5sum of the following lines except for the last line without php tags</md5sum>
// ---------- youtube.video.php: BEGIN ----------

	// Surpress warnings
	error_reporting( E_ERROR | E_PARSE | E_CORE_ERROR | E_CORE_WARNING | E_COMPILE_ERROR | E_COMPILE_WARNING );

	// Check if need to use curl for retrieving remote data
	$USEcurl = false;
	if (!empty($_GET['USEcurl']))
		$USEcurl = true;

	$yp_http_response_header = null;

	$fileStep      = '/tmp/yv_url_redir.step';
	$fileCallback  = '/tmp/yv_url_redir.callback';
	$fileExtraOpt  = '/tmp/yv_url_redir.extraOpt';
	$fileDataURL   = '/tmp/yv_url.data';
	$fileDataRedir = '/usr/local/etc/dvdplayer/ims_yv_url_redir.dat';

	// Check the existence of all the function definitions because this part of code may be re-loaded and re-evaluated

	if (function_exists('yp_str_between_2_1') === false) {
		function yp_str_between_2_1($string, $start, $end) {
			if (($ini = strpos($string, $start)) === false)
				return '';
			$ini += strlen($start);
			$len = ($endExists = strpos($string, $end, $ini)) - $ini;
			if ($endExists === false)
				return substr($string, $ini);
			else
				return substr($string, $ini, $len);
		}
	}

	if (function_exists('curl_redirect_exec_3_1') === false) {
		// http://www.php.net/manual/en/function.curl-setopt.php#95027
		// http://stackoverflow.com/questions/3890631/php-curl-with-curlopt-followlocation-error
		function curl_redirect_exec_3_1($ch, $url_array, &$redirects, $curlopt_header = false) {
			$retryMax = 5;
			$retryDelay = 1;
			curl_setopt($ch, CURLOPT_HEADER, true);
			curl_setopt($ch, CURLOPT_RETURNTRANSFER, true);
			for ($retry = 0 ; $retry < $retryMax ; $retry ++) {
				if (($data = curl_exec($ch)) !== false) break;
				sleep($retryDelay);
				simpleFileWrite_2_4_1('/tmp/yv.error.curl.' . strval($retry),
					'[' . ($curlErrCode = curl_errno($ch)) . ']: ' . curl_error($ch));
			}
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
					curl_setopt($ch, CURLOPT_URL, $url);
					$redirects ++;
					return curl_redirect_exec_3_1($ch, $url_array, $redirects);
				}
			}
			if ($curlopt_header)
				return $data;
			else {
				list(,$body) = explode("\r\n\r\n", $data, 2);
				return $body;
			}
		}
	}

	if (function_exists('yp_file_get_contents_3') === false) {
		function yp_file_get_contents_3($url, $http_header = null, $method = 'GET', $requestBody = null, $user_agent = null, $timeout = 30) {

			global $USEcurl;
			global $yp_http_response_header;

			if (empty($user_agent))
				$user_agent = ini_get('user_agent');

			if (!empty($USEcurl)) {
				// curl part is not tested
				$curl = curl_init();
				if (!empty($http_header)) {
					curl_setopt($curl, CURLOPT_HTTPHEADER, $http_header);
				}
				curl_setopt ($curl, CURLOPT_USERAGENT, $user_agent);
				curl_setopt ($curl, CURLOPT_TIMEOUT, $timeout);
				curl_setopt ($curl, CURLOPT_SSL_VERIFYPEER, false);
				curl_setopt ($curl, CURLOPT_FOLLOWLOCATION, false);
				switch ($method) {
					case 'POST':
						curl_setopt ($curl, CURLOPT_POST, true);
						curl_setopt ($curl, CURLOPT_POSTFIELDS, $requestBody);
						break;
					case 'PUT':
						curl_setopt ($curl, CURLOPT_CUSTOMREQUEST, 'PUT');
						curl_setopt ($curl, CURLOPT_POSTFIELDS, $requestBody);
						break;
					case 'DELETE':
						curl_setopt ($curl, CURLOPT_CUSTOMREQUEST, 'DELETE');
						break;
					default:
						break;
				}
				curl_setopt ($curl, CURLOPT_URL, $url);
				// The first one must be a complete url
				$redirects = 0;
				list($response_header, $html) = curl_redirect_exec_3_1($curl, parse_url($url), $redirects, true);
				$yp_http_response_header = explode("\r\n", $response_header);
				curl_close ($curl);
				return $html;
			}
			else {
				if (!empty($http_header))
					$header = $http_header;
				else
					$header = array();

				$header[] = 'User-Agent: ' . $user_agent;
				$options = array(
					'http' => array(
						'method'  => $method,
						'header'  => $header
					),
					'ssl' => array(
						'verify_peer' => false,
						'allow_self_signed' => true
					)
				);
				if (!empty($requestBody))
					$options['http']['content'] = $requestBody;
				$html = file_get_contents($url, false, stream_context_create($options));
				$yp_http_response_header = $http_response_header;
				return $html;
			}
		}
	}

	if (function_exists('local_file_get_contents') === false) {
		function local_file_get_contents($file) {
			return file_get_contents($file);
		}
	}

	if (function_exists('yp_str_until_close_2_3') === false) {
		// Different from str_between(), will return the (sub-)string from $startPos
		function yp_str_until_close_2_3($src, $startPos, $charOpen, $charClose) {
			$retStr = '';
			$pos = $startPos;
			$openCount = 0;
			// Copy until OPEN
			while($src[$pos] != $charOpen) {
				$retStr .= $src[$pos ++];
			}
			// OPEN
			$openCount ++;
			$retStr .= $src[$pos ++];
			// Copy until CLOSE
			while($openCount > 0) {
				if ($src[$pos] == $charOpen)
					$openCount ++;
				if ($src[$pos] == $charClose)
					$openCount --;
				$retStr .= $src[$pos ++];
			}
			return $retStr;
		}
	}

	if (function_exists('extrJSCodeID_2_3') === false) {
		function extrJSCodeID_2_3($js, $id) {
			if (($codePos = strpos($js, $codeID = 'function ' . $id . '(')) === false) {
				if (($codePos = strpos($js, $codeID = 'var ' . $id . '=')) === false) {
					return "// Unknown identifier: [$id]\n";
				}
			}
			$code = trim(yp_str_until_close_2_3($js, $codePos, '{', '}'));
			return $code . ";\n";
		}
	}

	if (function_exists('simpleFileWrite_2_4_1') === false) {
		function simpleFileWrite_2_4_1($filePathName, $contentToWrite) {
			$fileToWrite = fopen($filePathName, 'w');
			fwrite($fileToWrite, $contentToWrite);
			fclose($fileToWrite);
		}
	}

	if (function_exists('writeExtraInfo_2_4_1') === false) {
		function writeExtraInfo_2_4_1($extraInfo) {
			simpleFileWrite_2_4_1('/usr/local/etc/dvdplayer/ims_extra_info.dat', $extraInfo);
		}
	}

	if (function_exists('youtube_api_device_oauth2_3') === false) {
		function youtube_api_device_oauth2_3($apiData) {

			global $yp_http_response_header;

			if (empty($apiData['device_code'][0])) {
				$apiRetVal = yp_file_get_contents_3(($apiURL = 'https://accounts.google.com/o/oauth2/device/code'),
					($apiHeader = array('Content-Type: application/x-www-form-urlencoded')), ($method = 'POST'),
					($requestBody = http_build_query(array(
					'client_id' => $apiData['client_id'][0],
					'scope' => 'https://www.googleapis.com/auth/youtube'))));
			}
			else {
				$apiRetVal = yp_file_get_contents_3(($apiURL = 'https://accounts.google.com/o/oauth2/token'),
					($apiHeader = array('Content-Type: application/x-www-form-urlencoded')), ($method = 'POST'),
					($requestBody = http_build_query(array(
					'client_id'		=> $apiData['client_id'][0],
					'client_secret'	=> $apiData['client_secret'][0],
					'code'			=> $apiData['device_code'][0],
					'grant_type'	=> 'http://oauth.net/grant_type/device/1.0'))));
			}
			return $apiRetVal;
		}
	}

	if (function_exists('youtube_api_3') === false) {
		function youtube_api_3($apiData, $cmd, $method = 'GET', $requestHeader = array(), $requestBody = null) {

			global $yp_http_response_header;

			$apiURL    = 'https://www.googleapis.com/youtube/v3/' . $cmd;
			$apiHeader = array_merge($requestHeader, array('Authorization: Bearer ' . $apiData['access_token'][0]));
			$apiRetVal = yp_file_get_contents_3($apiURL, $apiHeader, $method, $requestBody);
			$httpStatusInfo = explode(' ', $yp_http_response_header[0]);
			$httpStatus = intval($httpStatusInfo[1]);
			if ($httpStatus == 401) {
				// Refresh the access token
				$apiRetVal = yp_file_get_contents_3('https://accounts.google.com/o/oauth2/token',
					array('Content-Type: application/x-www-form-urlencoded'), 'POST',
					http_build_query(array(
					'client_id' => $apiData['client_id'][0],
					'client_secret' => $apiData['client_secret'][0],
					'refresh_token' => $apiData['refresh_token'][0],
					'grant_type' => 'refresh_token')));
				$httpStatusInfo = explode(' ', $yp_http_response_header[0]);
				$httpStatus = intval($httpStatusInfo[1]);
				if ($httpStatus == 200) {
					$apiDecoded = json_decode($apiRetVal, true);
					$newAccessToken = $apiDecoded['access_token'];
					simpleFileWrite_2_4_1($apiData['access_token'][1], $newAccessToken);
					$apiHeader = array_merge($requestHeader, array('Authorization: Bearer ' . $newAccessToken));
					$apiRetVal = yp_file_get_contents_3($apiURL, $apiHeader, $method, $requestBody);
				}
			}
			return $apiRetVal;
		}
	}

	if (function_exists('yvJSONtoXML_3') === false) {
		function yvJSONtoXML_3($item, $partNames) {
			$xmlReturn = '';
			foreach ($partNames as $partName => $partItems) {
				if (!empty($item[$partName])) {
					$xmlReturn .= '<' . $partName . '>';
					foreach ($partItems as $partItem) {
						if (!empty($item[$partName][$partItem])) {
							$xmlReturn .=
								('<' . $partItem . '>' .
									str_replace('&', '&amp;', $item[$partName][$partItem]) .
								'</' . $partItem . ">\r\n");
						}
					}
					$xmlReturn .= '</' . $partName . ">\r\n";
				}
			}
			return $xmlReturn;
		}
	}

	if (function_exists('yvJSONtoXML_all_3') === false) {
		function yvJSONtoXML_all_3($item, $partNames) {
			$xmlReturn = '';
			foreach ($partNames as $partName) {
				if (!empty($item[$partName])) {
					$xmlReturn .= '<' . $partName . '>';
					foreach ($item[$partName] as $partItem => $partItemValue) {
						$xmlReturn .=
							('<' . $partItem . '>' .
								str_replace('&', '&amp;', $item[$partName][$partItem]) .
							'</' . $partItem . ">\r\n");
					}
					$xmlReturn .= '</' . $partName . ">\r\n";
				}
			}
			return $xmlReturn;
		}
	}

	if (function_exists('getallheaders') === false) {
		// http://php.net/manual/en/function.getallheaders.php
		function getallheaders() {
			$headers = '';
			foreach ($_SERVER as $name => $value)
				if (substr($name, 0, 5) == 'HTTP_')
					$headers[str_replace(' ', '-', ucwords(strtolower(str_replace('_', ' ', substr($name, 5)))))] = $value;
			return $headers;
		}
	}

	if (function_exists('setupCallBack_3_1') === false) {
		function setupCallBack_3_1($filePathName) {
			$urlCallback = "http://$_SERVER[HTTP_HOST]$_SERVER[PHP_SELF]?query=yv_url_redir";
			if (!empty($_GET['yv_rmt_src']))
				$urlCallback .= ('&yv_rmt_src=' . urlencode($_GET['yv_rmt_src']));
			simpleFileWrite_2_4_1($filePathName, $urlCallback);
			return $urlCallback;
		}
	}

	if (function_exists('yp_str_between_rev_3_1') === false) {
		function yp_str_between_rev_3_1($string, $end, $start) {
			if (($ini = strpos($string, $end)) === false)
				return '';
			$lenStart = strlen($start);
			$len = ($ini - ($startExists = strrpos($string, $start, $ini-strlen($string)))) - $lenStart;
			if ($startExists === false)
				return substr($string, $ini);
			else
				return substr($string, $startExists+$lenStart, $len);
		}
	}

	// If there is no 'query', respond to the request of youtube.video.php
	if (($evalLevel == 0) && empty($_GET['query'])) {
		// Check if memcache is used
		$useMemcache = false;
		if (($envVar = @getenv('IMS_USE_MEMCACHE')) !== false) {
			$useMemcache = ((strcmp($envVar, '0') != 0) && (strcasecmp($envVar, 'false') != 0));
		}

		if ($useMemcache) {
			include('../common/PHPMemcacheSASL/MemcacheSASL.php');
			$mc = new MemcacheSASL;
			$mc->addServer(@getenv('IMS_MEMCACHE_HOST'), @getenv('IMS_MEMCACHE_PORT'));
			$mc->setSaslAuthData(@getenv('IMS_MEMCACHE_USER'), @getenv('IMS_MEMCACHE_PASS'));
		}

		$mcKey = __FILE__;
		if (($useMemcache ===  false) || (($meToSend = $mc->get($mcKey)) === false)) {
			// Read myself and get the body to send
			$meToSendBody = yp_str_between_2_1(local_file_get_contents(__FILE__),
							"// ---------- youtube.video.php: BEGIN ----------\r\n",
							"// ---------- youtube.video.php: END ----------\r\n");
			$meToSend = '// <md5sum>' .
							md5($meToSendBody) .
							"</md5sum>\n" .
							"// ---------- youtube.video.php: BEGIN ----------\r\n" .
							$meToSendBody .
							"// ---------- youtube.video.php: END ----------\r\n";
			if ($useMemcache) {
				// Write to memcache
				// Expiration time is set to 6 hours
				$mc->add($mcKey, $meToSend, 6*60*60);
			}
		}
		echo $meToSend;
		return;
	}

	// If there is 'query' and 'yv_rmt_src', request youtube.video.php if yv_rmt_src is given
	if (($evalLevel == 0) && (!empty($_GET['yv_rmt_src']))) {
		$rmtSrcURL = $_GET['yv_rmt_src'];
		// Check if it's really "remote"
		if ((strpos($rmtSrcURL, '://localhost') === false) &&
			(strpos($rmtSrcURL, '://127.0.0.1') === false)) {
			// 1. a local copy in /tmp exists
			// 2. from the remote source
			$fileTmpRmtSrc = '/tmp/yv.rmt.src';
			$gotViaHTTP    = false;
			$rmtSrc        = null;
			$minCheckLen   = 52;
			if (((file_exists($fileTmpRmtSrc) &&
				(strlen($rmtSrc = local_file_get_contents($fileTmpRmtSrc)) > $minCheckLen)))
				||
				((strlen($rmtSrc = yp_file_get_contents_3($rmtSrcURL)) > $minCheckLen) &&
				($gotViaHTTP = true))) {
				$md5sum = yp_str_between_2_1($rmtSrc, '<md5sum>', '</md5sum>');
				$receivedCode = yp_str_between_2_1($rmtSrc,
								"// ---------- youtube.video.php: BEGIN ----------\r\n",
								"// ---------- youtube.video.php: END ----------\r\n");
				// Run the download source if the md5sum is correct
				if (strcmp($md5sum, md5($receivedCode)) == 0) {
					if ($gotViaHTTP === true)
						simpleFileWrite_2_4_1($fileTmpRmtSrc, $rmtSrc);
					$evalLevel ++;
					eval($receivedCode);
					return;
				}
			}
		}
	}

	// Main functionality begins here

	// Chrome 14.0.825.0
	// http://www.useragentstring.com/pages/Chrome/
	$userAgent = 'Mozilla/5.0 (X11; Linux i686) AppleWebKit/535.1 (KHTML, like Gecko) Ubuntu/11.04 Chromium/14.0.825.0 Chrome/14.0.825.0 Safari/535.1';
	ini_set('user_agent', $userAgent);

	// No matter it's the local source or remote source, 'query' is given.
	$id = $_GET['query'];

	// Check if only URL is wanted
	$URLonly = false;
	if (!empty($_GET['URLonly']))
		$URLonly = true;

	// User preferred formats
	// http://en.wikipedia.org/wiki/YouTube
	// The following itags are currently supported by 1073:
	//		37(X),22(O),35(X),18(O),34(X),6(X),5(O)
	//		X means discontinued by YouTube
	// These itags are also used for specifying the resolution preference for other sites, such as dailymotion.

	// Default: 22,35,18,34,6,5
	$fmtPrefs = '22,35,18,34,6,5';

	// If fmt_prefs is given in the url, use it
	if (!empty($_GET['fmt_prefs'])) {
		$fmtPrefs = $_GET['fmt_prefs'];
	}

	// If the local file exists and contains a string whose length > 0, use it
	$fileLocalVideoFmtPrefs = '/usr/local/etc/dvdplayer/ims_fmt_prefs.dat';
	if (file_exists($fileLocalVideoFmtPrefs) &&
		(strlen($localFmtPrefs = trim(local_file_get_contents($fileLocalVideoFmtPrefs))) > 0)) {
		$fmtPrefs = $localFmtPrefs;
	}

	// Explode the string to get the format preference
	$formats = explode(',', $fmtPrefs);

	// Default: <EMPTY>
	$ccPrefs = '';

	// If cc_prefs is given in the url, use it
	if (!empty($_GET['cc_prefs'])) {
		$ccPrefs = $_GET['cc_prefs'];
	}

	// If the local file exists and contains a string whose length > 0, use it
	$fileLocalVideoCCPrefs = '/usr/local/etc/dvdplayer/ims_cc_prefs.dat';
	if (file_exists($fileLocalVideoCCPrefs) &&
		(strlen($localCCPrefs = trim(local_file_get_contents($fileLocalVideoCCPrefs))) > 0)) {
		$ccPrefs = $localCCPrefs;
	}

	if (!empty($ccPrefs) && (strlen($ccPrefs) > 0))
		$ccPreferredLangs = explode(',', $ccPrefs);
	else
		unset($ccPreferredLangs);

	$videoUnavailable = false;
	$msgUnavailable = '';
	$videoColorBars = array('eSw6mfuLiFo', 'lTzgMwi_SZ8');
	$posColorBars = 0;

	if (strcmp($id, 'yv_api') == 0) {
		$docUrl       = 'http://hdp-ims.neocities.org';
		$docUrlS      = 'http://qr.net/Rwwd';
		$qrGenUrl     = 'http://api.qrserver.com/v1/create-qr-code/?size=300x300&data=';
		$dataFilePath = '/usr/local/etc/dvdplayer/';
		// YouTube Data API (for accessing account)
		$apiData = array(
			'client_id'		=> array('', $dataFilePath . 'ims_yv_api_client_id.dat'),
			'client_secret'	=> array('', $dataFilePath . 'ims_yv_api_client_secret.dat'),
			'device_code'	=> array('', $dataFilePath . 'ims_yv_oa_code_device.dat'),
			'refresh_token'	=> array('', $dataFilePath . 'ims_yv_oa_token_refresh.dat'),
			'access_token'	=> array('', $dataFilePath . 'ims_yv_oa_token_access.dat'),
		);
		$apiDataReady = true;
		foreach ($apiData as $apiK => $apiV) {
			$fileLocal = $apiV[1];
			if (file_exists($fileLocal) &&
				(strlen($localData = trim(local_file_get_contents($fileLocal))) > 0)) {
				$apiData[$apiK][0] = $localData;
			}
			else {
				$apiDataReady = false;
				break;
			}
		}
		if ($apiDataReady !== true) {
			if ((empty($apiData['client_id'][0])) || (empty($apiData['client_secret'][0]))) {
				$xmlReturn = '<root><code>400</code><msgSpecial>API 使用憑證尚未設定 -- 說明: ' . $docUrlS . '</msgSpecial><imgSpecial>' . htmlentities($qrGenUrl . urlencode($docUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
				echo $xmlReturn;
				return;
			}
			else if (empty($apiData['device_code'][0])) {
				$apiRetVal = youtube_api_device_oauth2_3($apiData);
				$httpStatusInfo = explode(' ', $yp_http_response_header[0]);
				$httpStatus = intval($httpStatusInfo[1]);
				if ($httpStatus == 200) {
					$apiDecoded      = json_decode($apiRetVal, true);
					$deviceCode      = $apiDecoded['device_code'];
					$userCode        = $apiDecoded['user_code'];
					$verificationUrl = $apiDecoded['verification_url'];
					simpleFileWrite_2_4_1($apiData['device_code'][1], $deviceCode);
					simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_oa_code_user.dat', $userCode);
					simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_oa_url_verification.dat', $verificationUrl);
					$xmlReturn = '<root><code>801</code>' .
						'<msgSpecial>請至 ' . htmlentities($verificationUrl, ENT_QUOTES) . ' 授權</msgSpecial>' .
						'<msgSpecialNote>裝置啟用碼: ' . htmlentities($userCode, ENT_QUOTES) . '</msgSpecialNote>' .
						'<imgSpecial>' . htmlentities($qrGenUrl . urlencode($verificationUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
				}
				else {
					$xmlReturn = '<root><code>' . $httpStatus . '</code><msgSpecial>叫用 API 錯誤，未取得 device_code</msgSpecial><imgSpecial>' . htmlentities($qrGenUrl . urlencode($docUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
				}
				echo $xmlReturn;
				return;
			}
			else {
				$apiRetVal = youtube_api_device_oauth2_3($apiData);
				$httpStatusInfo = explode(' ', $yp_http_response_header[0]);
				$httpStatus = intval($httpStatusInfo[1]);
				if ($httpStatus == 200) {
					$apiDecoded      = json_decode($apiRetVal, true);
					if (!empty($apiDecoded['error'])) {
						$userCode        = trim(local_file_get_contents($dataFilePath . 'ims_yv_oa_code_user.dat'));
						$verificationUrl = trim(local_file_get_contents($dataFilePath . 'ims_yv_oa_url_verification.dat'));
						$xmlReturn = '<root><code>802</code>' .
							'<msgSpecial>請至 ' . htmlentities($verificationUrl, ENT_QUOTES) . ' 授權</msgSpecial>' .
							'<msgSpecialNote>裝置啟用碼: ' . htmlentities($userCode, ENT_QUOTES) . '</msgSpecialNote>' .
							'<imgSpecial>' . htmlentities($qrGenUrl . urlencode($verificationUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
						echo $xmlReturn;
						return;
					}
					else if ((empty($apiDecoded['access_token'])) || (empty($apiDecoded['refresh_token']))) {
						$xmlReturn = '<root><code>803</code><msgSpecial>叫用 API 錯誤，未取得 access_token</msgSpecial><imgSpecial>' . htmlentities($qrGenUrl . urlencode($docUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
						echo $xmlReturn;
						return;
					}
					else {
						$accessToken  = $apiDecoded['access_token'];
						$refreshToken = $apiDecoded['refresh_token'];
						simpleFileWrite_2_4_1($apiData['access_token'][1], $accessToken);
						simpleFileWrite_2_4_1($apiData['refresh_token'][1], $refreshToken);
						$xmlReturn = '<root><code>800</code><msgSpecial>授權設定完成，請返回上層選單後重新進入</msgSpecial></root>' . "\r\n";
						echo $xmlReturn;
						return;
					}
				}
				else {
					$xmlReturn = '<root><code>' . $httpStatus . '</code><msgSpecial>叫用 API 錯誤，未取得 access_token</msgSpecial><imgSpecial>' . htmlentities($qrGenUrl . urlencode($docUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
					echo $xmlReturn;
					return;
				}
			}
		}

		$cmd = $_GET['cmd'];
		if (!empty($_GET['post']))
			$apiRetVal = youtube_api_3($apiData, $cmd, 'POST', array('Content-Type: application/json; charset=UTF-8'), $_GET['post']);
		else if (!empty($_GET['put']))
			$apiRetVal = youtube_api_3($apiData, $cmd, 'PUT', array('Content-Type: application/json; charset=UTF-8'), $_GET['put']);
		else if (!empty($_GET['delete']))
			$apiRetVal = youtube_api_3($apiData, $cmd, 'DELETE');
		else
			$apiRetVal = youtube_api_3($apiData, $cmd);
		$httpStatusInfo = explode(' ', $yp_http_response_header[0]);
		$httpStatus = intval($httpStatusInfo[1]);
		if ($httpStatus != 200) {
			$xmlReturn = '<root><code>' . strval($httpStatus) . '</code><msgSpecial>設定有誤，請依說明設定 -- ' . $docUrlS . '</msgSpecial><imgSpecial>' . htmlentities($qrGenUrl . urlencode($docUrl), ENT_QUOTES) . '</imgSpecial></root>' . "\r\n";
			echo $xmlReturn;
			return;
		}

		$apiDecoded = json_decode($apiRetVal, true);
		if ((empty($_GET['type'])) || (strcmp(($type = $_GET['type']), 'mine') != 0))
			$checkKind = $apiDecoded['kind'];
		else
			$checkKind = 'youtube#searchListResponse';
		switch ($checkKind) {
			case 'youtube#searchListResponse':
			case 'youtube#playlistItemListResponse':
				if (!empty($_GET['page'])) {
					$pageCurr = intval($_GET['page']);
					if (!empty($apiDecoded['nextPageToken'])) {
						simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.pageToken.' . strval($pageCurr+1), '&pageToken=' . $apiDecoded['nextPageToken']);
						simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.hasNextPage', '1');
					}
					else {
						simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.hasNextPage', '0');
					}
					if (!empty($apiDecoded['prevPageToken'])) {
						simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.pageToken.' . strval($pageCurr-1), '&pageToken=' . $apiDecoded['prevPageToken']);
						simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.hasPrevPage', '1');
					}
					else {
						simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.hasPrevPage', '0');
					}
				}

				// Write the local file directly
				$dataFileIds		= $dataFilePath . 'ims_yv_api.ids';
				$dataFileKinds		= $dataFilePath . 'ims_yv_api.kinds';
				$dataFileTitles		= $dataFilePath . 'ims_yv_api.titles';
				$dataFileImages		= $dataFilePath . 'ims_yv_api.images';
				$dataFilePubTime	= $dataFilePath . 'ims_yv_api.pubtime';
				$dataFilePLIds		= $dataFilePath . 'ims_yv_api.pl_ids';
				$dataFilePLPos		= $dataFilePath . 'ims_yv_api.pl_pos';
				$fileIds			= fopen($dataFileIds, 'w');
				$fileKinds			= fopen($dataFileKinds, 'w');
				$fileTitles			= fopen($dataFileTitles, 'w');
				$fileImages			= fopen($dataFileImages, 'w');
				$filePubTime		= fopen($dataFilePubTime, 'w');
				$filePLIds			= fopen($dataFilePLIds, 'w');
				$filePLPos			= fopen($dataFilePLPos, 'w');

				$itemCount = 0;
				foreach ($apiDecoded['items'] as $item) {
					$itemCount ++;
					$snippet = $item['snippet'];
					if (!empty($snippet['resourceId'])) {
						$idInfo = $snippet['resourceId'];
						if (is_string($item['id'])) {
							// Save (probable) playlistItem info
							fwrite($filePLIds, $item['id'] . "\n");
							fwrite($filePLPos, $snippet['position'] . "\n");
						}
					}
					else {
						if (is_array($item['id']))
							$idInfo = $item['id'];
						else
							$idInfo = $item;
					}
					list(, $itemKind) = explode('#', $idInfo['kind']);
					fwrite($fileKinds, "$itemKind\n");
					if (!empty($idInfo[$itemKind . 'Id']))
						fwrite($fileIds, $idInfo[$itemKind . 'Id'] . "\n");
					else
						fwrite($fileIds, $idInfo['id'] . "\n");
					// Change the comma (%2C) into unicode &sbquo; to avoid conflicts
					fwrite($fileTitles, str_replace(',', '‚', $snippet['title']) . "\n");
					fwrite($filePubTime, str_replace('.000Z', '', $snippet['publishedAt']) . "\n");
					if (!empty($snippet['thumbnails'])) {
						if (!empty($snippet['thumbnails']['medium']))
							fwrite($fileImages, str_replace('https://', 'http://', $snippet['thumbnails']['medium']['url'] . "\n"));
						else
							fwrite($fileImages, str_replace('https://', 'http://', $snippet['thumbnails']['default']['url'] . "\n"));
					}
					else
						fwrite($fileImages, "\n");
				}
				fclose($fileIds);
				fclose($fileKinds);
				fclose($fileTitles);
				fclose($fileImages);
				fclose($filePubTime);
				fclose($filePLIds);
				fclose($filePLPos);

				simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.item_count', strval($itemCount));
				simpleFileWrite_2_4_1($dataFilePath . 'ims_yv_api.total', strval($apiDecoded['pageInfo']['totalResults']));

				$xmlReturn = '<root><code>' . strval($httpStatus) . '</code><kind>' . $apiDecoded['kind'] . "</kind>\r\n" .
					'<itemCount>' . strval($itemCount) . "</itemCount></root>\r\n";
				echo $xmlReturn;
				return;

			case 'youtube#videoListResponse':
				$partNames = array(
					'snippet'			=> array('title', 'publishedAt', 'channelId', 'channelTitle'),
					'contentDetails'	=> array('duration', 'caption', 'definition'),
					'statistics'		=> array('viewCount'),
				);
				$xmlReturn = '<root><code>' . strval($httpStatus) . '</code><kind>' . $apiDecoded['kind'] . "</kind>\r\n" .
					yvJSONtoXML_3($apiDecoded['items'][0], $partNames) . "</root>\r\n";
				echo $xmlReturn;
				return;

			case 'youtube#playlistListResponse':
				$partNames = array(
					'snippet'			=> array('title', 'publishedAt', 'channelId', 'channelTitle'),
					'contentDetails'	=> array('itemCount'),
				);
				$xmlReturn = '<root><code>' . strval($httpStatus) . '</code><kind>' . $apiDecoded['kind'] . "</kind>\r\n" .
					yvJSONtoXML_3($apiDecoded['items'][0], $partNames) . "</root>\r\n";
				echo $xmlReturn;
				return;

			case 'youtube#channelListResponse':
				$partNames = array(
					'snippet'			=> array('title', 'publishedAt'),
					'statistics'		=> array('subscriberCount', 'videoCount', 'viewCount'),
				);
				$xmlReturn = '<root><code>' . strval($httpStatus) . '</code><kind>' . $apiDecoded['kind'] . "</kind>\r\n" .
					yvJSONtoXML_3($apiDecoded['items'][0], $partNames) .
					yvJSONtoXML_all_3($apiDecoded['items'][0]['contentDetails'], array('relatedPlaylists')) . "</root>\r\n";
				echo $xmlReturn;
				return;

			default:
				break;
		}

		$xmlReturn = '<root><code>' . strval($httpStatus) . '</code></root>' . "\r\n";
		echo $xmlReturn;
		return;
	}
	else if (strcmp($id, 'site_dailymotion') == 0) {
		// It's a dailymotion request
		// 'link' must be given
		// No idea how to process http://www.dailymotion.com/video/ for now
		$link = str_replace('dailymotion.com/video', 'dailymotion.com/embed/video', $_GET['link']);
		$html = yp_file_get_contents_3($link);

		$mapRes = array('37' => '1080', '22' => '720', '35' => '480', '18' => '360', '34' => '360', '5' => '240');

		if (strpos($html, '"status_code":') === false) {
			if (strpos($html, '{"type":"video\/mp4",') !== false) {
				foreach ($formats as $format) {
					$urlTag = '"' . $mapRes[$format] . '":[{"type":"video\/mp4","url":"';
					if (strlen($link = trim(yp_str_between_2_1($html, $urlTag, '"'))) > 0)
						break;
				}
				$link = str_replace('\/', '/', $link);
				$extraInfo = 'H264-' . trim(yp_str_between_2_1($link, 'H264-', '/'));
			}

			if (!empty($_GET['actual_src']))
				$extraInfo .= '; S=' . $_GET['actual_src'];
			writeExtraInfo_2_4_1($extraInfo);

			// Redirect to the video stream
			header('Location: ' . $link);
			return;
		}

		$msgArray = json_decode('{"message":"' . yp_str_between_2_1($html, '"message":"', '"') . '"}', true);
		$msgUnavailable = '[DM] ** ' . $msgArray['message'] . ' **';
		$videoUnavailable = true;
		$id = $videoColorBars[$posColorBars ++];
	}
	else if (strcmp($id, 'site_flvxz') == 0) {
		unset($flvToken);
		unset($localFLVtoken);
		$fileLocalFLVtoken = '/usr/local/etc/dvdplayer/ims_flv_token.dat';
		if (file_exists($fileLocalFLVtoken) &&
			(strlen($localFLVtoken = trim(local_file_get_contents($fileLocalFLVtoken))) > 0)) {
			$flvToken = $localFLVtoken;
		}

		$methodFlvxz = 0;
		if ((!empty($USEcurl)) || (extension_loaded('openssl') && in_array('https', stream_get_wrappers())))
			$methodFlvxz = 1;
		else if (isset($flvToken))
			$methodFlvxz = 2;

		// Refer to $formats[0] as the highest acceptable resolution
		// [0=>低清，1=>标清，2=>高清，3=>超清，4=>720P，5=>1080P，6=>高码1080P，7=>原画，8=>4K，9=>高码4K]
		// '9' (not used in Youtube): accept everything, the higher the better
		// '37':   1080 -- <= 6
		// '22':    720 -- <= 4
		// '35':    480 -- <= 3
		// '18/34': 360 -- <= 2
		// '6':     270 -- <= 1
		// '5':     240 -- <= 0
		$resCutOff = array('9' => 9, '37' => 6, '22' => 4, '35' => 3, '18' => 2, '34' => 2, '6' => 1, '5' => 0);

		$msgError = ':';
		if ($methodFlvxz > 0) {
			if ($methodFlvxz == 1) {
				$msgError .= ' M=' . strval($methodFlvxz);
				// Need to use curl or openssl for making https requests
				$link = 'http://flvxz.com/?url=' . ($forFlv = urlencode($_GET['link']));
				$html = yp_file_get_contents_3($link);
				$urlBase = str_replace('www.flvxz.com', 'flvxz.com', trim(yp_str_between_2_1($html, "baseurl = '", "'")));

				$linkRef = $link;
				$link = $urlBase . '/getFlv.php?url=' . $forFlv;
				$html = yp_file_get_contents_3($link, array('Referer: ' . $linkRef));
				if (file_exists($fileYVSnippet = (dirname(__FILE__) . '/ypYVSnippet.php')))
					include($fileYVSnippet);
				$flvToken = 'verify/' . trim(yp_str_between_2_1($html, '/verify/', '"'));
				if (strlen($flvToken) > 7) {
					$link = str_replace('https', 'http', $urlBase) . '/api/url/' . $_GET['link'] .
						'/jsonp/purejson/ftype/mp4.flv/' . $flvToken;
				}
				else if (isset($localFLVtoken)) {
					$methodFlvxz = 2;
					$flvToken = $localFLVtoken;
				}
				else
					$link = '';
			}
			// Directly call method 2 or fallback from the failure of calling method 1
			if ($methodFlvxz == 2) {
				$msgError .= ' M=' . strval($methodFlvxz);
				// Call flvxz.com (flv.cn) to resolve the video url
				$link = 'http://api.flvxz.com/url/' . $_GET['link'] .
					'/jsonp/purejson/ftype/mp4.flv/' . $flvToken;
			}

			$json = yp_file_get_contents_3($link);
			if (!empty($json)) {
				$res = json_decode($json, true);
				if ((!empty($res)) && (count($res) > 0)) {
					// Go through each entries and look for the best fit
					$indexBest = -1;
					$indexBestRes = -1;
					$indexBestFtype = '';
					$countItems = count($res);
					$hdCutOff = intval($resCutOff[$formats[0]]);
					$strHDavail = '';
					for ($index = 0 ; $index < $countItems ; $index ++) {
						$item = $res[$index];
						if (count($item['files']) > 1) continue;
						$qualComp = explode('_', $item['quality']);
						$strHDavail .= (' ' . $item['hd'] . '-' . ($ftype = $qualComp[count($qualComp)-1]));
						if (($hd = intval($item['hd'])) > $hdCutOff) continue;
						// Preference: 1. higher resolution; 2. mp4
						if (($hd > $indexBestRes) || (($hd == $indexBestRes) && (strcasecmp($ftype, 'mp4') == 0))) {
							$indexBestRes = $hd;
							$indexBest = $index;
							$indexBestFtype = $ftype;
						}
					}
					$extraInfo = strval($indexBestRes) . '-' . $indexBestFtype . ' of' . $strHDavail .
									'; S=' . $_GET['actual_src']. '; M=' . strval($methodFlvxz);
					writeExtraInfo_2_4_1($extraInfo);
					// Redirect to the video stream
					header('Location: ' . $res[$indexBest]['files'][0]['furl']);
					return;
				}
				else
					$msgUnavailable = '[飛驢] ** 回傳無內容' . $msgError . ' **';
			}
			else
				$msgUnavailable = '[飛驢] ** 回傳空字串' . $msgError . ' **';
		}
		else
			$msgUnavailable = '[飛驢] ** 無法使用 -- ' . $_GET['actual_src'] . ' **';

		$videoUnavailable = true;
		$id = $videoColorBars[$posColorBars ++];
	}
	else if (strcmp($id, 'site_https_redir') == 0) {
		$urlToGo = $_GET['link'];
		if (file_exists($fileDataRedir) &&
			(strlen($localURLredir = trim(local_file_get_contents($fileDataRedir))) > 0)) {
			$urlRedir = $localURLredir;
			simpleFileWrite_2_4_1($fileDataURL, $urlToGo);
			$urlToGo = $urlRedir;
			simpleFileWrite_2_4_1($fileStep, '3');
		}
		$extraInfo = 'Redir';
		if (!empty($_GET['actual_src']))
			$extraInfo .= '; S=' . $_GET['actual_src'];
		writeExtraInfo_2_4_1($extraInfo);

		// Redirect to the video stream
		header('Location: ' . $urlToGo);
		return;
	}
	else if (strcmp($id, 'yv_url_redir') == 0) {
		$timestamp = '';
		if (file_exists($fileStep)) {
			$currStep = intval(trim(local_file_get_contents($fileStep)));
			if ($currStep == 2) {
				simpleFileWrite_2_4_1(($fileMethod = '/tmp/yv_url_redir.requestMethod' . $timestamp), $_SERVER['REQUEST_METHOD']);
				simpleFileWrite_2_4_1(($fileHeader = '/tmp/yv_url_redir.requestHeader' . $timestamp), print_r(($rh = getallheaders()), true));
				$extraOpt = '';
				foreach ($rh as $rhn => $rhv) {
					if ((strcmp($rhn, 'Range')) == 0) {
						list(, $v) = explode('=', $rhv);
						$extraOpt .= " -r $v";
					}
				}
				simpleFileWrite_2_4_1($fileExtraOpt, $extraOpt);

				if (file_exists($fileDataRedir) &&
					(strlen($localURLredir = trim(local_file_get_contents($fileDataRedir))) > 0)) {
					$urlRedir = $localURLredir;
					simpleFileWrite_2_4_1($fileStep, strval($currStep+1));
				}
				header('Location: ' . $urlRedir);
			}
		}
		return;
	}
	else if (strcmp($id, 'get_a_random_int') == 0) {
		$xmlReturn = '<root><int>' . strval(rand(1, 30000)) . '</int></root>' . "\r\n";
		echo $xmlReturn;
		return;
	}

	do {
		// Two ways to get youtube videos
		// 1. May encounter "age verification"
		//		$link = 'https://www.youtube.com/watch?v=' . $id;
		// 2. May be forbidden by the video owner settings
		//		$link = 'https://www.youtube.com/get_video_info?video_id=' . $id;

		// Try the first way
		$link = 'https://www.youtube.com/watch?v=' . $id;
		$html = yp_file_get_contents_3($link);

		if (strpos($html, 'verify_age') !== false) {
			$link = 'https://www.youtube.com/get_video_info?video_id=' . $id;
			$html = yp_file_get_contents_3($link);
		}

		if (($availability = strpos(yp_str_between_2_1(yp_str_between_2_1($html, 'id="player-unavailable"', '>'), 'class="', '"'), ' hid ')) === false) {
			if ($videoUnavailable === false) {
				$videoUnavailable = true;
				$msgs = explode("\n", trim(yp_str_between_2_1(yp_str_between_2_1($html, '<h1 id="unavailable-message"', '/h1>'), '>', '<')));
				if (!empty($msgUnavailable))
					$msgUnavailable .= '; ';
				$msgUnavailable .= '[YV] ** ' . $msgs[count($msgs)-1] . ' **';
			}
			$id = $videoColorBars[$posColorBars ++];
		}
		else
			break;
	} while(true);

	// HTTP Live Stream
	$separators = array(
		array('"hlsvp":"', '"'),
	);
	foreach ($separators as $separator) {
		$timestamp = '';
		// for debugging purpose
		//$timestamp = ('.' . strval(time()));
		if (strpos($html, $separator[0]) !== false) {
			if (strlen($hlsvp = str_replace('\/', '/', trim(yp_str_between_2_1($html, $separator[0], $separator[1])))) <= 0)
				break;

			$strM3U8 = yp_file_get_contents_3($hlsvp);
			$strMark = '#EXTM3U';
			if (strcmp(substr($strM3U8, 0, strlen($strMark)), $strMark) != 0)
				break;

			simpleFileWrite_2_4_1('/tmp/yv_hls_top.m3u8' . $timestamp, $strM3U8);

			$mapRes = array(
				'37' => '1920x1080', '22' => '1280x720', '35' => '854x480', '18' => '640x360', '34' => '640x360', '5' => '426x240'
			);
			foreach ($formats as $format) {
				if (array_key_exists($format, $mapRes) && (strpos($strM3U8, ($resolution = $mapRes[$format])) !== false)) {
					$urlM3U8 = trim(yp_str_between_2_1(yp_str_between_2_1($strM3U8, $resolution, '#'), "\n", '.m3u8') . '.m3u8');
					setupCallBack_3_1($fileCallback);
					if (file_exists($fileDataRedir) &&
						(strlen($localURLredir = trim(local_file_get_contents($fileDataRedir))) > 0)) {
						$urlRedir = $localURLredir;
						simpleFileWrite_2_4_1($fileDataURL, $urlM3U8);
						$urlToGo = $urlRedir;
						simpleFileWrite_2_4_1($fileStep, '1');
						writeExtraInfo_2_4_1('CODECS=' . trim(yp_str_between_rev_3_1($strM3U8, $resolution, 'CODECS=')) . $resolution);
					}

					// Redirect to the video stream
					header('Location: ' . $urlToGo);
					return;
				}
			}
		}
	}

	// Get the format list
	$separators = array(
		array('"fmt_list":"', '"'),
		array('"fmt_list": "', '"')
	);
	foreach ($separators as $separator) {
		if (strpos($html, $separator[0]) !== false) {
			$fmtList = explode(',', str_replace('\/', '/', trim(yp_str_between_2_1($html, $separator[0], $separator[1]))));
			break;
		}
	}

	// Get the format <-> url map
	$separators = array(
		array('"url_encoded_fmt_stream_map":"', '"'),
		array('"url_encoded_fmt_stream_map": "', '"')
	);
	foreach ($separators as $separator) {
		if (strpos($html, $separator[0]) !== false) {
			$urlList = explode(',', ($htmlToExplode = trim(yp_str_between_2_1($html, $separator[0], $separator[1]))));
			break;
		}
	}

	// Select the video url according to the user preference
	$supportedVids = array();
	foreach ($urlList as $urlEntry) {
		// Decode '&' (\u0026) if necessary
		$urlEntry = str_replace('\u0026', '&', $urlEntry);
		$itagInURL = trim(yp_str_between_2_1($urlEntry, 'itag=', '&'));
		$key = array_search($itagInURL, $formats);
		if ($key !== false) {
			$fmtInfo = '';
			foreach ($fmtList as $fmtEntry) {
				$lenItagInURL = strlen($itagInURL);
				if (strncmp($fmtEntry, $itagInURL, $lenItagInURL) == 0) {
					$fmtInfo = $fmtEntry;
					break;
				}
			}
			// Ignore 'itag=XX&url='
			$supportedVids[$key] = array(urldecode(yp_str_between_2_1($urlEntry, 'url=', '&')), $fmtInfo, $urlEntry);
		}
	}

	ksort($supportedVids);
	$v = array_values($supportedVids);

	// User preferred format (use the first one)
	$urlToGo = $v[0][0];

	$separators = array(
		array('"js":"', '"'),
		array('"js": "', '"')
	);
	// http://userscripts.org/scripts/review/25105
	//		url=url+"&signature="+signature;
	// Get the signature from urlEntry if necessary
	if (strpos($urlToGo, 'signature') === false) {
		$urlEntry = $v[0][2];
		if (strpos($urlEntry, 'sig=') !== false) {
			$signature = trim(yp_str_between_2_1($urlEntry, 'sig=', '&'));
		}
		else if (strpos($urlEntry, 's=') !== false) {
			// encrypted signature
			$s_len = strlen($s = trim(yp_str_between_2_1($urlEntry, 's=', '&')));

			try {
				// Download the JS code
				foreach ($separators as $separator) {
					if (strpos($html, $separator[0]) !== false) {
						$linkJS = 'https:' . str_replace('\/', '/', trim(yp_str_between_2_1($html, $separator[0], $separator[1])));
						break;
					}
				}

				// set("signature",Wq(c))
				//$linkJS = 'https://s.ytimg.com/yts/jsbin/html5player-zh_TW-vfl3r5wZG/html5player.js';
				// signature=VD(c)
				//$linkJS = 'https://s.ytimg.com/yts/jsbin/html5player-ima-en_US-vflkClbFb.js';
				$codeJS = yp_file_get_contents_3($linkJS);

				$fileLocalYoutubeVideoSIGredir = '/usr/local/etc/dvdplayer/ims_yv_sig_redir.dat';
				if (file_exists($fileLocalYoutubeVideoSIGredir) &&
					(strlen($localSIGredir = trim(local_file_get_contents($fileLocalYoutubeVideoSIGredir))) > 0)) {
					$sigRedir = $localSIGredir;

					$sigData = '';
					$sigData .= "// $linkJS\n";
					if (strlen($decFuncName = trim(yp_str_between_2_1($codeJS, '"signature",', '('))) <= 0) {
						$decFuncName = trim(yp_str_between_2_1($codeJS, 'signature=', '('));
					}
					$topFunc = $decFuncName;

					while(true) {
						$sigData .= "// Need: \"$decFuncName\"\n";
						$sigData .= extrJSCodeID_2_3($codeJS, $decFuncName);
						simpleFileWrite_2_4_1('/usr/local/etc/dvdplayer/ims_yv_sig_data.dat', $sigData . "print($topFunc(\"$s\"));\n");

						$signature = trim(yp_file_get_contents_3($sigRedir));

						if (strpos($signature, 'ReferenceError:') === false) break;

						$decFuncName = trim(yp_str_between_2_1($signature, 'ReferenceError:', 'is not'));
					}
				}
			}
			catch (Exception $e) {
				$signature = '';
			}
		}
		$urlToGo .= ('&signature=' . $signature);
	}

	if ($URLonly === false) {
		// Set the extra information for display
		$extraInfo = $v[0][1];

		// Clean the cc data file
		unlink($filenameCount  = '/usr/local/etc/dvdplayer/ims_cc_count.dat');
		unlink($filenameStart  = '/usr/local/etc/dvdplayer/ims_cc_start.dat');
		unlink($filenameEnd    = '/usr/local/etc/dvdplayer/ims_cc_end.dat');
		unlink($filenameText   = '/usr/local/etc/dvdplayer/ims_cc_text.dat');

		$ccStatus = '';
		unlink($filenameStatus = '/usr/local/etc/dvdplayer/ims_cc_status.dat');

		if ($videoUnavailable !== false) {
			// video unavailable, discard CC
			$ccStatus = $msgUnavailable;
			$ccStatus .= "\n255:0:0";
			$extraInfo .= " $msgUnavailable";
		}
		else if (isset($ccPreferredLangs)) {
			// Get the available cc list
			$link = 'https://www.youtube.com/api/timedtext?type=list&v=' . $id;
			$xml = yp_file_get_contents_3($link);

			if ((strlen($xml) > 0) && (strpos($xml, '<track ') !== false)) {
				// Get the available cc list
				$ccList = explode('<track ', $xml);
				unset($ccList[0]);
				$ccList = array_values($ccList);

				// Select the cc according to the user preference
				$allLangs = array();
				$supportedLangs = array();
				foreach ($ccList as $ccEntry => $ccData) {
					$ccCode = trim(yp_str_between_2_1($ccData, 'lang_code="', '"'));
					$ccName = trim(yp_str_between_2_1($ccData, 'name="', '"'));
					$ccOriginal = trim(yp_str_between_2_1($ccData, 'lang_original="', '"'));
					$allLangs[] = $ccCode;
					$key = array_search($ccCode, $ccPreferredLangs);
					if (($key !== false) && (empty($supportedLangs[$key]))) {
						$supportedLangs[$key] = array($ccCode, $ccName, $ccOriginal);
					}
				}

				$allL = implode(',', $allLangs);

				if (count($supportedLangs) > 0) {

					// Get the preferred cc data
					ksort($supportedLangs);
					$cc = array_values($supportedLangs);

					$ccNameDisplay = $cc[0][1];
					if (strlen($ccNameDisplay) == 0)
						$ccNameDisplay = $cc[0][2];
					if (strlen($ccNameDisplay) > 0) {
						$ccNameDisplay = ': ' . $ccNameDisplay;
					}

					$link = 'https://www.youtube.com/api/timedtext?type=track&v=' . $id . '&lang=' . $cc[0][0] . '&name=' . urlencode($cc[0][1]);
					$xml = yp_file_get_contents_3($link);

					if ((strlen($xml) > 0) && (strpos($xml, '<transcript>') !== false)) {
						$fileStart = fopen($filenameStart, 'w');
						$fileEnd = fopen($filenameEnd, 'w');
						$fileText = fopen($filenameText, 'w');

						$data = explode('<text', $xml);
						unset($data[0]);
						$data = array_values($data);

						$dataCount = 0;

						$dataCount ++;
						fwrite($fileStart, "-60\n");
						fwrite($fileEnd,   "-50\n");
						fwrite($fileText,  "\n");

						$dataCount ++;
						fwrite($fileStart, "-40\n");
						fwrite($fileEnd,   "-30\n");
						fwrite($fileText,  "\n");

						$dataCount ++;
						fwrite($fileStart, "-20\n");
						fwrite($fileEnd,   "-10\n");
						fwrite($fileText,  "\n");

						foreach ($data as $dataEntry) {
							$start = floatval(trim(yp_str_between_2_1($dataEntry, 'start="', '"')));
							$dur   = floatval(trim(yp_str_between_2_1($dataEntry, 'dur="', '"')));
							$text  = trim(htmlspecialchars_decode(
										convertUnicodePoints(
											yp_str_between_2_1($dataEntry, '">', '</text>')), ENT_QUOTES));
							$end   = $start + $dur;

							$textLines = explode("\n", $text);
							foreach ($textLines as $textLine) {
								$dataCount ++;
								fwrite($fileStart, strval(floor($start * 10)) . "\n");
								fwrite($fileEnd,   strval(floor($end * 10)) . "\n");
								fwrite($fileText,  $textLine . "\n");
							}
						}

						$dataCount ++;
						fwrite($fileStart, "864000\n");
						fwrite($fileEnd,   "864010\n");
						fwrite($fileText,  "\n");

						fclose($fileStart);
						fclose($fileEnd);
						fclose($fileText);

						// Write the number of lines
						simpleFileWrite_2_4_1($filenameCount, strval($dataCount));

						$ccStatus = '成功載入外掛字幕 ' . $cc[0][0] . $ccNameDisplay . ', 全部: ' . $allL;
						$extraInfo .= (' [' . $cc[0][0] . $ccNameDisplay . ']{' . $allL . '}');
					}
					else if ((strlen($xml) > 0) && (strpos($xml, '<title>Error') !== false)) {
						$errorCode = trim(yp_str_between_2_1($xml, '<b>', '.</b>'));
						$ccStatus = '無法載入外掛字幕 ' . $cc[0][0] . $ccNameDisplay . ', 全部: ' . $allL . ' (Error ' . $errorCode . ')';
						$ccStatus .= "\n255:0:0";
						$extraInfo .= (' [' . $errorCode . ' @ ' . $cc[0][0] . $ccNameDisplay . ']{' . $allL . '}');
					}
					else {
						$ccStatus = '無法載入外掛字幕 ' . $cc[0][0] . $ccNameDisplay . ', 全部: ' . $allL;
						$ccStatus .= "\n255:0:0";
						$extraInfo .= (' [X @ ' . $cc[0][0] . $ccNameDisplay . ']{' . $allL . '}');
					}
				}
				else {
					$ccStatus = '無可用之外掛字幕, 接受: ' . $localCCPrefs . ' -- 全部: ' . $allL;
					$ccStatus .= "\n255:0:0";
					$extraInfo .= (' [# @ ' . $localCCPrefs . ']{' . $allL . '}');
				}
			}
			else if ((strlen($xml) > 0) && (strpos($xml, '<title>Error') !== false)) {
				$errorCode = trim(yp_str_between_2_1($xml, '<b>', '.</b>'));
				$ccStatus = '無法取得外掛字幕列表 (Error ' . $errorCode . ')';
				$ccStatus .= "\n255:0:0";
				$extraInfo .= ' {' . $errorCode . '}';
			}
			else {
				$ccStatus = '影片未提供外掛字幕或無法取得外掛字幕列表';
				$ccStatus .= "\n255:0:0";
				$extraInfo .= ' {-}';
			}
		}
		else {
			$extraInfo .= ' [-]';
		}
		simpleFileWrite_2_4_1('/usr/local/etc/dvdplayer/ims_cc_status.dat', $ccStatus);
		if (!empty($_GET['actual_src']))
			$extraInfo .= '; S=' . $_GET['actual_src'];
		writeExtraInfo_2_4_1($extraInfo);

		setupCallBack_3_1($fileCallback);
		if (file_exists($fileDataRedir) &&
			(strlen($localURLredir = trim(local_file_get_contents($fileDataRedir))) > 0)) {
			$urlRedir = $localURLredir;
			simpleFileWrite_2_4_1($fileDataURL, $urlToGo);
			$urlToGo = $urlRedir;
			simpleFileWrite_2_4_1($fileStep, '1');
		}

		// Redirect to the video stream
		header('Location: ' . $urlToGo);
	}
	else if (!empty($_GET['URLtext'])) {
		echo $urlToGo;
	}
	else {
		// For debug purpose, output variables for observation
		if (!empty($_GET['displayVariables'])) {
			$variables = explode(',', $_GET['displayVariables']);
			foreach ($variables as $variable) {
				echo '<' . $variable . '>' . print_r(${$variable}, true) . '</' . $variable . ">\n";
			}
		}
		echo '<a id="' . $id .
				'" url_orig="' . $link .
				'" href="' . $urlToGo . '">' . $urlToGo . "</a>\n";
	}

// ---------- youtube.video.php: END ----------
?>
