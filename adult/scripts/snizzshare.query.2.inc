<?php
	$siteURLprefix = 'http://www.snizzshare.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<div id="min"><a href="', '?PHPSESSID'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = 'confirm_dob=1';

		$image  = trim(str_between($video, '<img src="', '"'));
		$dataA  = explode('<td', $video);
		$note   = array();
		$note[] = $caption_view . ': ' .
					trim(str_between($dataA[4], '>', ' views</td>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[3], '>', ' ago</td>')) . ' 前';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
