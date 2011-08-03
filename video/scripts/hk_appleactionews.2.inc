<channel>
<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://hk.dv.nextmedia.com/template/dv_channel/';
		foreach($videos as $video) {
			$title = trim(str_between($video, 'title="', '"'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'ef="', '"'));
			$image = $siteURLprefix . trim(str_between($video, '<img src="', '"'));
			$note  = '';
			$extra = '';

			$pageStart = 0;
			include('04_query.inc');
		}
	}
?>
</channel>
