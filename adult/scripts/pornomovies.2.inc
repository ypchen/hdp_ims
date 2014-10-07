<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.pornomovies.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '">', '<'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
