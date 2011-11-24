<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://tw.nextmedia.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '>', '</a>'));
			$title = convertUnicodePoints(strip_tags($title));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'ef="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			$pageStart = 0;
			include('04_query.inc');
		}
	}
?>
</channel>
