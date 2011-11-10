<?php
	$link = $search = 'http://www.pornhub.com/categories';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li class="cat_pic">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgWidth   = 30;
	$myImgHeight  = 40;
?>
