<?php
	$itemXML   = '';

	$sites = array(
		array('2EEE480A9E7B4E18', 'TED Talks 中文字幕', $myBaseName,
			'建立者：andyjayu04ro936', 'playlist', 'continue=0'),
		array('6661FF1871FDD4CB', 'TED Talks 中文字幕', $myBaseName,
			'建立者：lamplighter543', 'playlist', 'continue=0'),
		array('EA1976CE9B085F35', 'TED Talks 中文字幕', $myBaseName,
			'建立者：MAVERICKTPC', 'playlist', 'continue=0'),
		array('4E435084C20A2111', 'TED Talks 中文字幕', $myBaseName,
			'建立者：RichardCFHuang', 'playlist', 'continue=0'),
		array('D5E54CA0E2DB9B54', 'TED Talks 中文字幕', $myBaseName,
			'建立者：windrider21', 'playlist', 'continue=0'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . ucfirst($site[4]) . ": " . $site[1] . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/youtube.query.php?uid=' . $user_id .
						'&amp;input_method='  . urlencode($inputMethod) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
						'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						'&amp;query=1' .
							',' . $site[0] .
							',' . urlencode($site[1]) .
							',' . urlencode($site[4] . '|' . $site[5]) .
				"</link>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>" . $site[3] . "</note>\r\n" .
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
