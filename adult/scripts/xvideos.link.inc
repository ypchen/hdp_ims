<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$t1 = explode('flv_url=', $html);
	$t2 = explode('&amp;', $t1[1]);
	$link = trim(urldecode($t2[0]));
/*
	$link = str_replace('%26','&',$link);
	$link = str_replace('%3A',':',$link);
	$link = str_replace('%3B',';',$link);
	$link = str_replace('%2F','/',$link);
	$link = str_replace('%3F','?',$link);
	$link = str_replace('%3D','=',$link);
*/
	$link = str_replace('&','&amp;',$link);
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
