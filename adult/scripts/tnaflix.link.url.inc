<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link  = str_replace('&', '&amp;',
				urldecode(trim(str_between($html, 'flashvars.config = escape("', '");')))
			);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link  = trim(urldecode(str_between($html, '<videoLink>', '</videoLink>')));
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
