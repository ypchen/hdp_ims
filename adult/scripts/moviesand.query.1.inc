<?php
	$link = $search . $page . '.html';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$clipNav = trim(str_between($html, '<div class="clip-navigation">', '</div>'));
	$pages = explode('<span class="page-link">', $clipNav);
	if (is_numeric(substr($pages[count($pages)-1], 0, 1)))
		$pageMax = $page;

	$videos = explode('<div class="clip-title">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
