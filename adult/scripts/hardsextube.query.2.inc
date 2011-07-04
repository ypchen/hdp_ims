<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<b>', '</b>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'style=\'vertical-align:top;\' src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div style="float:right;text-align: right; width:100%;">', '<br>'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
