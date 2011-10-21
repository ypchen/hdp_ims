<?php
	$rowCount    = 11;
	$columnCount = 3;
	$itemWidthPC = 31.67;

	$link = 'http://www.maplestage.net/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="shows_list">', $html);

	$videos = explode('<td>', $htmlBody[2]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
