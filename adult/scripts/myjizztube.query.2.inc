<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '" alt="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = str_replace(' ', '%20', trim(str_between($video, '<img src="', '"')));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div class="time"><b>', '</b>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<div class="views"><b>', '</b>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
