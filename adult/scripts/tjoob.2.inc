<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.tjoob.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '"><strong>', '</strong>'));
			$title = convertUnicodePoints($title);
			$data  = ' ('. trim(str_between($video, '<p>(<strong>', '</strong>')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
