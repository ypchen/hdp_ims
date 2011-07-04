<?php
	$link = $search = 'http://tw.nextmedia.com/animation/index/menusecid/1/ordertp/day';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = $search = 'http://tw.nextmedia.com' . trim(str_between($html, 'style="float:left" src="', '"'));
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$html = str_between($html, '<section class="upper_field fillup">', '</section>');

	$videos = explode('<a hr', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
