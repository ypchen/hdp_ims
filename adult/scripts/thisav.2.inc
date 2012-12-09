<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單 --" . $itemTotal . "-- </title>\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = trim(str_replace('&nbsp;', ' ', str_between($video, 'class="icon">', '</a>')));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$image = trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
