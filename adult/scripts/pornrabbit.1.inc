<?php
	$link = $search = 'http://www.pornrabbit.com/page/categories/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="cat">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
