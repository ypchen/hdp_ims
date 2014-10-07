<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.pornhub.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<strong>', '</strong>'));
			$title = convertUnicodePoints($title);
			$data  = ' (' . trim(str_between($video, '(<var>', '</var>)')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$image = trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
