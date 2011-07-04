<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.snizzshare.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '">', ' ('));
			$title = convertUnicodePoints($title);
			$data  = ' (' . trim(str_between($video, ' (', ' Videos)')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, 'ref="', '1.html'));
			$image = '';
			$note  = '';
			$extra = 'confirm_dob=1';

			include('04_query.inc');
		}
	}
?>
</channel>
