<?php
	$link = $search = 'http://www.keezmovies.com/categories';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('/a>', ($htmlToExplode = str_between($html, '<div class="catmenu_holder">', '<div class="clear">')));
	unset($videos[count($videos)-1]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
