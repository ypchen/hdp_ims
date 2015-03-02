<?php
	$link = $search = 'http://sugoideas.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('/a>', ($htmlToExplode = str_between($html, '">Home</a></li>', '</ul>')));
	unset($videos[count($videos)-1]);	// Suffix
	unset($videos[1]);					// Idol Dramas
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
