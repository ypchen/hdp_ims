<?php
	// For sugoideas
	$link = str_replace(
			'http://sugoitw.sugoideas.com/',
			'http://tw.sugoitw.com/',
			str_replace(
				'http://sugoideas.com/', 'http://tw.sugoitw.com/', $link));
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$ts = explode('|', str_between($html, '<title>', '</title>'));
	$title = trim($ts[0]);
	$title = convertUnicodePoints($title);

	// This one, i.e., Part 1
	$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));

	$videoList = explode('<li>', trim(str_between($html, '<ul class="contentlist">', '</ul>')));
	unset($videoList[1]);	// This one, i.e., Part 1, no link
	unset($videoList[0]);	// Prefix
	foreach ($videoList as $v) {
		$link = trim(str_between($v, ' href="', '"'));
		if (strlen($link) > 0) {
			$link = str_replace(
					'http://sugoitw.sugoideas.com/',
					'http://tw.sugoitw.com/',
					str_replace(
						'http://sugoideas.com/', 'http://tw.sugoitw.com/', $link));
			$html = yp_file_get_contents($link);
			include('05_check.file_contents.inc');

			$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));
		}
	}
	include('05_check.link.idcount.inc');
?>
