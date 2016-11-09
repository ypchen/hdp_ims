<channel>

<?php
	echo "<title>$myBaseName: 項目選單</title>\r\n\r\n";

	if ($pass_check) {
		$items = array(
			array('台灣綜藝', '"type":"variety","region":"tw"'),
			array('大陸綜藝', '"type":"variety","region":"cn"'),
			array('韓國綜藝', '"type":"variety","region":"kr"'),
			array('台灣戲劇', '"type":"drama","region":"tw"'),
			array('大陸戲劇', '"type":"drama","region":"cn"'),
			array('韓國戲劇', '"type":"drama","region":"kr"'),
			array('日本戲劇', '"type":"drama","region":"jp"'),
			array('其他戲劇', '"type":"drama","region":"ot"'),
		);

		$siteURLprefix = '';
		foreach ($items as $video) {
			$title  = convertUnicodePoints($video[0]);
			$data   = '';
			$link   = base64_encode($video[1]);
			$image  = '';
			$note   = '';
			$extra  = '';

			$pageStart = 0;
			$queryLevel = '.' . 'year';
			include('04_query.inc');
		}
	}
?>

</channel>
