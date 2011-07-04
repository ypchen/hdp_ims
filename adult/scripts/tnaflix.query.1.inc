<?php
	$link = $search . '/most-recent/' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="pagination clear">', $html);

	$videos = explode('<div class="video" ', $htmlBody[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
