<?php
	$siteURLprefix = 'http://www.thisav.com/video/';
	foreach($videos as $video) {

		// Get only the vide id
		$link  =
			$siteURLprefix .
				trim(str_between($video,
					'<a href="' . $siteURLprefix, '/')) .
			'/';
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img src="', '"'));
		$dataA  = explode('<br', $video);
		$dataB  = explode(' ', trim(str_between($video, '<div class="clear_right"></div>', '</div>')));
		$note   = array();
		$note[] = $caption_length . ': ' .
					trim(str_between($video, '<div class="box_left">', '<br'));
		$note[] = $caption_view . ': ' .
					$dataB[0];
		$note[] = $caption_publish . ': ' .
					trim(str_between($dataA[3], '/>', '</div>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
