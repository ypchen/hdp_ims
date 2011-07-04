<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

    $link = urldecode(str_between($html, "so.addVariable('file','", "'"));
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
