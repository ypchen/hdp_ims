<?php
	$link = $search = 'http://www.hardsextube.com/categories/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<li>',
		($htmlToExplode = str_between($html, '<ul class="subnav" id="categories">', '</ul>')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

//	$myImgHeight  = 35;
?>
