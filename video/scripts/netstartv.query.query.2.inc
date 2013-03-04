<?php
	$sortedVideos = array();

	$siteURLprefix = 'http://v.netstartv.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
		$title = trim(str_between(str_between($video, '<div class="name">', '</div>'), '">', '<'));
		$title = convertUnicodePoints($title);
		$image = trim(str_between($video, ' src="', '"'));
		$extra = '';
		$note  = array('', '', '', '');

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
