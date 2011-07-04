<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://xxxstash.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, ' alt="', '"'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = trim(str_between($video, '<a href="', '"'));
			$image = $siteURLprefix . trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
