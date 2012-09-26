<?php
	$siteURLprefix = 'http://www.pornrabbit.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<h2>', '</h2>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'src="', '"'));
		if (strpos($image, '/processing.png') !== false) continue;

		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, 'runtime: <b>', '</b>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, 'views: <b>', '</b>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, '<span class="r"><b>', '</b>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
