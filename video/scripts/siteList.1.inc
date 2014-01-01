<?php
	// Display parameters
	$themeMainBackgroundColor = '10:150:105';

	$itemXML   = '';

	// History
	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n"  .
			"\t\t<title>瀏覽觀看與收藏</title>\r\n" .
			"\t\t<link>"  . $scriptsURLprefix  . '/history.php?uid=' . $user_id .
				'&amp;input_method='           . urlencode($inputMethod) .
				'&amp;youtube_video='          . urlencode($localhostYoutubeVideo) .
				'&amp;yv_fmt_prefs='           . urlencode($youtubeVideoFmtPrefs) .
				'&amp;yv_cc_prefs='            . urlencode($youtubeVideoCCPrefs) .
				'&amp;yv_rmt_src='             . urlencode($youtubeVideoRemoteSource) .
				'&amp;history_peer_path='      . urlencode($history_peer_path) .
				'&amp;history_peer_path_supp=' . urlencode($history_peer_path_supp) .
				'&amp;history_peer_name='      . urlencode($history_peer_name) .
				'&amp;history_peer_desc='      . urlencode($history_peer_desc) .
				"</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";

	$sites = array(
		array('netstartv',			'不卡点播　 (原网星电视)',					'※ 需安裝 youtube.video.php'),
		array('appledaily_cont',	'台灣蘋果動新聞 [連續]',					''),
		array('appledaily',			'台灣蘋果動新聞',							''),
		array('maplestage',			'綜藝戲劇　 (楓林網)',						'※ 需安裝 youtube.video.php'),
		array('sugoideas',			'綜藝戲劇　 (sugoideas)',					'※ 需安裝 youtube.video.php'),
		array('ck101',				'卡提諾影音 (ck101)',						'※ 需安裝 youtube.video.php'),
		array('ted',				'TED Talks on TED / YouTube / podcast',		'※ 需安裝 youtube.video.php'),
		array('youtube',			'YouTube 搜索與設定',						'※ 需安裝 youtube.video.php'),
		array('youtube__channel',	'YouTube 頻道 (自行輸入)',					'※ 需安裝 youtube.video.php'),
		array('news',				'媒體新聞 on YouTube',						'※ 需安裝 youtube.video.php'),
		array('CNN',				'CNN 影音播放 podcast',						''),
		array('ims_search',			'IMS 搜索 (HAOIMS / HDPfans)',				''),
	);
	foreach($sites as $site) {
		if (in_array($site[0], $sitesTurnedOff) === false) {
			$itemTotal ++;
			$itemXML   .=
				"\t<item>\r\n"  .
					"\t\t<title>" . $site[1] . "</title>\r\n" .
					"\t\t<link>"  . $scriptsURLprefix . '/' . $site[0] . ".php?uid=" . $user_id .
						'&amp;input_method='  . urlencode($inputMethod) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
						'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
						'&amp;yv_cc_prefs='   . urlencode($youtubeVideoCCPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						"</link>\r\n" .
					"\t\t" . siteLogo($site[0]) . "\r\n" .
					"\t\t<note>" . $site[2] . "</note>\r\n" .
					"\t\t<mediaDisplay />\r\n" .
				"\t</item>\r\n\r\n";
		}
	}

	// I do this because I would like to combine my own running site with the released code
	if (file_exists('ypSiteList.inc')) {
		include('ypSiteList.inc');
	}
?>
