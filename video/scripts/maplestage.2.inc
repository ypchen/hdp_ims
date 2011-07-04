<channel>

<?php
	echo "<title>$myBaseName: 項目選單</title>\r\n\r\n";

	if ($pass_check) {
		$videos = array(
			array('popular', '每日熱門', '', 'Most Watched Today'),
			array('recent', '最新節目', '', 'Newly Added'),
			array('show', '綜藝節目', '', 'Shows'),
			array('drama', '偶像戲劇', '', 'Dramas')
		);

		$siteURLprefix = '';
		foreach ($videos as $video) {
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
	}
?>

</channel>
