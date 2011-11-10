<?php
	$link = str_replace(' ', '%20', $search . '/' . $page);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$pageNav = trim(str_between($html, ' class="pagenav">', '</td>'));
	$pages = explode('</a>', $pageNav);
	if (is_numeric(substr(trim($pages[count($pages)-1]), 0, 1)))
		$pageMax = $page;

	$videos = explode('<div style="overflow:hidden;width:220px;">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
