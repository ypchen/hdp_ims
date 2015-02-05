<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = '';
	if (strpos($html, '<source src="') !== false) {
		$link = trim(urldecode(str_between($html, '<source src="', '"')));
	}
	else if (strpos($html, '<iframe id="embedPlayer"') !== false) {
		// actual content is somewhere else
		$link = trim(str_between(str_between($html, '<iframe id="embedPlayer"', '</iframe>'), ' href="', '"'));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$separators = array(
			array(".video_url = '", "'"),
			array(".cdnPath720         = '", "'"),
			array(".cdnPath480         = '", "'"),
			array(".cdnPath240         = '", "'"),
			array(".cdnPath180         = '", "'"),
			array("video.src = '", "'"),
		);
		foreach ($separators as $separator) {
			$link = trim(str_between($html, $separator[0], $separator[1]));
			if (!empty($link)) break;
		}
		if (strpos($link, '://') === false)
			$link = urldecode($link);
	}
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
