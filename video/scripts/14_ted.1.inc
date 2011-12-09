<?php
	$link = $search . '?lang=' . $extra . '&page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '">Next &raquo;</a>') === false)
		$pageMax = $page;

	$videos = explode('<dl class="talk', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
