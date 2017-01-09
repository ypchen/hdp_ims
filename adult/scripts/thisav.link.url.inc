<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$mark = "so.addVariable('file','";
	if (strpos($html, $mark = "so.addVariable('file','") !== false) {
		$link = trim(urldecode(str_between($html, $mark, "'")));
	}
	elseif (strpos($html, $mark = 'file: "') !== false) {
		// Assuming the first presence of 'file: "' contains the video URL
		$link = trim(urldecode(str_between($html, $mark, '",')));
	}
	elseif (strpos($html, $mark = 'id="my-video"') !== false) {
		$parts = explode($mark, $html);
		$link = trim(urldecode(str_between($parts[1], $mark = ' src="', '"')));
	}
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
