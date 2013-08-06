<?php
	$siteURLprefix = 'http://www.ted.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
		$title = trim(str_between($video, '<a title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$images = explode('<img', $video);
		$image  = trim(str_between($images[1], ' src="', '"'));
		$dataA  = explode('class="notranslate"', $video);
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($dataA[2], '>', '</'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[2], 'Posted:', '<span')) . ' ' .
					trim(str_between($dataA[3], '>', '</'));
		if (count($dataA) > 4) {
			$note[] = $caption_view . ': ' .
						trim(str_between($dataA[4], '>', '</'));
		}

		$clickPlay = 'no';
		// Assume that there is no .onYTV any more
		$linkLevel = '.onTED.link';
		include('04_query.items.link.inc');
	}
?>
