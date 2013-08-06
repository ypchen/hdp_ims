<?php
	$link = $search . $page . '.html';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$clipNav = trim(str_between($html, '<ul class="pagination">', '</ul>'));
	if (strpos($clipNav, '<span>End</span>') !== false)
		$pageMax = $page;

	$videos = explode('<div class="video">', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
