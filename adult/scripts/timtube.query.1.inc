<?php
	$link = $search . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlMain = explode('<div id="right-column">', $html);

	$videos = explode('<div class="box"', $htmlMain[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
