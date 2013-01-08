<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li class="span8"', ($htmlToExplode = str_between($html, '<ul class="unstyled"', '</ul>')));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgWidth   = 18;
	$myImgHeight  = 40;
?>
