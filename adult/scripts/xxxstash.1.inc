<?php
	$link = $search = 'http://xxxstash.com/categories/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<p id="selImageBorder">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgWidth   = 30;
	$myImgHeight  = 40;
?>
