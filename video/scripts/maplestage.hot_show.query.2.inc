<?php
	$siteURLprefix = 'http://maplestage.com';
	foreach($videos as $video) {

		$section = explode('<a class="', $video);

		$link  = $siteURLprefix . trim(str_between($section[1], '" href="', '"'));
		$title = trim(str_between($section[2], '">', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($section[1], '<img src="', '"'));
		$note   = array();
		$note[] = $caption_publish . ': ' .
					trim(str_between($section[2], ' timeago" title="', '"'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
