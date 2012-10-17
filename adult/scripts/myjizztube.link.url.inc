<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(urldecode(str_between($html, 's1.addParam("flashvars","settings=', '"')));
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(urldecode(str_between($html, 'defaultVideo:', ';')));
	include('05_check.link.inc');

	// Let youtube.video.php to handle it
	$link =
		$localhostYoutubeVideo . '?query=site_myjizztube' .
			'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
			'&amp;link='       . urlencode($link);

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
