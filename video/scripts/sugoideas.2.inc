<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$itemNo = 0;
		$siteURLprefix = 'http://sugoideas.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '>', '</a>'));
			$title = str_replace('<br/>',   '', $title);
			$title = str_replace('<span>',  '', $title);
			$title = str_replace('</span>', '', $title);
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
			include('04_query.inc');
		}
	}
?>
</channel>
