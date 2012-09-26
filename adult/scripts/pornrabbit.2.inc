<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.pornrabbit.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<h2>' , '<small>'));
			$title = convertUnicodePoints($title);
			$data  = ' (' . trim(str_between($video, '<small> (' , ' videos)')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="' , '"'));
			$image = trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
