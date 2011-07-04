<?php
	$link = 'http://www.youtube.com/playlist?p=' . $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('id="vpl-videos-list"', $html);

	$videos = explode('<div class="vpl-thumb">', $htmlBody[1]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
