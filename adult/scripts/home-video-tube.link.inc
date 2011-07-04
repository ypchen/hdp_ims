<?php
	$link = str_replace(' ','%20',$link);
	$link = str_replace('[','%5B',$link);
	$link = str_replace(']','%5D',$link);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = str_between($html, 'to.addVariable("initexemel", "', '&');
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = str_between($html, '"FLVPath" Value="', '"');
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
