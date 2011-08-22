<?php
	// Extract all ids here
	$iCount = 0;
	$idString = '';
	$idArray  = array();
	foreach($videos as $video) {
		$currId    = trim(str_between($video, '<a href="/watch?v=', '&amp;'));
		$idString .= '&amp;vid' . strval($iCount) . '=' . $currId;
		$idArray[] = $currId;
		$iCount ++;
	}

	if (strcmp($extraSettings[1], 'continue=1') == 0) {
		$playContinue = true;
		$dataSupp = $idString;
	}
	else {
		$playContinue = false;
	}

	$iCount = 0;
	$extra = '';
	foreach($videos as $video) {

		$link  = $idArray[$iCount];
		$title = trim(str_between($video, '<span class="title video-title">', '</span>'));
		$title = convertUnicodePoints($title);
		if ($playContinue) {
			// Pass the current item number
			$extra = strval($iCount);
		}
		// else: $extra = '';
		$iCount ++;

		$image = 'http://i.ytimg.com/vi/' . $link . '/hqdefault.jpg';
		$note   = array();
		$note[] = $caption_length . '：' .
					trim(str_between($video, '<span class="video-time">', '</span>'));
		$note[] = $caption_view . '：' .
					trim(str_between(
						str_between(
							$video,
							'<span class="video-view-count">',
							'</span>'),
						'<strong>',
						'</strong>'));
		$note[] = trim(str_between($video, '<span class="video-owner">', '</span>'));
		$note[] = '';

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
