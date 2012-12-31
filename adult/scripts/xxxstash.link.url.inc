<?php
	// Quick fix
	$link = str_replace(' ', '%20', $link);
	$link = str_replace('&', '%26', $link);
	$link = str_replace('[', '%5B', $link);
	$link = str_replace(']', '%5D', $link);
	$link = str_replace('{', '%7B', $link);
	$link = str_replace('}', '%7D', $link);

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(urldecode(str_between($html, "'file': '", "',")));

	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
