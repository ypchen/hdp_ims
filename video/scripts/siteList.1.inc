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
				'&amp;cc_prefs='               . urlencode($videoCCPrefs) .
				'&amp;fmt_prefs='              . urlencode($videoFmtPrefs) .
				'&amp;yv_rmt_src='             . urlencode($youtubeVideoRemoteSource) .
				'&amp;youtube_video='          . urlencode($localhostYoutubeVideo) .
				'&amp;history_peer_path='      . urlencode($history_peer_path) .
				'&amp;history_peer_path_supp=' . urlencode($history_peer_path_supp) .
				'&amp;history_peer_name='      . urlencode($history_peer_name) .
				'&amp;history_peer_desc='      . urlencode($history_peer_desc) .
				"</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";

	$sites = array(
		array('netstartv',			'众遥电视　 (原网星、不卡)',				'※ 需安裝 youtube.video.php'),
		array('maplestage',			'綜藝戲劇　 (楓林網)',						'※ 需安裝 youtube.video.php'),
		array('sugoideas',			'綜藝戲劇　 (sugoideas)',					'※ 需安裝 youtube.video.php'),
		array('ck101',				'卡提諾影音 (ck101)',						'※ 需安裝 youtube.video.php'),
		array('ted',				'TED Talks on TED / YouTube / podcast',		'※ 需安裝 youtube.video.php'),
		array('youtube__v3',		'YouTube 帳戶功能',							'※ 需安裝 youtube.video.php　　 ※ 需設妥 YouTube 帳戶相關資料'),
		array('prefs',				'字幕、解析度、輸入方式設定',				'字幕: YouTube, TED　　　　　　解析度: YouTube, DM, 飛驢　　　輸入方式: 各需輸入功能處'),
		array('appledaily',			'台灣蘋果動新聞',							''),
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
						'&amp;cc_prefs='      . urlencode($videoCCPrefs) .
						'&amp;fmt_prefs='     . urlencode($videoFmtPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
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
