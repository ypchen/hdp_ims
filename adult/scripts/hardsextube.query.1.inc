<?php
	$link = str_replace(' ', '+', $search . '/Relevance/' . ($page-1));
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$pageNav = trim(str_between($html, "<div id='pagesel'>", '</div>'));
	$pages = explode('npages', $pageNav);
	$pageNow = ' npages_active';
	if (strncmp($pages[count($pages)-1], $pageNow, strlen($pageNow)) == 0)
		$pageMax = $page;

	$htmlBody = explode('<div class="pagination', $html);

	$videos = explode('<li class="normal_li', $htmlBody[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
