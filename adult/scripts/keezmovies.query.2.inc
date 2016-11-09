<?php
	$siteURLprefix = 'http://www.keezmovies.com';
	foreach($videos as $video) {

		$link  = trim(str_between($video, 'href="', '"'));
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, 'data-srcdata="', '"'));
		if (strpos($image, '//') == 0)
			$image = 'http:' . $image;
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between(str_between($video, 'class="vd_dr">', '</div>'), '<span>', '</span>'));
		$note[] = $caption_eval . ': ' .
					trim(str_between($video, 'class="liked_span">', '</span>'));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, 'class="views">', '</span>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
