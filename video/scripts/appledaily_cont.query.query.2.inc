<?php
	if ($dataTotal > 0) {

		$iCount = 0;

		$siteURLprefix = 'http://tw.nextmedia.com';
		foreach($videos as $video) {

			// Pass the same XML $link
			//$link  = $siteURLprefix . trim(str_between($video, '<artlink>', '</artlink>'));
			$title = trim(str_between($video, '<title><![CDATA[', ']]></title>'));
			$title = convertUnicodePoints($title);
			// Pass the urrent item number
			$extra = strval($iCount);
			$iCount ++;

			$image  = trim(str_between($video, '<image>', '</image>'));
			$note   = array();
			$note[] = $caption_view . ': ' .
						trim(str_between($video, '<page_view>', '</page_view>'));
			$note[] = '';
			$note[] = '';
			$note[] = '';

			$clickPlay = 'no';
			include('04_query.items.link.inc');
		}
	}
?>
