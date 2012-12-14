<?php
	$link = $search = 'http://www.appledaily.com.tw/animation';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<a id=', ($htmlToExplode = str_between($html, '<nav class="mmvnv"', '</nav>')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
