<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link  = str_replace('&', '&amp;',
				urldecode(trim(str_between($html, "so.addVariable('config', '", "');")))
			);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link  = trim(str_between($html, '<file>', '</file>'));
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
