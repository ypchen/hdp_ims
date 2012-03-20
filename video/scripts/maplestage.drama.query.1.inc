<?php
	$link = 'http://www.maplestage.net/drama/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<ul class="yearS', $html);

	$videos = explode('<li>', trim(str_between($htmlBody[1], 'orting">', '</ul>')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
