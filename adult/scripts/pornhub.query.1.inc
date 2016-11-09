<?php
	ini_set('user_agent', $userAgent);

	$link = $search . '&page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '<li class="page_next">') === false)
		$pageMax = $page;

	$videos = explode('<li class="videoblock', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
