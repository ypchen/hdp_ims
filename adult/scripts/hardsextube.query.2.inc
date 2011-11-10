<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, "<a href='", "'"));
		$title = trim(str_between($video, "title='", "'"));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, "src='", "'"));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, ' class="duration_text">', '</span>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, 'Rating: ', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, ' class="views_text">', '</span>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, ' class="daysold">', '</span>'));

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
