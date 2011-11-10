<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '" href="', '"'));
		$title = trim(str_between($video, '<a title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'class="video-thumb" src="', '"'));
		$dataA  = explode('<div ', $video);
		$index  = 3;
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($dataA[$index+0], 'class="video-item-info">', '</div>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($dataA[$index+3], 'class="video-item-info-right">', ' Views</div>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[$index+1], 'class="video-item-info-right">', '</div>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
