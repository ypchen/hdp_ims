<?php
	$link = $search = 'http://www.xvideos.com/porn/japanese';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="main-categories"', $html);
	$htmlBody2 = explode('</ul>', $htmlBody[1]);

	$videos = explode('<li>', ($htmlToExplode = $htmlBody2[0]));
	unset($videos[count($videos)-1]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
