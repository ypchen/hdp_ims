<?php
	$link = $search = 'http://www.appledaily.com.tw/animation';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li ',
		($htmlToExplode = str_between($html, '<h2 class="an-tab-tit">動新聞</h2>', '<h2 class="an-tab-tit">')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
