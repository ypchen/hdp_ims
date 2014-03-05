<?php
	$siteURLprefix = 'http://www.maplestage.com';
	foreach($videos as $video) {

		$link  = trim(str_between($video, ' href="', '"'));
		if (strpos($link, 'http://') === false)
			$link = $siteURLprefix . $link;
		$title = trim(str_between($video, '">', '</'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = '';
		$note   = array();
		$note[] = '';
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
