<?php
	$itemNo = intval($extra);

	if ($itemNo == 0) {
		// Show
		include('15_4_columns.inc');
	}
	else {
		// Drama
		include('15_2_columns.inc');
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
