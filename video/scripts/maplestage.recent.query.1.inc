<?php
	$link = 'http://www.maplestage.com/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="latest_shows_block">', $html);

	$videos = explode('<div class="latest_show">', $htmlBody[1]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
