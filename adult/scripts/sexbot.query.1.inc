<?php
	if ($page == 1)
		$link = $search;
	else
		$link = $search . '/latest/' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="video-item">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
