<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.appledaily.com.tw';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<span>', '</span>'));
			$title = cleanFragments('/&#\d+/', convertUnicodePoints(strip_tags($title)));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			$pageStart = 0;
			$queryLevel = '.query.query';
			include('04_query.inc');
		}
	}
?>
</channel>
