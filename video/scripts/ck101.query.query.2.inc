<?php
	$myBaseNameOriginal = $myBaseName;

	$siteURLprefix = 'http://video.ck101.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ' lz_src="', '"'));
		$note   = array();
		$note[] = '';
		$note[] = '';
		$note[] = '';
		$note[] = '';

		if (strpos($image, '.ytimg.com/') !== false) {
			$image = str_replace('/default.jpg', '/hqdefault.jpg', $image);
			$myBaseName = $myBaseNameOriginal . '.youtube';
		}
		else {
			$myBaseName = $myBaseNameOriginal . '.other';
		}
		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}

	$myBaseName = $myBaseNameOriginal;
?>
