<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.moviesand.com';
		foreach($videos as $video) {
			$title = trim(
						str_replace('More ', '',
						str_replace(' Videos', '',
							str_between($video, '">', '</a>'))));
			$title = convertUnicodePoints($title);
			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '1.html"'));
			$image = '';
			$note  = '';
			$extra = '';
			$data  = '';

			include('04_query.inc');
		}
	}
?>
</channel>
