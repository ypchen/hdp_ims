<?php
	if ($page > 1) {
		$extraArray  = explode('|', $extra);
		$extra       = $extraArray[0];
		$talkTotal   = $extraArray[1];
		$talkPerPage = $extraArray[2];
	}

	$link = $search . '?lang=' . $extra . '&event=&duration=&sort=newest&tag=&page=' . $page;
	$html = yp_file_get_contents($link, null, array('X-Requested-With: XMLHttpRequest'));
	include('05_check.file_contents.inc');

	if ($page == 1) {
		$talkTotal   = trim(str_between($html, 'total:', ','));
		$talkPerPage = trim(str_between($html, 'per_page:', ','));
	}

	if ((intval($talkPerPage) * intval($page)) >= intval($talkTotal))
		$pageMax = $page;

	$videos = explode('<div class="col clearfix">', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');

	// Change the outside $extra
	$extra_02_query_from_inc = $extra . '|' . $talkTotal . '|' . $talkPerPage;
?>
