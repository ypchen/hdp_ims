<?php
	include('15_4_columns.inc');

	$link = 'http://www.maplestage.com/show/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<ul class="yearS', $html);

	$videos = explode('<div>', ($htmlToExplode = trim(str_between($htmlBody[1], 'orting">', '</ul>'))));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
