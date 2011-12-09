<?php
	$siteURLprefix = 'http://www.ted.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
		$title = trim(str_between($video, '<a title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$images = explode('<img', $video);
		$playType = (strpos($images[1], 'botw') !== false)  ?
					'.onYTV' : '.onTED';
		$image  = trim(str_between($images[2], ' src="', '"'));
		$dataA  = explode(' ', str_between($video, 'class="date">', '<'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim($dataA[0]);
/*
		if (strpos($video, 'Views: <strong>') !== false) {
			$note[] = $caption_view . ': ' .
						trim(str_between($video, 'Views: <strong>', '</strong>'));
		}
*/
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, 'first">', '</span>')) .
					' ' .
					trim(str_between($video, 'last">', '</span>'));
		$note[] = $caption_publish . ': ' .
					trim($dataA[2]) . ' ' . trim($dataA[3]);
		$note[] = (strcmp($playType, '.onYTV') == 0) ?
					'※ 置於 YouTube (通常無字幕)' : '';

		$clickPlay = 'no';
		$linkLevel = $playType . '.link';
		include('04_query.items.link.inc');
	}
?>
