<?php
	$query = '';
	$page = 1;
	$search = '';
	unset($cat);
	unset($extra);
	if(!empty($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		$page = $queryArr[0];
		$search = urldecode($queryArr[1]);
		if (count($queryArr) > 2) {
			$cat = urldecode($queryArr[2]);
			if (strcmp($cat, '') == 0) {
				unset($cat);
			}
		}
		if (count($queryArr) > 3) {
			$extra = urldecode($queryArr[3]);
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
		$inputMethod = urldecode($_GET['input_method']);
	}
	else {
		$inputMethod = $defaultInputMethod;
	}

	if(!empty($_GET['yv_fmt_prefs'])) {
		$youtubeVideoFmtPrefs = urldecode($_GET['yv_fmt_prefs']);
	}
	else {
		$youtubeVideoFmtPrefs = $defaultYoutubeVideoFmtPrefs;
	}

	if(!empty($_GET['yv_rmt_src'])) {
		$youtubeVideoRemoteSource = urldecode($_GET['yv_rmt_src']);
	}
	else {
		$youtubeVideoRemoteSource = $defaultYoutubeVideoRemoteSource;
	}

	if(!empty($_GET['youtube_video'])) {
		$localhostYoutubeVideo = urldecode($_GET['youtube_video']);
	}
	else {
		$localhostYoutubeVideo = $defaultLocalhostYoutubeVideo;
	}
?>
