<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="panel-heading"', ($htmlToExplode = $html));
	unset($videos[0]);	// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
