<?php
	if ($page == 1)
		$link = $search;
	else
		$link = $search . '?page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '<li class="next" id="paginator_next">') === false)
		$pageMax = $page;

	$videos = explode('<li class="videoblock float-left" id=', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
