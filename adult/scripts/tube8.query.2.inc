<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ' src="', '"'));
		$dataA  = explode('<div class="video-cont-wrapper">', $video);
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<strong>', '</strong>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, 'style="padding:2px 0 0 0; color:green;">', '</div>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($dataA[2], '<div class="video-right-text float-right">', ' views</div>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[3], '<div class="video-right-text float-right">', '</div>'));

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
