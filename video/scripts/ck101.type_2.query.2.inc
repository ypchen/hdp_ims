<?php
	$siteURLprefix = 'http://v.ck101.com/channel/lists';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '/lists', '"'));
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = siteImage('ck101');
		$note   = array();
		$note[] = '';
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$sortedVideos[] = array(
			$title,
			$data,
			$link,
			$image,
			$note,
			$extra,
		);
	}

	foreach($sortedVideos as $video) {
		$title = $video[0];
		$data  = $video[1];
		$link  = $video[2];
		$image = $video[3];
		$note  = $video[4];
		$extra = $video[5];

		$pageStart = 1;
		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
