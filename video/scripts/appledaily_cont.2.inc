<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = trim(str_between($video, ');" >', '</a>'));
			$title = convertUnicodePoints(strip_tags($title));
			$data  = '';
			$link  = str_replace(',', '|', trim(str_between($video, ' href="', '"')));
			$image = '';
			$note  = '';
			$extra = '';

			$pageStart = 0;
			if (strpos($title, "最熱") !== false) {
				$queryLevel = '.query.query';
			}
			else {
				$queryLevel = '.query';
			}
			include('04_query.inc');
		}
	}
?>
</channel>
