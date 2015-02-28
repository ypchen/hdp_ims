<?php
	$itemXML   = '';

	$sites = array(
		array('appleactionews', '香港蘋果動新聞 [連續]', 'appleactionews',
			'appleactionews', 'channel', 'continue=3'),
		array('CantoneseNews360', '粵語新聞 [連續]', 'CantoneseNews360',
			'CantoneseNews360', 'channel', 'continue=3'),
		array('NMANews', '台灣蘋果動新聞 [連續]', 'appledaily',
			'建立者：NMANews', 'channel', 'continue=3'),
		array('AlJazeeraEnglish', '半島電視新聞 [連續]', $myBaseName,
			'建立者：AlJazeeraEnglish', 'channel', 'continue=3'),
		array('ttvnewsview', '台視 [連續]', $myBaseName,
			'建立者：ttvnewsview', 'channel', 'continue=3'),
		array('chinatv', '中視 [連續]', $myBaseName,
			'建立者：chinatv', 'channel', 'continue=3'),
		array('TBSCTS', '華視 [連續]', $myBaseName,
			'建立者：TBSCTS', 'channel', 'continue=3'),
		array('FTVCP', '民視 [連續]', $myBaseName,
			'建立者：FTVCP', 'channel', 'continue=3'),
		array('pts', '公視 [連續]', $myBaseName,
			'建立者：pts', 'channel', 'continue=3'),
		array('newsebc', '東森 [連續]', $myBaseName,
			'建立者：ETTVnews', 'channel', 'continue=3'),
		array('ChinaTimes', '中天 [連續]', $myBaseName,
			'建立者：ChinaTimes', 'channel', 'continue=3'),
		array('udncom', '聯合新聞網 [連續]', $myBaseName,
			'建立者：udncom', 'channel', 'continue=3'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . ucfirst($site[4]) . ": " . $site[1] . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/youtube.query.php?uid=' . $user_id .
						'&amp;cc_prefs='      . urlencode($videoCCPrefs) .
						'&amp;fmt_prefs='     . urlencode($videoFmtPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
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
