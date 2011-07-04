<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
	/*
		echo '<item>
		<title>不分類</title>
		<link>' . $scriptsURLprefix . '/' . $myBaseName .
			'.query.php?uid=' . $user_id  . '&amp;query=1,' . urlencode('http://www.pornhub.com/video?c=') .
			',' . urlencode('不分類') . '</link></item>';
	*/
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
