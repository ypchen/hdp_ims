<?php
	$html = yp_file_get_contents($link = $search);
	include('05_check.file_contents.inc');

	$videos = explode('iv>', ($htmlToExplode = trim(str_between($html, '<div class="listing-block', '<div class="sidebar'))));
	//unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
