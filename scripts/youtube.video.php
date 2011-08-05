<?php
	function str_between($string, $start, $end){
		$string = ' ' . $string;
		$ini = strpos($string, $start);
		if ($ini == 0)
			return '';
		$ini += strlen($start);
		$len = strpos($string, $end, $ini) - $ini;
		return substr($string, $ini, $len);
	}

	// Default id: FBI warning
	$id = 'ILGA5UFmfRM';
	if (!empty($_GET['query'])) {
		$id = $_GET['query'];
	}

	// User preferred formats
	// http://en.wikipedia.org/wiki/YouTube
	// Default: 37,22,35,34,18,5
	$fmtPrefs = '37,22,35,34,18,5';
	if (!empty($_GET['yv_fmt_prefs'])) {
		$fmtPrefs = $_GET['yv_fmt_prefs'];
	}
	$formats = explode(',', $fmtPrefs);

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
			$supportedVids[$key] = urldecode(substr($urlList[$fmtEntry], 4));
		}
	}

	ksort($supportedVids);
	$v = array_values($supportedVids);

	// User preferred format
	$urlToGo = $v[0];
	// Cut the problematic tail
	$cutPos = strpos($urlToGo, '&quality=');
	if ($cutPos !== false) {
		$urlToGo = substr($urlToGo, 0, $cutPos);
	}

	// Return the video stream
	header('Location: ' . $urlToGo);
?>
