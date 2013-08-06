<?php
	require('../../common/Aes.class.php');
	require('../../common/AesCtr.class.php');

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = '';
	$quality = array('"quality_480p":"', '"quality_240p":"', '"quality_180p":"');
	foreach ($quality as $q) {
		if (strpos($html, $q) !== false) {
			$link = urldecode(str_between($html, $q, '"'));
			break;
		}
	}

	$encrypted = urldecode(str_between($html, '"encrypted":', ','));
	if (strcmp($encrypted, 'true') == 0) {
		$key  = urldecode(str_between($html, '"video_title":"', '"'));
		$link = urldecode(AesCtr::decrypt($link, $key, 256));
	}

	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
