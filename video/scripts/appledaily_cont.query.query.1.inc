<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if ($page > 0) {
		$pageHtml = str_between($html, '<nav class="page_switcher"', '</nav>');
		$pages = explode('<a class="btn_num"', $pageHtml);
		unset($pages[0]);
		$pages = array_values($pages);
		$pageMax = count($pages);
		if ($pageMax > 1) {
			$siteURLprefix = 'http://tw.nextmedia.com';
			$link  = $siteURLprefix . trim(str_between($pages[$page-1], 'href="', '"'));
			$html = yp_file_get_contents($link);
			include('05_check.file_contents.inc');
		}
	}

	$html = str_between($html, '<header>', '</article>');

	$videos = explode('<figure>', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
