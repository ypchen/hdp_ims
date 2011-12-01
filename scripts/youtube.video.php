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
// ---------- youtube.vide.php: BEGIN ----------

	// If there is no 'query',
	// respond to the request of youtube.video.php
	if (($evalLevel == 0) && empty($_GET['query'])) {
		// Read myself and get the body to send
		$meToSendBody = str_between(file_get_contents(__FILE__),
						"// ---------- youtube.vide.php: BEGIN ----------\r\n",
						"// ---------- youtube.vide.php: END ----------\r\n");
		$meToSend = '// <md5sum>' .
						md5($meToSendBody) .
						"</md5sum>\n" .
						"// ---------- youtube.vide.php: BEGIN ----------\r\n" .
						$meToSendBody .
						"// ---------- youtube.vide.php: END ----------\r\n";
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
			$rmtSrc = file_get_contents($rmtSrcURL);
			// The length of <md5sum /> is already 52
			if (strlen($rmtSrc) > 52) {
				$md5sum = str_between($rmtSrc, '<md5sum>', '</md5sum>');
				$receivedCode = str_between($rmtSrc,
								"// ---------- youtube.vide.php: BEGIN ----------\r\n",
								"// ---------- youtube.vide.php: END ----------\r\n");
				// Run the download source if the md5sum is correct
				if (strcmp($md5sum, md5($receivedCode)) == 0) {
					$evalLevel ++;
					eval($receivedCode);
					return;
				}
			}
		}
	}

	// No matter it's the local source or remote source,
	// 'query' is given.
	$id = $_GET['query'];

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
		(strlen($localFmtPrefs = file_get_contents($fileLocalYoutubeVideoFmtPrefs)) > 0)) {
		$fmtPrefs = $localFmtPrefs;
	}

	// Explode the string to get the format preference
	$formats = explode(',', $fmtPrefs);

	// If the local file exists and contains a string whose length > 0, use it
	$fileLocalYoutubeVideoCCPrefs = '/usr/local/etc/dvdplayer/ims_yv_cc_prefs.dat';
	if (file_exists($fileLocalYoutubeVideoCCPrefs) &&
		(strlen($localCCPrefs = file_get_contents($fileLocalYoutubeVideoCCPrefs)) > 0)) {
		// Explode the string to get the cc preference
		$ccPreferredLangs = explode(',', $localCCPrefs);
	}
	else {
		$ccPreferredLangs = null;
	}

	// Chrome 14.0.825.0
	// http://www.useragentstring.com/pages/Chrome/
	$userAgent        = 'Mozilla/5.0 (X11; Linux i686) AppleWebKit/535.1 (KHTML, like Gecko) Ubuntu/11.04 Chromium/14.0.825.0 Chrome/14.0.825.0 Safari/535.1';
	ini_set('user_agent', $userAgent);

	// Two ways to get youtube videos
	// 1. May encounter "age verification"
	//		$link = 'http://www.youtube.com/watch?v=' . $id;
	// 2. May be forbidden by the video owner settings
	//		$link = 'http://www.youtube.com/get_video_info?video_id=' . $id;

	// Try the first way
	$link = 'http://www.youtube.com/watch?v=' . $id;
	$html = file_get_contents($link);

	if (strpos($html, 'verify_age') !== false) {
		$link = 'http://www.youtube.com/get_video_info?video_id=' . $id;
		$html = file_get_contents($link);
	}

	// Get the format list
	$fmtList = explode(',', urldecode(trim(str_between($html, 'fmt_list=', '&'))));

	// Get the format <-> url map
	$urlList = explode(',', urldecode(trim(str_between($html, 'url_encoded_fmt_stream_map=', '&'))));

	// Select the video url according to the user preference
	$supportedVids = array();
	foreach ($fmtList as $fmtEntry => $fmtData) {
		$fmtDetail = explode('/', $fmtData);
		$key = array_search($fmtDetail[0], $formats);
		if ($key !== false) {
			// Ignore 'url='
			$supportedVids[$key] = array(urldecode(substr($urlList[$fmtEntry], 4)), $fmtData);
		}
	}

	ksort($supportedVids);
	$v = array_values($supportedVids);

	// User preferred format
	$urlToGo = $v[0][0];
	// Cut the problematic tail
	$cutPos = strpos($urlToGo, '&quality=');
	if ($cutPos !== false) {
		$urlToGo = substr($urlToGo, 0, $cutPos);
	}

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
		$xml = file_get_contents($link);

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
				$xml = file_get_contents($link);

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

// ---------- youtube.vide.php: END ----------
?>
