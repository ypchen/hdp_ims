<?php
	require('../../common/Aes.class.php');
	require('../../common/AesCtr.class.php');

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(urldecode(str_between($html, '&amp;video_url=', '&amp;')));

	$encrypted = trim(urldecode(str_between($html, '&amp;encrypted=', '"')));
	if (strcmp($encrypted, 'true') == 0) {
		$key  = trim(urldecode(str_between($html, '&amp;video_title=', '&amp;')));
		$link = trim(urldecode(AesCtr::decrypt($link, $key, 256)));
	}

	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
