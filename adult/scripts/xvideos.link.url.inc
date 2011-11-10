<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$t1 = explode('flv_url=', $html);
	$t2 = explode('&amp;', $t1[1]);
	$link = trim(urldecode($t2[0]));
	$link = str_replace('&','&amp;',$link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
