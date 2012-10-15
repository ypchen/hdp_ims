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

	function str_between($string, $start, $end) {
		if (($ini = strpos($string, $start)) === false)
			return '';
		$ini += strlen($start);
		$len = strpos($string, $end, $ini) - $ini;
		return substr($string, $ini, $len);
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

	// Check the existence because this part of code may be re-loaded and re-evaluated
	if (function_exists('yp_file_get_contents_1_7') === false) {
		function yp_file_get_contents_1_7($url, $data_to_post = null,
			$http_header = null, $user_agent = null, $timeout = 30) {

			global $USEcurl;

			if (empty($user_agent))
				$user_agent = ini_get('user_agent');

			if (!empty($USEcurl)) {
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
	}

	// Check the existence because this part of code may be re-loaded and re-evaluated
	if (function_exists('local_file_get_contents') === false) {
		function local_file_get_contents($file) {
			return file_get_contents($file);
		}
	}

	// If there is no 'query',
	// respond to the request of youtube.video.php
	if (($evalLevel == 0) && empty($_GET['query'])) {
		// Read myself and get the body to send
		$meToSendBody = str_between(local_file_get_contents(__FILE__),
						"// ---------- youtube.video.php: BEGIN ----------\r\n",
						"// ---------- youtube.video.php: END ----------\r\n");
		$meToSend = '// <md5sum>' .
						md5($meToSendBody) .
						"</md5sum>\n" .
						"// ---------- youtube.video.php: BEGIN ----------\r\n" .
						$meToSendBody .
						"// ---------- youtube.video.php: END ----------\r\n";
		echo $meToSend;
		return;
	}

	// If there is 'query' and 'yv_rmt_src',
	// request youtube.video.php if yv_rmt_src is given
	if (($evalLevel == 0) && (!empty($_GET['yv_rmt_src']))) {
		$rmtSrcURL = $_GET['yv_rmt_src'];
		// Check if it's really "remote"
		if ((strpos($rmtSrcURL, '://localhost') === false) &&
			(strpos($rmtSrcURL, '://127.0.0.1') === false)) {
			// Get the remote source
			$rmtSrc = yp_file_get_contents_1_7($rmtSrcURL);
			// The length of <md5sum /> is already 52
			if (strlen($rmtSrc) > 52) {
				$md5sum = str_between($rmtSrc, '<md5sum>', '</md5sum>');
				$receivedCode = str_between($rmtSrc,
								"// ---------- youtube.video.php: BEGIN ----------\r\n",
								"// ---------- youtube.video.php: END ----------\r\n");
				// Run the download source if the md5sum is correct
				if (strcmp($md5sum, md5($receivedCode)) == 0) {
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
	$userAgent        = 'Mozilla/5.0 (X11; Linux i686) AppleWebKit/535.1 (KHTML, like Gecko) Ubuntu/11.04 Chromium/14.0.825.0 Chrome/14.0.825.0 Safari/535.1';
	ini_set('user_agent', $userAgent);

	// No matter it's the local source or remote source,
	// 'query' is given.
	$id = $_GET['query'];

	// It's a dailymotion request
	if (strcmp($id, 'site_dailymotion') == 0) {
		// 'link' must be given
		$link = $_GET['link'];
		$html = yp_file_get_contents_1_7($link);

		if (
			(strlen($link = trim(str_between($html, '"stream_h264_url":"', '"'))) > 0) ||
			(strlen($link = trim(str_between($html, '"stream_h264_ld_url":"', '"'))) > 0)
		) {
			$link = str_replace('\/', '/', $link);
			$extraInfo = 'H264-' . trim(str_between($link, 'H264-', '/'));

			// Write the extraInfo file
			$fileExtraInfo = fopen('/usr/local/etc/dvdplayer/ims_extra_info.dat', 'w');
			fwrite($fileExtraInfo, $extraInfo);
			fclose($fileExtraInfo);

			// Return the video stream
			header('Location: ' . $link);
		}
		return;
	}

	// Check if only URL is wanted
	$URLonly = false;
	if (!empty($_GET['URLonly']))
		$URLonly = true;

	// User preferred formats
	// http://en.wikipedia.org/wiki/YouTube

	// Default: 22,35,34,18,6,5
	$fmtPrefs = '22,35,34,18,6,5';

	// If yv_fmt_prefs is given in the url, use it
	if (!empty($_GET['yv_fmt_prefs'])) {
		$fmtPrefs = $_GET['yv_fmt_prefs'];
	}

	// If the local file exists and contains a string whose length > 0, use it
	$fileLocalYoutubeVideoFmtPrefs = '/usr/local/etc/dvdplayer/ims_yv_fmt_prefs.dat';
	if (file_exists($fileLocalYoutubeVideoFmtPrefs) &&
		(strlen($localFmtPrefs = local_file_get_contents($fileLocalYoutubeVideoFmtPrefs)) > 0)) {
		$fmtPrefs = $localFmtPrefs;
	}

	// Explode the string to get the format preference
	$formats = explode(',', $fmtPrefs);

	// If the local file exists and contains a string whose length > 0, use it
	$fileLocalYoutubeVideoCCPrefs = '/usr/local/etc/dvdplayer/ims_yv_cc_prefs.dat';
	if (file_exists($fileLocalYoutubeVideoCCPrefs) &&
		(strlen($localCCPrefs = local_file_get_contents($fileLocalYoutubeVideoCCPrefs)) > 0)) {
		// Explode the string to get the cc preference
		$ccPreferredLangs = explode(',', $localCCPrefs);
	}
	else {
		$ccPreferredLangs = null;
	}

	// Two ways to get youtube videos
	// 1. May encounter "age verification"
	//		$link = 'http://www.youtube.com/watch?v=' . $id;
	// 2. May be forbidden by the video owner settings
	//		$link = 'http://www.youtube.com/get_video_info?video_id=' . $id;

	// Try the first way
	$link = 'http://www.youtube.com/watch?v=' . $id;
	$html = yp_file_get_contents_1_7($link);

	if (strpos($html, 'verify_age') !== false) {
		$link = 'http://www.youtube.com/get_video_info?video_id=' . $id;
		$html = yp_file_get_contents_1_7($link);
	}

	// Get the format list
	$separators = array(
		array('"fmt_list": "', '"', false),
		array('fmt_list=', '\u0026', true)
	);
	foreach ($separators as $separator) {
		if (strpos($html, $separator[0]) !== false) {
			if ($separator[2])
				$fmtList = explode(',', urldecode(trim(str_between($html, $separator[0], $separator[1]))));
			else
				$fmtList = explode(',', str_replace('\/', '/', trim(str_between($html, $separator[0], $separator[1]))));
			break;
		}
	}

	// Get the format <-> url map
	$separators = array(
		array('"url_encoded_fmt_stream_map": "', '"', false),
		array('url_encoded_fmt_stream_map=', '\u0026', true)
	);
	foreach ($separators as $separator) {
		if (strpos($html, $separator[0]) !== false) {
			if ($separator[2])
				$urlList = explode(',', urldecode(trim(str_between($html, $separator[0], $separator[1]))));
			else
				$urlList = explode(',', trim(str_between($html, $separator[0], $separator[1])));
			break;
		}
	}

	// Select the video url according to the user preference
	$supportedVids = array();
	foreach ($urlList as $urlEntry) {
		// Decode '&' (\u0026) if necessary
		$urlEntry = str_replace('\u0026', '&', $urlEntry);
		$itagInURL = trim(str_between($urlEntry, 'itag=', '&'));
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
			$supportedVids[$key] = array(urldecode(substr($urlEntry, strpos($urlEntry, 'url=') + 4)), $fmtInfo);
		}
	}

	ksort($supportedVids);
	$v = array_values($supportedVids);

	// User preferred format (use the first one)
	$urlToGo = $v[0][0];

	// http://userscripts.org/scripts/review/25105
	//		url=url+"&signature="+signature;
	// saved my day
	$urlToGo = str_replace('&sig=', '&signature=', $urlToGo);

	// It happens to itag=37 and itag=22.
	// There should be no space and " in the URL.
	$urlToGo = str_replace(' ', '%20', $urlToGo);
	$urlToGo = str_replace('"', '%22', $urlToGo);

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

		if (isset($ccPreferredLangs)) {

			// Get the available cc list
			$link = 'http://www.youtube.com/api/timedtext?type=list&v=' . $id;
			$xml = yp_file_get_contents_1_7($link);

			if ((strlen($xml) > 0) && (strpos($xml, '<track ') !== false)) {

				// Get the available cc list
				$ccList = explode('<track ', $xml);
				unset($ccList[0]);
				$ccList = array_values($ccList);

				// Select the cc according to the user preference
				$allLangs = array();
				$supportedLangs = array();
				foreach ($ccList as $ccEntry => $ccData) {
					$ccCode = trim(str_between($ccData, 'lang_code="', '"'));
					$ccName = trim(str_between($ccData, 'name="', '"'));
					$ccOriginal = trim(str_between($ccData, 'lang_original="', '"'));
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

					$link = 'http://www.youtube.com/api/timedtext?type=track&v=' . $id . '&lang=' . $cc[0][0] . '&name=' . urlencode($cc[0][1]);
					$xml = yp_file_get_contents_1_7($link);

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
							$start = floatval(trim(str_between($dataEntry, 'start="', '"')));
							$dur   = floatval(trim(str_between($dataEntry, 'dur="', '"')));
							$text  = trim(htmlspecialchars_decode(
										convertUnicodePoints(
											str_between($dataEntry, '">', '</text>')), ENT_QUOTES));
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
						$fileCount = fopen($filenameCount, 'w');
						fwrite($fileCount,  strval($dataCount));
						fclose($fileCount);

						$ccStatus = '成功載入外掛字幕 ' . $cc[0][0] . $ccNameDisplay . ', 全部: ' . $allL;
						$extraInfo .= (' [' . $cc[0][0] . $ccNameDisplay . ']{' . $allL . '}');
					}
					else if ((strlen($xml) > 0) && (strpos($xml, '<title>Error') !== false)) {
						$errorCode = trim(str_between($xml, '<b>', '.</b>'));
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
				$errorCode = trim(str_between($xml, '<b>', '.</b>'));
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

		// Write the ccStatus file
		$fileCCStatus = fopen('/usr/local/etc/dvdplayer/ims_cc_status.dat', 'w');
		fwrite($fileCCStatus, $ccStatus);
		fclose($fileCCStatus);

		// Write the extraInfo file
		$fileExtraInfo = fopen('/usr/local/etc/dvdplayer/ims_extra_info.dat', 'w');
		fwrite($fileExtraInfo, $extraInfo);
		fclose($fileExtraInfo);

		// Return the video stream
		header('Location: ' . $urlToGo);
	}
	else if (!empty($_GET['URLtext'])) {
		echo $urlToGo;
	}
	else {
		echo '<a id="' . $id .
				'" url_orig="' . $link .
				'" href="' . $urlToGo . '">' . $urlToGo . "</a>\n";
	}

// ---------- youtube.video.php: END ----------
?>
