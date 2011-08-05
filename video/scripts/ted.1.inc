<?php
	$itemXML   = '';

	$sites = array(
		array('dxmonline',      'TED Talks 中文字幕', 'PL2EEE480A9E7B4E18'),
		array('lamplighter543', 'TED Talks 中文字幕', '6661FF1871FDD4CB'),
		array('MAVERICKTPC',    'TED Talks 中文字幕', 'PLEA1976CE9B085F35'),
		array('RichardCFHuang', 'TED Talks 中文字幕', 'PL4E435084C20A2111'),
		array('windrider21',    'TED Talks 中文字幕', 'PLD5E54CA0E2DB9B54'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . ' (' . $site[0] . ' 的播放清單)' . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/' . $myBaseName . '.' . $site[0] . '.php?uid=' . $user_id .
						'&amp;input_method='  . urlencode($inputMethod) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
						'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						'&amp;query=0,' . urlencode($site[2]) . ',' . $site[0] . ',' .
				"</link>\r\n" .
				"\t\t" . siteLogo($myBaseName) . "\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$podcast_include = local_file_get_contents('10_podcast.inc');

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>TEDTalks (podcast)</title>\r\n" .
			"\t\t<link>http://feeds.feedburner.com/tedtalks_video</link>\r\n" .
			"\t\t" . siteLogo('ted') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

?>
