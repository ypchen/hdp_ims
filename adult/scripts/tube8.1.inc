<?php
	$link = $search = 'http://www.tube8.com/categories.html';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="title-bar">', ($htmlToExplode = $html));
	unset($videos[0]);
	unset($videos[1]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
