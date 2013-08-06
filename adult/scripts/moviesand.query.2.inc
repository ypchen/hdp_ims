<?php
	$siteURLprefix = 'http://www.moviesand.com';
	foreach($videos as $video) {

		$data  = explode('<h3>', $video);
		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($data[1], '">', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<span class="duration">', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between(str_between($data[1], '<p>', '</p>'), 'with ', ' view'));
		$note[] = $caption_publish . ': ' .
					trim(str_between(str_between($data[1], '<p>', '</p>'), 'on ', ' with'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
