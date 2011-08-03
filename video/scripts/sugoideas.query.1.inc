<?php
	$itemNo = intval($extra);

	if ($itemNo == 0) {
		// Show
		$rowCount    = 11;
		$columnCount = 4;
		$itemWidthPC = 23.75;
	}
	else {
		// Drama
		$rowCount    = 11;
		$columnCount = 2;
		$itemWidthPC = 47.5;
	}

	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$videos = explode('<div class="upcomingad"', $html);
	unset($videos[count($videos)-1]);	// Ads
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
