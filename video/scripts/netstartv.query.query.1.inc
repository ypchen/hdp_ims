<?php
	if (strpos($search, '?') === false) {
		$link = $search . '?page=' . $page;
	}
	else {
		$link = $search . '&page=' . $page;
	}
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '>下一页 &raquo;</a>') === false)
		$pageMax = $page;
	else
		$pageMax = $page+1;

	$typeLayout = '';
	if (strpos($html, '<li class="grid-item col-xs-6 col-md-2">') !== false) {
		$typeLayout = '<li class="grid-item col-xs-6 col-md-2">';
		$videos = explode($typeLayout, ($htmlToExplode = $html));
	}
	else if (strpos($html, '<li class="grid-item col-md-2">') !== false) {
		$typeLayout = '<li class="grid-item col-md-2">';
		$videos = explode($typeLayout, ($htmlToExplode = $html));
	}
	else if (strpos($html, '<li class="col-md-6">') !== false) {
		$typeLayout = '<li class="col-md-6">';
		$videos = explode($typeLayout, ($htmlToExplode = $html));
	}
	else if (strpos($html, '<section class="video clearfix">') !== false) {
		$typeLayout = '<section class="video clearfix">';
		$videos = explode($typeLayout, ($htmlToExplode = $html));
	}
	else {
		$videos = array('Unknown format');
	}
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgWidth   = 20;
	$myImgHeight  = 40;
?>
