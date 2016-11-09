<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(str_between($html, '<iframe src="', '"'));
	if (strpos($link, 'youporn.com') !== false) {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, "720: '", "',"));
		if (strlen($link) <= 0)
			$link = trim(str_between($html, "480: '", "',"));
		if (strlen($link) <= 0)
			$link = trim(str_between($html, "240: '", "',"));
	}
	else if (strpos($link, 'alotporn.com') !== false) {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, "video_url: '", "',"));
	}
	else if (strpos($link, 'redtube.com') !== false) {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, '<source src="', '"'));
	}
	else if (strpos($link, 'updatetube.com') !== false) {
		$link = 'http://www.updatetube.com/player/embed.xml?video_id=' . trim(str_between($link, '/embed/', '/'));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, 'video_url="', '"'));
	}
	else if (strpos($link, 'thenewporn.com') !== false) {
		$link = 'http://thenewporn.com/player/embed.xml?video_id=' . trim(str_between($link, '/embed/', '/'));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, 'video_url="', '"'));
	}
	else if (strpos($link, 'exgfvideos.xxx') !== false) {
		$link = 'http://www.exgfvideos.xxx/modules/video/player/config_iframe.php?id=' . trim(str_between($link, '/embed.php?id=', '"'));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, "'url': '", "'"));
	}
	else if (strpos($link, 'pornhub.com') !== false) {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, "src		: '", "'"));
	}
	else if (strpos($link, 'creamypussyvideos.com') !== false) {
		$link = 'http://creamypussyvideos.com/modules/video/player/nuevo/config_embed.php?id=' . trim(str_between($link, '/embed/', '"'));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, '<file>', '</file>'));
	}
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
