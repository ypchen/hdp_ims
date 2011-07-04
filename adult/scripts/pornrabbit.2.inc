<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.pornrabbit.com';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<h3>' , '<span class="h3text">'));
			$title = convertUnicodePoints($title);
			$data  = ' (' . trim(str_between($video, '<span class="h3text">(' , 'videos)</span>')) . ' 片段)';
			$link  = $siteURLprefix . trim(str_between($video, '<a href="' , 'page'));
			$image = trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
