<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$itemNo = 0;
		$siteURLprefix = 'http://video.ck101.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, 'title="', '"'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = trim(str_between($video, 'href="', '"'));
			if (strpos($link, $siteURLprefix) === false)
				$link = $siteURLprefix . $link;
			$image = '';
			$note  = '';
			$extra = $itemNo;
			$itemNo ++;

			$pageStart = 0;
			if ($itemNo <= 3) {
				$queryLevel = '.type_1.query';
			}
			else {
				$queryLevel = '.type_2.query';
			}
			include('04_query.inc');
		}
	}
?>
</channel>
