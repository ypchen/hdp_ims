<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://pornomovies.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<a href="/channel/', '"><div style'));
			$title = convertUnicodePoints($title);
			$data  = ' (' . trim(str_between($video, 'Videos:', '<br/>')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"><div style'));
			$image = trim(str_between($video, '<div style="height:67px;width:205px;background:url(', ')'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
