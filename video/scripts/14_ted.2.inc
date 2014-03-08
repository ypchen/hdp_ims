<?php
	$siteURLprefix = 'http://www.ted.com';
	$titleSep = " lang='" . $extra . "'>";
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, " href='", "'"));
		$title = trim(str_between($video, $titleSep, '</a>'));
		$title = convertUnicodePoints($title);
		// pass $extra to the next level
//		$extra = '';

		$images = explode('<img', $video);
		$image  = trim(str_between($images[1], ' src="', '"'));
		$dataA  = explode("<span class='meta__item'>", $video);
		$note   = array();
		$note[] = convertUnicodePoints(trim(str_between($video, "talk-link__speaker'>", '</')));
		$note[] = $caption_length . ': ' .
					trim(str_between($video, 'thumb__duration">', '</'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[2], "meta__val'>", '</'));
		$note[] = $caption_view . ': ' .
					trim(str_between($dataA[1], "meta__val'>", 'views'));

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
