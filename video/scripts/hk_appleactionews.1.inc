<?php
	$link = $search = 'http://hk.dv.nextmedia.com/template/dv_channel/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$html = str_between($html, '<div class="dv_20052010"', '</div>');

	$videos = explode('<a hr', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
