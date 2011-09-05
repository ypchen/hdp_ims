<?php
	$yvItemPerPage = 40;
	$yvStartIndex  = ((($page > 0) ? ($page - 1) : 0) * $yvItemPerPage) + 1;

	switch ($extraSettings[0]) {
		case 'channel':
			$link = 'http://gdata.youtube.com/feeds/api/users/' . $search . '/uploads' .
					'?start-index=' . strval($yvStartIndex) .
					'&max-results=' . strval($yvItemPerPage) .
					'&v=2';
			break;
		case 'playlist':
			$link = 'http://gdata.youtube.com/feeds/api/playlists/' . $search .
					'?start-index=' . strval($yvStartIndex) .
					'&max-results=' . strval($yvItemPerPage) .
					'&v=2';
			break;
		case 'search':
			$link = 'http://gdata.youtube.com/feeds/api/videos' .
					'?start-index=' . strval($yvStartIndex) .
					'&max-results=' . strval($yvItemPerPage) .
					'&v=2' .
					$search;
			break;
	}

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$yvTotalResults = intval(
		trim(str_between($html,
			'<openSearch:totalResults>', '</openSearch:totalResults>')));
	if ($yvTotalResults <= $yvItemPerPage)
		$page = 0;

	$videos = explode('<entry gd:etag=', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
