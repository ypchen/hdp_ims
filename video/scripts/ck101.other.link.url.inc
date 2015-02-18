<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '"viewLoginBox"') !== false) {
		// for comics
		$link = str_replace('v.ck101.com', 'mv.ck101.com', $link);
	}
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(
				str_replace('卡提諾影音', '',
					str_between($html, '<title>', '</title>'))
			);
	$title = convertUnicodePoints($title);

	$htmlToExplode = $html;
	$itemTotal = 0;
	$separators = array('<video ', '<div class="dm_keys"');
	foreach($separators as $separator) {
		if (strpos($htmlToExplode, $separator) !== false) {
			$videos = explode($separator, $htmlToExplode);
			unset($videos[0]);
			$videos = array_values($videos);

			$itemTotal = count($videos);
			break;
		}
	}
	include('05_check.base.inc');

	$links = array();
	$titles = array();

	$siteURLprefix = '';
	foreach($videos as $video) {
		if (strpos($video, '<source src="') !== false) {
			$link  = $siteURLprefix . trim(str_between($video, '<source src="', '"'));

			$titles[] = $title;
			$links[] = $link;
		}
		else if (strpos($video, '<div class="dm_types"') !== false) {
			// Daily Motion
			$ids = explode(',', trim(str_between($video, '">', '<')));
			foreach ($ids as $id) {
				$link =
					$localhostYoutubeVideo . '?query=site_dailymotion' .
						'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
						'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
						'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
						'&amp;link='       . urlencode('http://www.dailymotion.com/embed/video/' . $id);

				$titles[] = $title;
				$links[] = $link;
			}
		}
	}
	$itemTotal = count($links);
	include('05_check.base.inc');

	$iStart = intval($extra);
?>
