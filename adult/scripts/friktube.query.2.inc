<?php
	$siteURLprefix = 'http://www.friktube.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<span class="title">', '</span>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<br />views: ', '</span>'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
