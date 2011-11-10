<?php
	$link = $search . '&start=' . intval($page-1)*20;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, ' class="pagerNext pagerInactive">Next</li>') === true)
		$pageMax = $page;

	$htmlMain = explode('sectionList', $html);
	$htmlMainTail = explode('sectionFooter', $htmlMain[1]);
	$videos = explode('class="videoThumb">', $htmlMainTail[0]);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
