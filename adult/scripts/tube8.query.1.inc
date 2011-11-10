<?php
	if ($page == 1)
		$link = $search;
	else
		$link = $search . 'page/' . $page . '/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, ' prev-next-inactive">NEXT</li>') === true)
		$pageMax = $page;

	$videos = explode('<div id="video_', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
