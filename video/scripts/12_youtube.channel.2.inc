<?php
	// Extract all ids here
	$iCount = 0;
	$idString = '';
	$idArray  = array();
	foreach($videos as $video) {
		$currId    = trim(str_between($video, '<yt:videoid>', '</yt:videoid>'));
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
		$title = trim(str_between($video, '<title>', '</title>'));
		$title = convertUnicodePoints($title);
		if ($playContinue) {
			// Pass the current item number
			$extra = strval($iCount);
		}
		// else: $extra = '';
		$iCount ++;

		$image = 'http://i.ytimg.com/vi/' . $link . '/hqdefault.jpg';
		$note   = array();
		$length = intval(trim(str_between($video, "<yt:duration seconds='", "'")));
		$note[] = $caption_length . ': ' . sprintf("%02.2d:%02.2d:%02.2d", floor( $length / 3600 ), floor( ($length % 3600) / 60 ), $length % 60 );
		$note[] = $caption_publish . ': ' .
					str_replace('.000Z', '',
						str_replace('T', ' ',
							trim(str_between($video, '<yt:uploaded>', '</yt:uploaded>'))));
		$note[] = $caption_view . ': ' .
					trim(str_between($video, " viewCount='", "'"));
		$uploader = trim(str_between(
							str_between($video, "<media:credit role='uploader'", '/media:credit>'),
							'>', '<'));
		if (strlen($uploader) > 0) {
			$note[] = $caption_uploader . ': ' . $uploader;
		}
		else {
			$note[] = '';
		}

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
