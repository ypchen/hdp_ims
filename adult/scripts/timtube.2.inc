<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://timtube.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '"caption">', '<'));
			$title = convertUnicodePoints($title);
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"')) . 'recent/';
			$image = $siteURLprefix . trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';
			$data  = '';

			include('04_query.inc');
		}
	}
?>
</channel>
