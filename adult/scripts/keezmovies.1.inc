<?php
	$link = $search = 'http://www.keezmovies.com/categories';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li class="capitalize relative"><span class="absolute layout-sprite" style="width:6px; height:6px; background-position:-52px 0; top:5px;"></span>', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
