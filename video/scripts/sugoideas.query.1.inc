<?php
	$link = $search . 'page/' . strval($page) . '/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, "'wp-pagenavi'") === false)
		$pageMax = 1;
	else if (strpos($html, '">&raquo;<') === false)
		$pageMax = $page;

	$videos = explode('<div class="upcomingad"', ($htmlToExplode = $html));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
