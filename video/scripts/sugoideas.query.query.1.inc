<?php
	include('15_3_columns.inc');

	$link = $search . '?lcp_page0=' . strval($page);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, "class='lcp_paginator'>") === false)
		$pageMax = 1;
	else if (strpos($html, '>>></a>') === false)
		$pageMax = $page;

	$videos = explode('<li>', ($htmlToExplode = str_between($html, '_episode">', '</div>')));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
