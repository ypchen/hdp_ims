<?php
	$siteURLprefix = 'http://timtube.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'alt="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = $siteURLprefix . trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<span class="watermark duration label label-info">', '</span>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($video, 'class="addtime">', '<'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
