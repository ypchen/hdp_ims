<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li ', ($htmlToExplode = str_between($html, '<ul class="nav nav-pills', '</ul>')));
	unset($videos[0]);	// Prefix: search text box
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
