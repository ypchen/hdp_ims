<?php
	$link = $search = 'http://www.myjizztube.com/channels.php';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="video-thumb"', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$myImgHeight  = 50;
?>
