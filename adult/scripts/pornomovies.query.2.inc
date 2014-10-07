<?php
	$siteURLprefix = 'http://www.pornomovies.com';
	foreach($videos as $video) {

		$h3    = str_between($video, '<h3>', '</h3>');
		$p     = str_between($video, '<p', '</p>');

		$link  = $siteURLprefix . trim(str_between($h3, '<a href="', '"'));
		$title = trim(str_between($h3, '">', '</a>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$len    = trim(str_between($video, '<span class="duration">', '</span>'));
		$len    = preg_replace("/(<\/?)(\w+)([^>]*>)/e","", $len);
		$view   = trim(str_between($p, 'with', 'views'));
		$view   = preg_replace("/(<\/?)(\w+)([^>]*>)/e","", $view);
		$note   = array();
		$note[] = $caption_length . ': ' .
					$len;
		$note[] = $caption_view . ': ' .
					$view;
		$note[] = $caption_publish . ': ' .
					trim(str_between($p, '>', 'with'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
