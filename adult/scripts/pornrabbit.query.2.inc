<?php
	$siteURLprefix = 'http://www.pornrabbit.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<h3>', '</h3>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<b>runtime:</b>', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<b>views:</b>', '</span>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, '<span class="uploadtimehome">', '</span>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
