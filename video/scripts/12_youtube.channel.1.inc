<?php
	$yvItemPerPage = 40;
	$yvStartIndex  = ((($page > 0) ? ($page - 1) : 0) * $yvItemPerPage) + 1;

	switch ($extraSettings[0]) {
		case 'channel':
			$link = 'http://gdata.youtube.com/feeds/api/users/' . $search . '/uploads' .
					'?start-index=' . strval($yvStartIndex) .
					'&max-results=' . strval($yvItemPerPage) .
					((count($extraSettings) > 2) ? ($extraSettings[2]) : ('')) .
					'&v=2';
			break;
		case 'playlist':
			$link = 'http://gdata.youtube.com/feeds/api/playlists/' . $search .
					'?start-index=' . strval($yvStartIndex) .
					'&max-results=' . strval($yvItemPerPage) .
					((count($extraSettings) > 2) ? ($extraSettings[2]) : ('')) .
					'&v=2';
			break;
		case 'search':
			$link = 'http://gdata.youtube.com/feeds/api/videos' .
					'?start-index=' . strval($yvStartIndex) .
					'&max-results=' . strval($yvItemPerPage) .
					((count($extraSettings) > 2) ? ($extraSettings[2]) : ('')) .
					'&v=2' .
					$search;
			break;
	}

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$yvTotalResults = intval(
		trim(str_between($html,
			'<openSearch:totalResults>', '</openSearch:totalResults>')));
	if ($yvTotalResults <= ($yvStartIndex + $yvItemPerPage - 1))
		$pageMax = $page;

	$videos = explode('<entry gd:etag=', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	if (strcmp($extraSettings[1], 'continue=3') == 0) {
		$playContinue = true;
	}
	else {
		$playContinue = false;
	}

	// Save titles to the local disk
	$yvTitleFilePath = '/usr/local/etc/dvdplayer/ims_titles.dat';
	echo "\ttitleArray  = null;\r\n";
	// Extract all ids and titles here
	$iCount     = 0;
	$idString   = '';
	$idArray    = array();
	$titleArray = array();
	foreach($videos as $video) {
		$currId    = trim(str_between($video, '<yt:videoid>', '</yt:videoid>'));
		$idString .= '&amp;vid' . strval($iCount) . '=' . $currId;
		$idArray[] = $currId;
		$title = convertUnicodePoints(
					trim(str_between($video, '<title>', '</title>')));
		$titleArray[] = $title;
		echo "\ttitleArray  = pushBackStringArray(titleArray, \"" . str_replace('"', '\"', $title) . "\");\r\n";
		$iCount ++;
	}
	echo "\twriteStringToFile(\"" . $yvTitleFilePath . "\", titleArray);\r\n";
?>
