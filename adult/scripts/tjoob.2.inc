<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.tjoob.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '"><strong>', '</strong>'));
			$title = convertUnicodePoints($title);
			$vids  = trim(str_between($video, '<p>(<strong>', '</strong>'));
			if (strcmp($vids, '0') == 0) continue;
			$data  = ' ('. $vids . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
