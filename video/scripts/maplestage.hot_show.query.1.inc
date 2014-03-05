<?php
	$link = 'http://maplestage.com/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<div class="daily-block', $html);
	$htmlBody = explode('<div class="recent-block', $htmlBody[2]);

	$videos = explode(' class="item ', ($htmlToExplode = $htmlBody[0]));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
