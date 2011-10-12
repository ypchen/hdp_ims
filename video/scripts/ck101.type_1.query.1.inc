<?php
	$itemNo = intval($extra);

	$rowCount    = 11;
	$columnCount = 4;
	$itemWidthPC = 23.75;

	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="pack pack_album"', $html);
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
