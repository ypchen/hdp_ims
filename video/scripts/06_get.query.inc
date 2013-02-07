<?php
	// http://php.net/manual/en/function.urldecode.php
	/*
		Warning
		The superglobals $_GET and $_REQUEST are already decoded.
		Using urldecode() on an element in $_GET or $_REQUEST
		could have unexpected and dangerous results.
	*/
	$query = '';
	$page = 1;
	$search = '';
	unset($cat);
	unset($extra);
	if(!empty($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		$page = intval($queryArr[0]);
		$search = $queryArr[1];
		if (count($queryArr) > 2) {
			$cat = str_replace('%2C', ',', $queryArr[2]);
			if (strcmp($cat, '') == 0) {
				unset($cat);
			}
		}
		if (count($queryArr) > 3) {
			$extra = $queryArr[3];
			if (strcmp($extra, '') == 0) {
				unset($extra);
			}
		}
	}

	$history_title = $search;
	$history_filename = $cat;
	if(isset($_GET['history'])) {
		$history = intval($_GET['history']);
	}
	else {
		$history = 0;
	}
	if(isset($_GET['history_peer_path'])) {
		$history_peer_path = $_GET['history_peer_path'];
	}
	else {
		$history_peer_path = '';
	}
	if(isset($_GET['history_peer_path_supp'])) {
		$history_peer_path_supp = $_GET['history_peer_path_supp'];
	}
	else {
		$history_peer_path_supp = '';
	}
	if(isset($_GET['history_peer_name'])) {
		$history_peer_name = $_GET['history_peer_name'];
	}
	else {
		$history_peer_name = '';
	}
	if(isset($_GET['history_peer_desc'])) {
		$history_peer_desc = $_GET['history_peer_desc'];
	}
	else {
		$history_peer_desc = '';
	}

	if(!empty($_GET['input_method'])) {
		$inputMethod = $_GET['input_method'];
	}
	else {
		$inputMethod = $defaultInputMethod;
	}

	if(!empty($_GET['yv_fmt_prefs'])) {
		$youtubeVideoFmtPrefs = $_GET['yv_fmt_prefs'];
	}
	else {
		$youtubeVideoFmtPrefs = $defaultYoutubeVideoFmtPrefs;
	}

	if(!empty($_GET['yv_cc_prefs'])) {
		$youtubeVideoCCPrefs = $_GET['yv_cc_prefs'];
	}
	else {
		$youtubeVideoCCPrefs = $defaultYoutubeVideoCCPrefs;
	}

	if(!empty($_GET['yv_rmt_src'])) {
		$youtubeVideoRemoteSource = $_GET['yv_rmt_src'];
	}
	else {
		$youtubeVideoRemoteSource = $defaultYoutubeVideoRemoteSource;
	}

	if(!empty($_GET['youtube_video'])) {
		$localhostYoutubeVideo = $_GET['youtube_video'];
	}
	else {
		$localhostYoutubeVideo = $defaultLocalhostYoutubeVideo;
	}
?>
