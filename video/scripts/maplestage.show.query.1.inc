<?php
	$rowCount    = 11;
	$columnCount = 4;
	$itemWidthPC = 23.75;

	$link = 'http://www.maplestage.com/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="shows_list">', $html);

	$videos = explode('<td>', $htmlBody[1]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
