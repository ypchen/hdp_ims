<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {
			$title = trim(str_between($video, '/">', '<'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
			$image = siteImage($pageTitleBase);
			$note  = '';
			$extra = '';

			include('04_query.inc');
		}
	}
?>
</channel>
