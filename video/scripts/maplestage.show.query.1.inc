<?php
	include('15_4_columns.inc');

	$link = 'http://www.maplestage.com/show/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode(' id="show_table"', $html);

	$videos = explode('<tr>', ($htmlToExplode = trim(str_between($htmlBody[1], '<tbody>', '</tbody>'))));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
