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
		$ids = array();
		$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));
		include('05_check.link.idcount.inc');
	}
	else {
		// maplestage new format -- direct youtube video url without id
		$htmlBody = explode('<div class="node_body">', $html);

		$videos = explode('<param name="flashvars"', $htmlBody[1]);
		if (count($videos) > 1) {
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
			// clear-text youtube url(s) not found
			// No solution for the time being
			$ids = array();
			include('05_check.link.idcount.inc');
		}
	}
?>
