<?php
	$link = $search = 'http://xxxstash.com/browse';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlMain = explode('">Categories<', $html);
	$htmlBody = explode('</ul>', $htmlMain[1]);

	$videos = explode('<li>', $htmlBody[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgWidth   = 30;
//	$myImgHeight  = 40;
?>
