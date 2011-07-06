<?php
	$siteURLprefix = 'http://tw.nextmedia.com';
	foreach($videos as $video) {
		$title = trim(str_between($video, '>', '</a>'));
		$title = convertUnicodePoints($title);
		$data  = '';
		$link  = $siteURLprefix . trim(str_between($video, 'ef="', '"'));
		$image = '';
		$note  = '';
		$extra = '';

		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
