<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="ecs">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$links = array();
	$titles = array();

	$siteURLprefix = 'http://www.appledaily.com.tw';
	foreach($videos as $video) {
		$link = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$link = $scriptsURLprefix . '/appledaily.video.php' .
			'?uid=' . $user_id  . '&amp;query=' . urlencode($link);
		$links[] = $link;

		$title = trim(str_between($video, '<p>', '</p>'));
		$title = convertUnicodePoints($title);
		$titles[] = $title;
	}

	$iStart = intval($extra);
?>
