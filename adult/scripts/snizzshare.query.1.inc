<?php
	$link = $search . $page . '.html?' . $extra;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, " class='next'>NEXT PAGE &raquo;</a>") === false)
		$pageMax = $page;

	$videos = explode('<!--- mianitura-->', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
