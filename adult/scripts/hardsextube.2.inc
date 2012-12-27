<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = convertUnicodePoints(trim(str_between($video, '">', '<')));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
			if (strpos($link, 'hardsextube.com') === false)
				continue;
			$image = '';
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
