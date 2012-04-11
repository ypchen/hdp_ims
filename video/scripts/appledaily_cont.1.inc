<?php
	$link = $search = 'http://www.appledaily.com.tw/animation';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$html = str_between($html, '<nav class="mmvnv"', '</nav>');

	$videos = explode('<a id=', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
