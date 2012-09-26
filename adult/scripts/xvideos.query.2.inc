<?php
	$siteURLprefix = 'http://www.xvideos.com';
	foreach($videos as $video) {

		if (strstr($video, '<script>') != FALSE) continue;

		$sections = explode('<p>', $video);

		$link  = $siteURLprefix . trim(str_between($sections[1], '<a href="', '"'));
		$title = trim(str_between($sections[1], '">', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($sections[0], '<img src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($sections[1], '<span class="duration">(', ')</span>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($sections[1], 'Porn quality: ', '</span>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
