<?php
	// For sugoideas
	$link = str_replace('http://sugoitw.sugoideas.com/', 'http://tw.sugoitw.com/', $link);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$ts = explode('|', str_between($html, '<title>', '</title>'));
	$title = trim($ts[0]);
	$title = convertUnicodePoints($title);

	// This one, i.e., Part 1
	if (strpos($html, 'http://www.youtube.com/embed/') !== false) {
		$ids = array();
		$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));

		$videoList = explode('<li>', trim(str_between($html, '<ul class="contentlist">', '</ul>')));
		unset($videoList[1]);	// This one, i.e., Part 1, no link
		unset($videoList[0]);	// Prefix
		foreach ($videoList as $v) {
			$link = trim(str_between($v, ' href="', '"'));
			if (strlen($link) > 0) {
				$link = str_replace('http://sugoitw.sugoideas.com/', 'http://tw.sugoitw.com/', $link);
				$html = yp_file_get_contents($link);
				include('05_check.file_contents.inc');

				$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));
			}
		}
		include('05_check.link.idcount.inc');
	}
	else if (strpos($html, 'http://www.dailymotion.com/embed/video/') !== false) {
		$links = array();
		$video_group = str_between($html, ' class="videodiv"', ' id="dltip"');
		$videos = explode('<iframe ', $video_group);
		unset($videos[0]);
		$videos = array_values($videos);
		foreach($videos as $video) {
			$video_data = explode('?', trim(str_between($video, ' src="', '"')));
			$links[] = 
				$localhostYoutubeVideo . '?query=site_dailymotion' .
					'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
					'&amp;link='       . urlencode($video_data[0]);
		}
	}
	else {
		// Clear-text youtube url(s) not found
		// Unknown sugoideas format
		$ids = array();
		include('05_check.link.idcount.inc');
	}
?>
