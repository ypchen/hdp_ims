<?php
	$link = $search = 'http://www.pornomovies.com/categories/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li>', ($htmlToExplode = str_between($html, '<ul class="taglist"', '</ul>')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
