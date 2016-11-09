<?php
	// Redirect to the local youtube.video.php because of IP locking
	$src  = 'Tube8';

	$link =
		$localhostYoutubeVideo . '?query=site_tube8' .
			'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
			'&amp;fmt_prefs='  . urlencode($vdeoFmtPrefs) .
			'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
			'&amp;actual_src=' . urlencode($src) .
			'&amp;link='       . urlencode($link);
	$links = array($link);
	$titles = array($title);
			
	$itemTotal = count($links);
	include('05_check.base.inc');
?>
