<channel>
<?php
	echo "\t<title>" . $myBaseName . ": 分類選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://www.tube8.com/';
		foreach($videos as $video) {
			$title = trim(str_between($video, '<h2 class="sh1"><span>', '</span></h2>'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, '<a class="display-block box_textshadow" href="', '"'));
			$image = trim(str_between($video, ' src="', '"'));
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
