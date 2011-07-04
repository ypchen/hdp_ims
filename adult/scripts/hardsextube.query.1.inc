<?php
	$link = str_replace(' ', '+', $search . '/Relevance/' . ($page-1));
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div style="background: url', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
