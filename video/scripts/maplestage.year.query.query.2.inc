<?php
	$siteURLprefix = 'http://maplestage.com';
	foreach($videos as $video) {

		$link = $siteURLprefix . $video['href'];
		$title = convertUnicodePoints($video['title']);
		// Keep $extra (i.e., slug)
		//$extra = '';

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
