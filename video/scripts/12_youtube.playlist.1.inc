<?php
	$link = 'http://www.youtube.com/playlist?p=' . $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div id="playlist-container"', $html);

	// No paging for playlists
	$page = 0;

	$videos = explode('<li class="playlist-video-item', $htmlBody[1]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
