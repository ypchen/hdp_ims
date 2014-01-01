<?php
	$link = $search = 'http://v.aibuka.com/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li ', ($htmlToExplode = str_between($html, '<ul class="nav"', '</ul>')));
	unset($videos[0]);	// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
