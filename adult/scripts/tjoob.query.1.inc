<?php
	$link = $search . '/top-' . 16*($page-1) . '/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, "<img src='/images/next.gif' alt='Next'") === false)
		$pageMax = $page;

	$videos = explode('<div class="vids">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
