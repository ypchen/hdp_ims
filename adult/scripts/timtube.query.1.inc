<?php
	$link = $search . $page . '/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '<strong> &rarr;</strong>') !== false)
		$pageMax = $page;

	$videos = explode('<li class="video', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
