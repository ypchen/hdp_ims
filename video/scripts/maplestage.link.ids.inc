<?php
	// For maplestage
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(str_between($html, '<h3>', '</h3>'));
	$title = convertUnicodePoints($title);

	if (strlen($base64 = trim(str_between($html, ' data-data="', '"'))) > 0) {
		// Contributed by absentfriend@HDPFans
		$json = base64_decode(strrev($base64));
		$res = json_decode($json, true);
		$src = $res['source'];
	}
	else {
		$src = 'Unknown';
		$ids = array();
	}

	switch ($src) {

		case 'Youtube':
		case 'YoutubeBypass':
			$ids = $res['ids'];
			include('05_check.link.idcount.inc');
			break;

		case 'Dailymotion':
			$links = array();
			foreach($res['ids'] as $id) {
				$links[] =
					$localhostYoutubeVideo . '?query=site_dailymotion' .
						'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
						'&amp;link='       . urlencode('http://www.dailymotion.com/embed/video/' . $id);
			}

			$itemTotal = count($links);
			include('05_check.base.inc');
			break;

		case 'VideoGroup':
			$links = array();
			foreach($res['elements'] as $element) {
				$links[] = str_replace('\/', '/', trim(str_between($element, 'src=\"', '\"')));
			}

			$itemTotal = count($links);
			include('05_check.base.inc');
			break;

		default:
				// Clear-text youtube url(s) not found
				// Unknown maplestage format
				include('05_check.link.idcount.inc');
			break;

	}
?>
