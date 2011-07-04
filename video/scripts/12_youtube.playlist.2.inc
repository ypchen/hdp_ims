<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="/watch?v=', '&amp;'));
		$title = trim(str_between($video, '<a title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = 'http:' . trim(str_between($video, '<img data-thumb="', '"'));
		$note   = array();
		$note[] = $caption_length . '：' .
					trim(str_between($video, '<span class="video-time">', '</span>'));
		$note[] = trim(str_between($video, '<span class="vpl-videos-list-info-views">', '</span>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
