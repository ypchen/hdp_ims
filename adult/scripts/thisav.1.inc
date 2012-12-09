<?php
	$link = $search = 'http://www.thisav.com/categories';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlMain = explode('id="content">', $html);
	$htmlMainTail = explode('<noscript>', $htmlMain[1]);

	$videos = explode('class="btopl">', ($htmlToExplode = $htmlMainTail[0]));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
