<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

    $link = trim(str_between($html, 's1.addParam("flashvars","settings=', '"'));
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

    $link = trim(str_between($html, 'defaultVideo:', ';'));
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
