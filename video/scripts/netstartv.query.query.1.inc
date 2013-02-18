<?php
	$link = $search . '?page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '>下一页 &raquo;</a>') === false)
		$pageMax = $page;
	else
		$pageMax = $page+1;

	$videos = explode('<section class="video clear', ($htmlToExplode = str_between($html, '<div class="videos clear', '<nav class="pagina')));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgWidth   = 18;
	$myImgHeight  = 40;
?>
