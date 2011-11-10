<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div id = "video-detail-title"', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$links = array();
	$titles = array();

	$siteURLprefix = '';
	foreach($videos as $video) {
		$link  = $siteURLprefix . trim(str_between($video, ' src="', '"'));
		$links[] = $link;

		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$titles[] = $title;
	}

	$iStart = intval($extra);
?>
