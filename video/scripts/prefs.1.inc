<?php
	$itemXML   = '';

	$sites = array(
		array('prefs.set_resolution',
			'設定: 影片解析度之喜好順序', $myBaseName,
			'取消本機設定或設定影片解析度之喜好順序 (YouTube, Dailymotion, 飛驢)'),
		array('prefs.set_cc',
			'設定: 字幕', $myBaseName,
			'取消或設定: 嘗試載入順序 (YouTube)、字型大小 (YouTube, TED)、字幕顏色 (YouTube, TED)'),
		array('prefs.set_input',
			'設定: 輸入方式', $myBaseName,
			'設定輸入方式 (各需輸入功能處)'),
	);

	foreach($sites as $site) {
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
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>" . $site[3] . "</note>\r\n" .
				"\t\t<mediaDisplay />\r\n" .
			"\t</item>\r\n\r\n";
	}
?>
