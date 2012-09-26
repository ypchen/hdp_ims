<?php
	require('../../common/Aes.class.php');
	require('../../common/AesCtr.class.php');

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(str_replace('\/', '/', str_between($html, '"video_url":"', '"')));

	$encrypted = trim(str_between($html, '"encrypted":', '}'));
	if (strcmp($encrypted, 'true') == 0) {
		$key  = trim(str_replace('\/', '/', str_between($html, '"video_title":"', '"')));
		$link = trim(urldecode(AesCtr::decrypt($link, $key, 256)));
	}

	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
