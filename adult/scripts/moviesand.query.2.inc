<?php
	$siteURLprefix = 'http://www.moviesand.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '.html">', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ' src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div class="clip-time">', '</div>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, '<div class="clip-added">', '</div>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<div class="clip-views">views: ', '</div>'));
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
