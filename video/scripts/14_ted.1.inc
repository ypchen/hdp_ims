<?php
	// $extra is the language parameter
	$link = $search . '?language=' . $extra . '&sort=newest&page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, 'disabled">Next</') !== false)
		$pageMax = $page;

	$videos = explode("<div class='talk-link'>", ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
