<?php
	$siteURLprefix = 'http://tw.nextmedia.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<h2>', '</h2>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_view . ': ' .
					str_between(trim(str_between($video, '</h2>', '/a>')), ':', '<');
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
