<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$ids = array(trim(str_between($html, 'http://www.youtube.com/v/', '&')));
	include('05_check.link.idcount.inc');

	$title = $title_03_play;
?>
