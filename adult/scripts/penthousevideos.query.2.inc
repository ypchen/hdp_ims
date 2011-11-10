<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'alt="', '"'));
		$title = convertUnicodePoints($title);
		$extra = 'confirm_dob=1';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, 'Time: ', '</td>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, 'Uploaded: ', '</td>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
