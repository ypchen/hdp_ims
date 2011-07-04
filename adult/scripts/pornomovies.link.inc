<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = str_between($html, 's1.addVariable("file","', '"');
	$link = "http://pornomovies.com" . $link;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = str_between($html, '<location>', '<');
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
