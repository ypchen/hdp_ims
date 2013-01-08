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
		// YouTube ids
		$ids = explode(',', $idString);
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, 'http://www.youtube.com/embed/') !== false) {
		// YouTube ids
		$ids = array(trim(str_between($html, 'http://www.youtube.com/embed/', '?')));
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, 'data="http://static.youku.com/v') !== false) {
		// youku video
		$link = 'http://v.youku.com/player/getPlayList/VideoIDS/' . trim(str_between($html, 'VideoIDS=', '&'));
		// Get the JSON object
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$links = array();

		$youku_seed = trim(str_between($html, '"seed":', ','));
		foreach (array('mp4', 'flv') as $youku_format) {

			$youku_fileID = trim(str_between($html, '"' . $youku_format . '":"', '"'));
			if (strlen($youku_fileID) <= 0)
				continue;
			$youku_fileID_array = youku_getFileID($youku_fileID, $youku_seed);

			$youku_videos = trim(str_between($html, '"' . $youku_format . '":[', ']'));
			$videos = explode('},', $youku_videos);

			$url_sid = youku_getSid();

			foreach($videos as $video) {
				$seq_no  = sprintf('%02X', intval(trim(str_between($video, '"no":"', '"'))));
				$url_key = trim(str_between($video, '"k":"', '"'));
				$links[] = 'http://f.youku.com/player/getFlvPath/sid/' .
					$url_sid . '_' . $seq_no .
					'/st/flv/fileid/' .
					$youku_fileID_array[1] . $seq_no . $youku_fileID_array[3] .
					'?K=' . $url_key;
			}
		}

		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else if (strpos($html, 'http://www.dailymotion.com/embed/video/') !== false) {
		// Daily Motion
		$links = array();
		if (strlen($htmlToExplode = str_between($html, "'videoGroup'", '</div>')) > 0) {}
		else if (strlen($htmlToExplode = str_between($html, '"videoGroup"', '</div>')) > 0) {}
		else {
			$htmlToExplode = str_between($html, '<div class="node_body ', '</iframe></center>');
		}
		$videos = explode('<iframe ', $htmlToExplode);
		unset($videos[0]);
		$videos = array_values($videos);
		foreach($videos as $video) {
			$video_data = explode('?', trim(str_between($video, 'src="', '"')));
			$links[] = 
				$localhostYoutubeVideo . '?query=site_dailymotion' .
					'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
					'&amp;link='       . urlencode($video_data[0]);
		}

		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else if ((strpos($html, 'http://www-cdn.jtvnw.net/') !== false) ||
				(strpos($html, 'http://www-cdn.justin.tv/') !== false)) {
		// Justin TV
		$links = array();
		$videos = explode('<object ', ($htmlToExplode = str_between($html, '"node_body ', '</div>')));
		unset($videos[0]);
		$videos = array_values($videos);
		foreach($videos as $video) {
			$archive_id = trim(str_between($video, 'archive_id=', '"'));
			$link = 'http://api.justin.tv/api/broadcast/by_archive/' . $archive_id . '.xml';
			$html = yp_file_get_contents($link);
			include('05_check.file_contents.inc');

			$archives = explode('<archive>', ($htmlToExplode = $html));
			foreach($archives as $archive) {
				if (strpos($archive, "<id>$archive_id</id>") !== false) {
					$links[] = trim(str_between($archive, '<video_file_url>', '</video_file_url>'));
					break;
				}
			}
		}

		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else if (strpos($html, 'http://video.nexttv.com.tw/') !== false) {
		// Next TV
		$links = array('http://video.nexttv.com.tw/' . trim(urldecode(
					str_between(
						$htmlToExplode = str_between($html, '<div class="node_body ', '</center>'),
					'http://video.nexttv.com.tw/', '&quot;'))));
		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else if (strpos($html, '.letv.com') !== false) {
		// letv -- http://www.oschina.net/question/554530_61580
		$letv_id = trim(
					str_between(
						$htmlToExplode = str_between($html, '<div class="node_body ', '</center>'),
					'&amp;id=', '&amp;'));
		$link = 'http://app.letv.com/v.php?id=' . $letv_id;
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = str_replace('\/', '/', trim(str_between($html, '"url":"', '"')));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$links = array(
			str_replace('&', '&amp;', str_replace('\/', '/', trim(str_between($html, '"location": "', '"')))));
		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else if (count($videos = explode('value="fs=1&amp;', ($htmlToExplode = $html))) > 1) {
		// Direct youtube video url without id
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
	else if (strpos($html, ' flashvars="hl=zh_CN&amp;video_id=') !== false) {
		// YouTube ids
		$ids = array(trim(str_between($html, ' flashvars="hl=zh_CN&amp;video_id=', '"')));
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, ' flashvars="file=http%3A%2F%2F') !== false) {
		// Next TV / letv
		$links = array(trim(urldecode(
					str_between(
						$htmlToExplode = str_between($html, '<div class="node_body ', '</center>'),
					' flashvars="file=', '&amp;'))));
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
