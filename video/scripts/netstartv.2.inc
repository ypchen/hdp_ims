<channel>

<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = convertUnicodePoints(trim(str_between($video, '">', '</a>')));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			$pageStart = 0;
			include('04_query.inc');
		}
	}
?>

</channel>
