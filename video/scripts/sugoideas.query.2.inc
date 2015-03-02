<?php
	$siteURLprefix = '';
	foreach($videos as $video) {
		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ' src="', '"'));
		$note   = array();
		$infoArray = explode('<br />', $video);
		$note[] = trim(strip_tags($infoArray[2]));
		$note[] = trim(strip_tags(str_between($infoArray[3], '<strong>', '</div>')));
		$note[] = '';
		$note[] = '';

		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
