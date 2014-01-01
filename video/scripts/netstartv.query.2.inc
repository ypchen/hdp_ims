<?php
	if ($pass_check) {
		$siteURLprefix = 'http://v.aibuka.com';
		foreach($videos as $video) {
			$title = convertUnicodePoints(trim(str_between($video, '">', '</a>')));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			$queryLevel = '.query.query';
			include('04_query.inc');
		}
	}
?>
