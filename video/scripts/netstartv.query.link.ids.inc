<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(str_between($html, '<title>', '</title>'));
	$title = convertUnicodePoints($title);

	$playlist = json_decode($playlistString = ('[' . trim(str_between($html, 'var playlist = [', '];')) . ']'));
	$ids = array();
	$titles = array();
	$i = 0;
	foreach ($playlist as $item) {
		$i ++;
		$item_title = $item[0];
		if ((is_numeric($item_title)) && (intval($item_title) == $i)) {
			$titles[] = $title . ' 第 ' . $item_title . ' 段/集';
		}
		else {
			$titles[] = $item_title;
		}
		$ids[] = $item[1];
	}

	$srcPrefix = 'P2PR-';
	if (strpos($html, 'youtube_progress_') !== false) {
		// YouTube ids
		$src = 'YouTube';
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, 'dm_progress_') !== false) {
		// Dailymotion ids
		$src = 'Dailymotion';
		$links = array();
		foreach($ids as $id) {
			$links[] =
				$localhostYoutubeVideo . '?query=site_dailymotion' .
					'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
					'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
					'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
					'&amp;actual_src=' . urlencode($srcPrefix . $src) .
					'&amp;link='       . urlencode('http://www.dailymotion.com/embed/video/' . $id);
		}
		unset($ids);
		unset($title);
		$itemTotal = count($links);
		include('05_check.base.inc');
	}
?>
