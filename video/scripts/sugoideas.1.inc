<?php
	$link = $search = 'http://sugoideas.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlVideos  = str_between($html, '<div class="menuL"', '</div>');
	$htmlVideos .= str_between($html, '<div class="menu"', '</div>');

	$videos = explode('<li><a ', ($htmlToExplode = $htmlVideos));
	unset($videos[count($videos)-1]);	// English Sub
// "Upcoming" is now "2011 Drama"
//	unset($videos[5]);	// Upcoming
	unset($videos[4]);	// Home
	unset($videos[3]);	// Download Center
	unset($videos[1]);	// Idol Dramas
	unset($videos[0]);	// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
