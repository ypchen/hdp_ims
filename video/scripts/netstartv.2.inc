<channel>

<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://v.netstartv.com';
		foreach($videos as $video) {

			if (strpos($video, 'class="dropdown"') !== false)
				continue;

			if (strpos($video, 'role="presentation"') !== false)
				continue;

			$title = convertUnicodePoints(trim(str_between($video, '">', '</a>')));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			if (strpos($link, '/children') !== false) {
				// Special case for children: No secondary menu
				$queryLevel = '.query.query';
			}
			else {
				$pageStart = 0;
			}
			include('04_query.inc');
		}
	}
?>

</channel>
