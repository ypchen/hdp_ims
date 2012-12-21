<?php
	$itemNo = intval($extra);

	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videoHtml = explode('', $html);
	$videos = explode('<a href="/channel', ($htmlToExplode = trim(str_between($html, '<div class="mediaNav">', '</div>'))));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
