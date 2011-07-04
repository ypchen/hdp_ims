<?php
	$query = '';
	$link = '';
	$title = '';
	unset($extra);
	if(isset($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		$link = urldecode($queryArr[0]);
		if (count($queryArr) > 1)
			$title = urldecode($queryArr[1]);
		if (count($queryArr) > 2)
			$extra = urldecode($queryArr[2]);
	}

	$history = 0;
	if(isset($_GET['history'])) {
		$history = intval($_GET['history']);
	}

	if(isset($_GET['youtube_video'])) {
		$localhostYoutubeVideo = urldecode($_GET['youtube_video']);
	}
	else {
		$localhostYoutubeVideo = $defaultLocalhostYoutubeVideo;
	}
?>
