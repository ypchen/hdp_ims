<?php
	ini_set('user_agent', $userAgent);

	$link = $search . '&page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$main_col_ary = explode('class="nf-videos">', $html);
	$main_col = $main_col_ary[2];
	$videos = explode('<li ', $main_col);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
