<?php
	$itemNo = intval($extra);

	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videoHtml = explode('<ul class="subMenu">', $html);
	$videos = explode('<li >', $videoHtml[1]);
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
