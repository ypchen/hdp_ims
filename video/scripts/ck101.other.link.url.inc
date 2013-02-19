<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(
				str_replace('卡提諾影音', '',
					str_between($html, '<title>', '</title>'))
			);
	$title = convertUnicodePoints($title);

	$videos = explode('<video', ($htmlToExplode = str_between($html, '<div class="flashBox"', '</div>')));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$links = array();
	$titles = array();

	$siteURLprefix = '';
	foreach($videos as $video) {
		$titles[] = $title;

		$link  = $siteURLprefix . trim(str_between($video, '<source src="', '"'));
		$links[] = $link;
	}

	$iStart = intval($extra);
?>
