<?php
	$link = $search = 'http://www.pornomovies.com/categories/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<a target', ($htmlToExplode = str_between($html, '<div id="skyscrape"', '</div>')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
