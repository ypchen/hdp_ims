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

	$verLayout = '';
	if (strpos($html, "<ul class='unstyled row-fluid'>") !== false) {
		$verLayout = 'v.2.1.8.5';
		// New format from v2.1.8.5
		$videos = explode('video"', ($htmlToExplode = str_between($html, "<ul class='unstyled row-fluid'>", '</ul>')));
	}
	else {
		$verLayout = 'v2.1.8.4';
		// Old format before v2.1.8.5
		$videos = explode('<section class="video clear', ($htmlToExplode = str_between($html, '<div class="videos clear', '<nav class="pagina')));
	}
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgWidth   = 20;
	$myImgHeight  = 40;
?>
