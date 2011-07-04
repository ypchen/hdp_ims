<?php
	$siteURLprefix = 'http://www.pornmehorny.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = $siteURLprefix . trim(str_between($video, '<img src="', '"'));
		$dataA  = explode('<div class="box_left">', $video);
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div class="box_left">', '<br />'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[1], '<br />', '</div>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($dataA[1], '<div class="clear_right"></div>', ' views'));
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
