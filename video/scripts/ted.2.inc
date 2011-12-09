<channel>

<title>TED Talks on TED / YouTube / podcast</title>

<?php
	if ($pass_check) {
		// TED
		$videos = array(
			array('zh-tw',	'TED Talks 正體中文字幕', '',		'提供正體中文字幕的 TED Talks'),
			array('zh-cn',	'TED Talks 简体中文字幕', '',		'提供简体中文字幕的 TED Talks'),
			array('zh',		'TED Talks 粵語中文字幕', '',		'提供粵語中文字幕的 TED Talks'),
			array('en',		'TED Talks 英文字幕', '',			'提供英文字幕的 TED Talks'),
		);

		$siteURLprefix = 'http://www.ted.com/talks/list';
		foreach ($videos as $video) {
			$title  = $video[1];
			$data   = '';
			$link   = $siteURLprefix;
			$image  = $video[2];
			$note   = $video[3];
			$extra  = $video[0];

			include('04_query.inc');
		}

		// YouTube / podcast
		echo $itemXML;
	}
?>

</channel>
