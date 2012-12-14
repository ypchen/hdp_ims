<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('"video-detail-title"', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$links = array();
	$titles = array();

	$siteURLprefix = '';
	foreach($videos as $video) {
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$titles[] = $title;

		$v = explode('<div class="detailed-video4"', $video);
		$link  = $siteURLprefix . trim(str_between($v[1], ' src="', '"'));
		$links[] = $link;
	}

	$iStart = intval($extra);
?>
