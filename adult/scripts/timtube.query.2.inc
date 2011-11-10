<?php
	$siteURLprefix = 'http://www.timtube.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<h4><a href="', '"'));
		$title = trim(
			str_replace('&nbsp;', ' ',
				str_replace('<br />', ' ', str_between($video, 'onClick="traffic();">', '</a>'))
			)
		);
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ';" src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<span style="color:#FFFFFF">', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<td align="right">', ' Hits'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
