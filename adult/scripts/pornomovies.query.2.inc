<?php
	$siteURLprefix = 'http://pornomovies.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
		$title = trim(str_between($video, ' alt="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'src="', '"'));
		$len    = trim(str_between($video, 'Length:',"</a>"));
		$len    = preg_replace("/(<\/?)(\w+)([^>]*>)/e","", $len);
		$view   = trim(str_between($video, 'Views:',"</a>"));
		$view   = preg_replace("/(<\/?)(\w+)([^>]*>)/e","", $view);
		$note   = array();
		$note[] = $caption_length . ': ' .
					$len;
		$note[] = $caption_view . ': ' .
					$view;
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, 'Added:', 'ago')) . ' 前';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
