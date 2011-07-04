<?php
	$siteURLprefix = 'http://tw.nextmedia.com';
	foreach($videos as $video) {
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$data  = '';
		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$image = '';
		$note  = '';
		$extra = '';

		$pageStart = 0;
		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
