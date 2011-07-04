<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = trim(str_between($video, 'title="Click for more ', ' porn movies'));
			$title = convertUnicodePoints($title);
			$data  = ' (' . trim(str_between($video, "<span class='categorytotal'>", ' videos</span>')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, 'porn movies" href="', '"'));
			$image = trim(str_between($video, 'style=\'vertical-align:top;\' src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
