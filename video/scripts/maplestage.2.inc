<channel>

<?php
	echo "<title>$myBaseName: 項目選單</title>\r\n\r\n";

	if ($pass_check) {
		$hot_items = array(
			array('hot_show', '每日熱門綜藝', '', 'Hot Shows'),
			array('hot_drama', '每日熱門偶像劇', '', 'Hot Dramas')
		);

		$siteURLprefix = '';
		foreach ($hot_items as $video) {
			$title  = $video[1];
			$data   = '';
			$link   = $video[0];
			$image  = $video[2];
			$note   = $video[3];
			$extra  = '';

			$pageStart = 0;
			$queryLevel = '.' . $link . '.query';
			include('04_query.inc');
		}

		$siteURLprefix = 'http://maplestage.com';
		foreach ($videos as $video) {
			$tmpArr = explode(' ', trim(str_between($video, '">', '<')));
			$title  = $tmpArr[0];
			$title  = convertUnicodePoints($title);
			unset($tmpArr[0]);
			$note   = implode(' ', $tmpArr);
			$data   = '';
			$link   = trim(str_between($video, '"', '">'));
			$tmpArr = explode('/', $link);
			$link   = $siteURLprefix . $link;
			$image  = '';
			$extra  = '';

			$pageStart = 0;
			$queryLevel = '.' . substr($tmpArr[1], 0, -1) . '.query';
			include('04_query.inc');
		}
	}
?>

</channel>
