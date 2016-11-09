<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$mark = "so.addVariable('file','";
	if (strpos($html, $mark) !== false) {
		$link = trim(urldecode(str_between($html, $mark, "'")));
	}
	else { 
		// Assuming the first presence of 'file: "' contains the video URL
		$link = trim(urldecode(str_between($html, 'file: "', '",')));
	}
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
