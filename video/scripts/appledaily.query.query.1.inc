<?php
	$dataTotal  = 0;

	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$jq   = trim(str_between($html, 'jQuery.get(', ','));
	$jq   = str_replace("'+carousel.first+'", '1', $jq);
	$jq   = str_replace("'+carousel.last", '100', $jq);
	$jq   = str_replace("'", '', $jq);
	$link = $search = 'http://tw.nextmedia.com' . $jq;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$strToCheck = trim(str_between($html, '<total>', '</total>'));
	include('05_check.str.inc');

	$dataTotal = intval($strToCheck);
	if ($dataTotal > 0) {
		$videos = explode('<imgdata>', $html);
		unset($videos[0]);
		$videos = array_values($videos);

		$itemTotal = count($videos);
		include('05_check.base.inc');
	}
?>
