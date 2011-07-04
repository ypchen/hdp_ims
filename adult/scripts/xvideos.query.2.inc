<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		if (strstr($video, '<script>') != FALSE) continue;

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'style="text-decoration:underline;">', '</span>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<strong>(', ')</strong>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, 'Porn quality: ', '</td>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
