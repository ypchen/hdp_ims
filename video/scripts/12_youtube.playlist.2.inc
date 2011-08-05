<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="/watch?v=', '&amp;'));
		$title = trim(str_between($video, '<span class="title video-title">', '</span>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		if (strpos($video, ' data-thumb="') !== false) {
			$image  = 'http:' . trim(str_between($video, ' data-thumb="', '"'));
		}
		else {
			$image  = 'http:' . trim(str_between($video, '<img src="', '"'));
		}
		$note   = array();
		$note[] = $caption_length . '：' .
					trim(str_between($video, '<span class="video-time">', '</span>'));
		$note[] = $caption_view . '：' .
					trim(str_between(
						str_between(
							$video,
							'<span class="video-view-count">',
							'</span>'),
						'<strong>',
						'</strong>'));
		$note[] = trim(str_between($video, '<span class="video-owner">', '</span>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
