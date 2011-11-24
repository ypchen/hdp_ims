<?php
	function str_between($string, $start, $end) {
		$string = ' ' . $string;
		$ini = strpos($string, $start);
		if ($ini == 0)
			return '';
		$ini += strlen($start);
		$len = strpos($string, $end, $ini) - $ini;
		return substr($string, $ini, $len);
	}

	$evalLevel = 0;
	$cutLine = (__LINE__+1); // Include the next line
//HERE: md5sum of the following lines except for the last line without php tags

	// If there is no 'query',
	// respond to the request of youtube.video.php
	if (($evalLevel == 0) && empty($_GET['query'])) {
		// Read myself and clear the php tag
		$me = str_replace('<?php', '',
			str_replace('?>', '',
				file_get_contents(__FILE__)));
		// Create an empty default return string
		$meToSend = '';
		// Break into lines
		$meLines = explode("\n", $me);
		if (count($meLines) > __LINE__) {
			for ($i = 0 ; $i < $cutLine ; $i ++)
				unset($meLines[$i]);
			$meToSend = implode("\n", $meLines);
			$meToSend = '//' . md5($meToSend) . "\n" . $meToSend;
		}
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
			// The length of //<md5sum> is already 34
			if (strlen($rmtSrc) > 34) {
				$rmtSrcLines = explode("\n", $rmtSrc);
				$md5sum = trim(substr($rmtSrcLines[0], 2));
				unset($rmtSrcLines[0]);
				$receivedCode = implode("\n", $rmtSrcLines);
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

	// Default: 22,35,34,18,5
	$fmtPrefs = '22,35,34,18,5';

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

	// $link = 'http://www.youtube.com/get_video_info?video_id=' . $id;
	$link = 'http://www.youtube.com/watch?v=' . $id;
	$html = file_get_contents($link);

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
	unlink($filenameStart = '/usr/local/etc/dvdplayer/ims_cc_start.dat');
	unlink($filenameEnd   = '/usr/local/etc/dvdplayer/ims_cc_end.dat');
	unlink($filenameText  = '/usr/local/etc/dvdplayer/ims_cc_text.dat');

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
				$allLangs[] = $ccCode;
				$key = array_search($ccCode, $ccPreferredLangs);
				if ($key !== false) {
					$supportedLangs[$key] = $ccCode;
				}
			}

			if (count($supportedLangs) > 0) {

				// Get the preferred cc data
				ksort($supportedLangs);
				$cc = array_values($supportedLangs);

				$link = 'http://www.youtube.com/api/timedtext?type=track&v=' . $id . '&lang=' . $cc[0];
				$xml = file_get_contents($link);

				if (strlen($xml) > 0) {
					$fileStart = fopen($filenameStart, 'w');
					$fileEnd = fopen($filenameEnd, 'w');
					$fileText = fopen($filenameText, 'w');

					$data = explode('<text', $xml);
					unset($data[0]);
					$data = array_values($data);
					$dataCount = count($data);

					fwrite($fileStart, strval($dataCount + 4) . "\n");
					fwrite($fileEnd,   strval($dataCount + 4) . "\n");
					fwrite($fileText,  strval($dataCount + 4) . "\n");

					fwrite($fileStart, "-60\n");
					fwrite($fileEnd,   "-50\n");
					fwrite($fileText,  "\n");

					fwrite($fileStart, "-40\n");
					fwrite($fileEnd,   "-30\n");
					fwrite($fileText,  "\n");

					fwrite($fileStart, "-20\n");
					fwrite($fileEnd,   "-10\n");
					fwrite($fileText,  "\n");

					foreach ($data as $dataEntry) {
						$start = floatval(trim(str_between($dataEntry, 'start="', '"')));
						$dur   = floatval(trim(str_between($dataEntry, 'dur="', '"')));
						$text  = str_replace('&#39;', "'",
									html_entity_decode(str_replace('&amp;', '&',
										trim(str_between($dataEntry, '">', '</text>')))));
						$end   = $start + $dur;

						$textLines = explode("\n", $text);
						foreach ($textLines as $textLine) {
							fwrite($fileStart, strval(floor($start * 10)) . "\n");
							fwrite($fileEnd, strval(floor($end * 10)) . "\n");
							fwrite($fileText, $textLine . "\n");
						}
					}

					fwrite($fileStart, "864000\n");
					fwrite($fileEnd,   "864010\n");
					fwrite($fileText,  "\n");

					fclose($fileStart);
					fclose($fileEnd);
					fclose($fileText);

					$extraInfo .= (' [' . $cc[0] . ']{' . implode(',', $allLangs) . '}');
				}
				else {
					$extraInfo .= (' [X]{' . implode(',', $allLangs) . '}');
				}
			}
			else {
				$extraInfo .= (' [#]{' . implode(',', $allLangs) . '}');
			}
		}
		else {
			$extraInfo .= ' {-}';
		}
	}
	else {
		$extraInfo .= ' [-]';
	}

	// Write the extraInfo file
	$fileExtraInfo = fopen('/usr/local/etc/dvdplayer/ims_extra_info.dat', 'w');
	fwrite($fileExtraInfo, $extraInfo);
	fclose($fileExtraInfo);

	// Return the video stream
	header('Location: ' . $urlToGo);
?>
