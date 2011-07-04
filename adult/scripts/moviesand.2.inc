<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.moviesand.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '" alt="', '"'));
			$title = convertUnicodePoints($title);
			$data  = ' (' .
						trim(str_between($video, 'Total: <b>', '</b>')) .
					' 片段 [今天發佈: ' .
						trim(str_between($video, 'Today: <b>', '</b>')) .
					'])';
			$link  = $siteURLprefix . trim(str_between($video, '<center><a href="', '1.html"'));
			$image = trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
