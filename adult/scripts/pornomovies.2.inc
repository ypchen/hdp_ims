<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.pornomovies.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<h4><span>', '</h4>'));
			$title = convertUnicodePoints($title);
			$data  = ' (' .
				str_replace('&nbsp;', '; ',
				str_replace('<b>', '',
				str_replace('</b>', '',
					trim(str_between($video, '<center style="font-size: 16px;">', '</center>'))))) . ')';
			$link  = $siteURLprefix .
				str_replace('1.html', '',
					trim(str_between($video, ' href="', '">')));
			$image = trim(str_between($video, ' src="', '">'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
