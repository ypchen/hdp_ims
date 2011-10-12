<?php
	$link = $search = 'http://video.ck101.com';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlVideos = str_between($html, '<div class="menu"', '</div>');

	$videos = explode('</a></li>', $htmlVideos);
	unset($videos[count($videos)-1]);	// Suffix
	unset($videos[count($videos)-1]);	// 其他
	unset($videos[count($videos)-1]);	// 成人短片
	unset($videos[count($videos)-1]);	// 成人影片
	unset($videos[count($videos)-1]);	// 成人動漫
	unset($videos[0]);	// Prefix + 首頁
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
