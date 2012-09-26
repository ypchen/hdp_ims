<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$sections = explode('<div class="video_name">', $video);

		$link  = $siteURLprefix . trim(str_between($sections[1], '<a href="', '"'));
		$title = trim(str_between($sections[1], '">', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($sections[0], '<img src="', '"'));
		$note   = array();
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, '<div class="video_timestamp">', '</div>'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
