<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$html = str_between($html, '<div id="shw_lst"', '<div id="shw_txt"');

	$videos = explode('<div id="pic_play_list', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
