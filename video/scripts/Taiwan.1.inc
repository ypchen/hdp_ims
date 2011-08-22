<?php
	$itemXML   = '';

	$sites = array(
		array('qwq33', '動感小站 Show Time', $myBaseName,
			'建立者：qwq33', 'channel', 'continue=0'),
		array('qwq33', '動感小站 Show Time (連續播放)', $myBaseName,
			'建立者：qwq33', 'channel', 'continue=1'),
		array('ttvnewsview', '台視 (連續播放)', $myBaseName,
			'建立者：ttvnewsview', 'channel', 'continue=1'),
		array('chinatv', '中視 (連續播放)', $myBaseName,
			'建立者：chinatv', 'channel', 'continue=1'),
		array('TBSCTS', '華視 (連續播放)', $myBaseName,
			'建立者：TBSCTS', 'channel', 'continue=1'),
		array('FTVCP', '民視 (連續播放)', $myBaseName,
			'建立者：FTVCP', 'channel', 'continue=1'),
		array('pts', '公視 (連續播放)', $myBaseName,
			'建立者：pts', 'channel', 'continue=1'),
		array('ETTVnews', '東森 (連續播放)', $myBaseName,
			'建立者：ETTVnews', 'channel', 'continue=1'),
		array('ChinaTimes', '中天 (連續播放)', $myBaseName,
			'建立者：ChinaTimes', 'channel', 'continue=1'),
		array('udncom', '聯合新聞網 (連續播放)', $myBaseName,
			'建立者：udncom', 'channel', 'continue=1'),
		array('NMANews', '蘋果動新聞 (連續播放)', 'appledaily',
			'建立者：NMANews', 'channel', 'continue=1'),
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
?>
