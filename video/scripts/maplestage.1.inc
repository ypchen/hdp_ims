<?php
	$link = $search = 'http://maplestage.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlVideos = explode('<div class="submenu ', $html);
	unset($htmlVideos[0]);
	$videoString = '';
	foreach ($htmlVideos as $htmlVideo) {
		$videoString .= str_between($htmlVideo, '">', '<h');
	}
	$videos = explode(' href=', $videoString);
	unset($videos[0]);
	$videos = array_values($videos);

	// + 2 for hot shows & dramas
	$itemTotal = count($videos) + 2;
	include('05_check.base.inc');
?>
