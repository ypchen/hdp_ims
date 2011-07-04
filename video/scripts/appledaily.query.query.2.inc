<?php
	if ($dataTotal > 0) {
		$siteURLprefix = 'http://tw.nextmedia.com';
		foreach($videos as $video) {

			$link  = $siteURLprefix . trim(str_between($video, '<artlink>', '</artlink>'));
			$title = trim(str_between($video, '<title><![CDATA[', ']]></title>'));
			$title = convertUnicodePoints($title);
			$extra = '';

			$image  = trim(str_between($video, '<image>', '</image>'));
			$note   = array();
			$note[] = $caption_view . ': ' .
						trim(str_between($video, '<page_view>', '</page_view>'));
			$note[] = '';
			$note[] = '';
			$note[] = '';

			$clickPlay = 'yes';
			include('04_query.items.link.inc');
		}
	}
?>
