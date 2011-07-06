<?php
	$link = $search = 'http://tw.nextmedia.com/animation/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$html = str_between($html, '<div class="mainsections"', '</div>');

	$videos = explode('<a hr', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
