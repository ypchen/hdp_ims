<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(urldecode(str_between($html, 'flvpathValue: "', '"')));
	$link = str_replace('_@?_nva',  '&nva',  $link);
	$link = str_replace('_@?_hash', '&hash', $link);
	$link = str_replace('&',        '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
