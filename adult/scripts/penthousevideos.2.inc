<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = trim(str_between($video, ".html'>", '</a>'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = trim(str_between($video, "<a href='", "page1.html'"));
			$image = trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = 'confirm_dob=1';

			include('04_query.inc');
		}
	}
?>
</channel>
