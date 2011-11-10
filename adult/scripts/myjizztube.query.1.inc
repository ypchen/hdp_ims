<?php
	$link = $search . $page . '.html';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '>Next &raquo;</a>') === false)
		$pageMax = $page;

	$videos = explode('<div class="content"', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
