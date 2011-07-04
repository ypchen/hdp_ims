<?php
	$link = $search = 'http://www.snizzshare.com/channels.php?confirm_dob=1';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<h2><a h', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
