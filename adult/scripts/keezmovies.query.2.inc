<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'src="', '"'));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, 'class="vd_dr">', '</span>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, 'class="liked_span">', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, 'class="views">', '</span>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
