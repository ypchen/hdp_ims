<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '<nav class="page_switcher"') !== false)
		$pageStart = 1;
	else
		$pageStart = 0;

	$html = str_between($html, '<div class="subsections"', '</div>');
	if (strpos($html, '/type/day"') !== false) {
		$html = '<a href="/animation/">總覽</a>' . $html;
	}

	$videos = explode('<a hr', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
