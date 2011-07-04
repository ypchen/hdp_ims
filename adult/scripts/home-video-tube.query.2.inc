<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, '<h2 style="text-transform:capitalize">', '</h2>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img class="moduleFeaturedThumb" src="', '"'));
		$dataA  = explode('div id="left_box_item_text_left_tb">', $video);
		$dataB  = explode('<p', $dataA[1]);
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($dataB[1], '>', '</p>'));
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataB[2], '>', ' ago')) .	' 前';
		$note[] = $caption_view . ': ' .
					trim(str_between($dataB[3], '>', ' views'));
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
