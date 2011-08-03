<?php
	$siteURLprefix = 'http://hk.dv.nextmedia.com';
	foreach($videos as $video) {

//		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
// I have no idea how to retrieve the link from the ajax call like these:
//		ajaxGetPlayer('10','20110802','4104','15485764','15486146','123467');
//		ajaxGetPlayer('10','20110802','4104','15485820','15486164','59300');
		$link = 'xxx';
		$title = trim(str_between($video, '<div class="dv_playlist_do_left_content_right2">', '<p>'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = $siteURLprefix . trim(str_between($video, '<img src="', '"'));
		$note   = array();
		$note[] = '';
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$clickPlay = 'yes';
		include('04_query.items.link.inc');
	}
?>
