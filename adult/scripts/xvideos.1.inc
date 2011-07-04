<?php
	$link = $search = 'http://www.xvideos.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlMain = explode('id="pag"', $html);
	$htmlBody = explode('</div>', $htmlMain[2]);

	$videos = explode('<a ', $htmlBody[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
