<?php
	// For maplestage
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(
				str_replace('- MapleStage', '',
					str_between($html, '<title>', '</title>'))
			);
	$title = convertUnicodePoints($title);

	if (strlen($idString = trim(str_between($html, '<div class="video_ids">', '</div>'))) > 0) {
		$ids = explode(',', $idString);
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, 'http://www.youtube.com/embed/') !== false) {
		$ids = array(trim(str_between($html, 'http://www.youtube.com/embed/', '?')));
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, ' flashvars="hl=zh_CN&amp;video_id=') !== false) {
		$ids = array(trim(str_between($html, ' flashvars="hl=zh_CN&amp;video_id=', '"')));
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, 'http://www.dailymotion.com/embed/video/') !== false) {
		$links = array();
		$video_group = str_between($html, '"videoGroup"', '</div>');
		$videos = explode('<iframe', $video_group);
		unset($videos[0]);
		$videos = array_values($videos);
		foreach($videos as $video) {
			$video_data = explode('?', trim(str_between($video, 'src="', '"')));
			$links[] = 
				$localhostYoutubeVideo . '?query=site_dailymotion' .
					'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
					'&amp;link='       . urlencode($video_data[0]);
		}
	}
	else if (count($videos = explode('value="fs=1&amp;', $html)) > 1) {
		// maplestage new format -- direct youtube video url without id
		unset($videos[0]);
		$videos = array_values($videos);

		$links = array();
		$extraInfo = array();
		foreach($videos as $video) {
			$fmt_stream_map = urldecode(trim(str_between($video, 'fmt_stream_map=', '&amp;')));
			$fmt_streams = explode(',', $fmt_stream_map);
			// For now, just use the first stream (usually the highest resolution)
			$streamOne = explode('|', $fmt_streams[0]);
			$links[] = str_replace('&', '&amp;', $streamOne[1]);

			$fmt_list = urldecode(trim(str_between($video, 'fmt_list=', '&amp;')));
			$fmts = explode(',', $fmt_list);
			// For now, just use the first stream (usually the highest resolution)
			$extraInfo[] = $fmts[0];
		}

		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else {
		// Clear-text youtube url(s) not found
		// Unknown maplestage format
		$ids = array();
		include('05_check.link.idcount.inc');
	}
?>
