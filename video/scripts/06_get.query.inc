<?php
	$query = '';
	$page = 1;
	$search = '';
	unset($cat);
	unset($extra);
	if(isset($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		$page = $queryArr[0];
		$search = urldecode($queryArr[1]);
		if (count($queryArr) > 2)
			$cat = urldecode($queryArr[2]);
		if (count($queryArr) > 3)
			$extra = urldecode($queryArr[3]);
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
