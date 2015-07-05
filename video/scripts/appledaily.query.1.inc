<?php
	$html = yp_file_get_contents($search);
	include('05_check.file_contents.inc');

	if (strpos($html, 'class="listmore') !== false) {
		$totalPage = intval(trim(str_between(str_between($html, 'class="listmore', '<'), 'data-totalpage="', '"')));
	}
	else {
		$totalPage = 1;
	}

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
?>
