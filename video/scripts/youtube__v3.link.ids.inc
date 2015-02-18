<?php
	$infoFromLocalFile = false;

	if (isset($extra)) {
		// For YouTube's playlists, channels, and search results
		$extraSettings = explode('|', $extra);

		$infoFromLocalFile = true;
		list(, $continueFlag) = explode('=', $extraSettings[0]);
		$itemTotal = intval($extraSettings[1]);
		$iStart = intval($extraSettings[2]);
	}
	else {
		$ids  = explode(',', $link);
		$title = $title_03_play;
		include('05_check.link.idcount.inc');
	}
?>
