<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

    $link = trim(urldecode(str_between($html, 's1.addParam("flashvars","file=', '&')));
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
