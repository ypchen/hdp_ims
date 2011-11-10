<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, ' alt="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ' src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div class="duration">', '</div>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<div class="views">', '<img style'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
