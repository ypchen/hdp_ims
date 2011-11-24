<?php
	// For YouTube's playlists, channels, and search results
	if (isset($extra)) {
		$iStart = intval($extra);
		$iCount = 0;
		$ids = array();
		while (!empty($_GET[($idKey = 'vid' . strval($iCount ++))])) {
			$ids[] = $_GET[$idKey];
		}
	}
	else {
		$ids  = explode(',', $link);
		$title = $title_03_play;
	}
	include('05_check.link.idcount.inc');
?>
