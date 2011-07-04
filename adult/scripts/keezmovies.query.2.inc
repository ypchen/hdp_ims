<?php
	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = $caption_view . ': ' .
					trim(str_between($video, '<span class="views"><var>', '</var>'));
		$note[] = $caption_eval . ': ' .
				trim(str_between($video, 'style="margin:2px 0 0;"><strong >', '</strong>'));
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
