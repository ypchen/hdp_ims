<?php
	$link = $search = 'http://www.pornomovies.com/channel/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlMain = explode(' id="videosgrid"', $html);

	$videos = explode('<div class="video"', ($htmlToExplode = $htmlMain[1]));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
