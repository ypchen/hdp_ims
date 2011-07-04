<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<div id="loading_', '">'));
		$title = trim(str_between($video, '" />', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = 'http://thumbs.tjoob.com' . trim(str_between($video, '<img src="http://thumbs.tjoob.com', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, 'Video Duration: <strong>', '</strong>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, 'Video views: <strong>', '</strong>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
