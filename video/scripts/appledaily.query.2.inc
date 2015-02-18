<?php
	$iCount = 0;

	$siteURLprefix = 'http://www.appledaily.com.tw';
	foreach($videos as $video) {
		// Pass the same $link
		$link  = $search;
		//$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
		$title = trim(str_between($video, '<h2>', '</h2>'));
		$title = cleanFragments('/&#\d+/', convertUnicodePoints($title));
		// Pass the current item number
		$extra = strval($iCount);
		$iCount ++;

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, '<div class="datetime">', '</div>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<span class="aneye">', '</span>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
