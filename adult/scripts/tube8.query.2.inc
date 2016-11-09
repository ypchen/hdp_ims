<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div class="video_duration">', '</div>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, '<span class="float-left">', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<div class="video_views">', '</div>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
