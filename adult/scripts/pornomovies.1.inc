<?php
	$myImgHeight  = 15;

	$link = $search = 'http://pornomovies.com/channel/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlMain = explode('channel_02.gif', $html);
	$htmlMainTail = explode('<br /><center>', $htmlMain[1]);

	$videos = explode('<td style=', ($htmlToExplode = $htmlMainTail[0]));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
