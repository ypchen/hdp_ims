<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$totalPage = intval(trim(str_between(str_between($html, 'class="listmore', '<'), 'data-totalpage="', '"')));

	$siteURLprefix = 'http://www.appledaily.com.tw';
	$link = $siteURLprefix . trim(str_between(str_between($html, ".listmore').click", "</script>"), 'url: "', '"'));

	$htmlToExplode = '';

	// Load all pages
	for ($page = 1 ; $page <= $totalPage ; $page ++) {
		$html = yp_file_get_contents($link . $page);
		include('05_check.file_contents.inc');

		$htmlToExplode .= $html;
	}
	// Disable the page control
	$pageMax = $page = 0;

	$videos = explode('class="an-list-box"', $htmlToExplode);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	$links = array();
	$titles = array();

	$siteURLprefix = 'http://www.appledaily.com.tw';
	foreach($videos as $video) {
		$link = trim(str_between($video, ' href="', '"'));
		if (strpos($link, 'http://') === false)
			$link = $siteURLprefix . $link;
		$link = $scriptsURLprefix . '/appledaily.video.php' .
			'?uid=' . $user_id  . '&amp;query=' . urlencode($link);
		$links[] = $link;

		$title = trim(str_between($video, '<h2>', '</h2>'));
		$title = cleanFragments('/&#\d+/', convertUnicodePoints($title));
		$titles[] = $title;
	}

	$iStart = intval($extra);
?>
