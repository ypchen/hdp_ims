<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = urldecode(trim(str_between($html, '"video_url":"', '"')));
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
