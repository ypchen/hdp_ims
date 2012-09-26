<?php
	$iCount = 0;

	$siteURLprefix = 'http://www.appledaily.com.tw';
	foreach($videos as $video) {

		// Pass the same $link
		//$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<p>', '</p>'));
		$title = cleanFragments('/&#\d+/', convertUnicodePoints($title));
		// Pass the current item number
		$extra = strval($iCount);
		$iCount ++;

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<span>瀏覽人次:', '</span>'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
