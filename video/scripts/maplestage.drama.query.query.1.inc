<?php
	$rowCount    = 11;
	$columnCount = 2;
	$itemWidthPC = 47.5;

	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="shows">', $html);

	$videos = explode('<div class="show">', $htmlBody[1]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
