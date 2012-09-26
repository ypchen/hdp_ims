<?php
	$link = $search . '/' . intval($page-1)*20;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '">&gt;</a>') === false)
		$pageMax = $page;

	$htmlMain = explode('<section id="video_list">', $html);
	$htmlBody = explode('<div class="pagination">', $htmlMain[1]);
	$videos = explode('browse_video_container', $htmlBody[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
