<?php
	// http://php.net/manual/en/function.urldecode.php
	/*
		Warning
		The superglobals $_GET and $_REQUEST are already decoded.
		Using urldecode() on an element in $_GET or $_REQUEST
		could have unexpected and dangerous results.
	*/
	$query = '';
	$link = '';
	$title = '';
	unset($extra);
	if(!empty($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		//$link = urldecode($queryArr[0]);
		$link = $queryArr[0];
		if (count($queryArr) > 1) {
			//$title = urldecode($queryArr[1]);
			$title = str_replace('%2C', ',', $queryArr[1]);
		}
		if (count($queryArr) > 2) {
			//$extra = urldecode($queryArr[2]);
			$extra = $queryArr[2];
			if (strcmp($extra, '') == 0) {
				unset($extra);
			}
		}
	}

	$history = 0;
	if(isset($_GET['history'])) {
		$history = intval($_GET['history']);
	}

	if(!empty($_GET['input_method'])) {
		//$inputMethod = urldecode($_GET['input_method']);
		$inputMethod = $_GET['input_method'];
	}
	else {
		$inputMethod = $defaultInputMethod;
	}

	if(!empty($_GET['yv_fmt_prefs'])) {
		//$youtubeVideoFmtPrefs = urldecode($_GET['yv_fmt_prefs']);
		$youtubeVideoFmtPrefs = $_GET['yv_fmt_prefs'];
	}
	else {
		$youtubeVideoFmtPrefs = $defaultYoutubeVideoFmtPrefs;
	}

	if(!empty($_GET['yv_rmt_src'])) {
		//$youtubeVideoRemoteSource = urldecode($_GET['yv_rmt_src']);
		$youtubeVideoRemoteSource = $_GET['yv_rmt_src'];
	}
	else {
		$youtubeVideoRemoteSource = $defaultYoutubeVideoRemoteSource;
	}

	if(!empty($_GET['youtube_video'])) {
		//$localhostYoutubeVideo = urldecode($_GET['youtube_video']);
		$localhostYoutubeVideo = $_GET['youtube_video'];
	}
	else {
		$localhostYoutubeVideo = $defaultLocalhostYoutubeVideo;
	}
?>
