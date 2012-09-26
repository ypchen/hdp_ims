<?php
	$siteURLprefix = '';
	foreach($videos as $video) {
		$title = trim(str_between($video, ')">', '</a>'));
		$title = cleanFragments('/&#\d+/', convertUnicodePoints(strip_tags($title)));
		$data  = '';
		$link  = str_replace("'", '', str_replace(',', '|', trim(str_between($video, 'ef="', '"'))));
		$image = '';
		$note  = '';
		$extra = '';

		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
