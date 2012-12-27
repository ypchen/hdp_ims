<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	// Not working as on Dec 28, 2012
	// Temporarily removed from the list
	$link =
		trim(urldecode(str_between($html, 'flvserver: "', '"'))) .
		trim(urldecode(str_between($html, 'flv: "', '?'))) . 
		'?mp4mod=1&start=0';
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
