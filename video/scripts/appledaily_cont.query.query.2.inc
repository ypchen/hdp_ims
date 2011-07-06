<?php
	$iCount = 0;

	$siteURLprefix = 'http://tw.nextmedia.com';
	foreach($videos as $video) {

		// Pass the same $link
		//$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<h2>', '</h2>'));
		$title = convertUnicodePoints($title);
		// Pass the current item number
		$extra = strval($iCount);
		$iCount ++;

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_view . ': ' .
					str_between(trim(str_between($video, '</h2>', '/a>')), ':', '<');
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
