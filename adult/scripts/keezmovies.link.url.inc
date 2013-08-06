<?php
	require('../../common/Aes.class.php');
	require('../../common/AesCtr.class.php');

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$separators = array(
		// keezmovies
		array('&amp;video_url=', '',
				false,
				array('&amp;video_url='), '&amp;',
				'&amp;encrypted=', '"',
				'&amp;video_title=', '&amp;'),
		// pornhub
		array('http://www.pornhub.com/view_video.php?viewkey=', '"',
				true,
				array('"quality_480p":"', '"quality_240p":"', '"quality_180p":"'), '"',
				'"encrypted":', ',',
				'"video_title":"', '"')
	);

	foreach ($separators as $separator) {
		if (strpos($html, $separator[0]) !== false) {

			if ($separator[2]) {
				// $separator[2]: need to reload the html
				$link = $separator[0] . trim(str_between($html, $separator[0], $separator[1]));
				$html = yp_file_get_contents($link);
				include('05_check.file_contents.inc');
			}

			$link = '';
			foreach ($separator[3] as $q) {
				if (strpos($html, $q) !== false) {
					$link = urldecode(str_between($html, $q, $separator[4]));
					break;
				}
			}

			$encrypted = urldecode(str_between($html, $separator[5], $separator[6]));
			if (strcmp($encrypted, 'true') == 0) {
				$key  = urldecode(str_between($html, $separator[7], $separator[8]));
				$link = urldecode(AesCtr::decrypt($link, $key, 256));
			}

			break;
		}
	}

	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
