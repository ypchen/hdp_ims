<?php
	$itemXML   = '';

	$sites = array(
		array('980F96CA7FC4B708', '高清測試影片 (720p，1080p)', 'youtube',
			'建立者：julianzart', 'playlist', 'continue=0'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . ucfirst($site[4]) . ": " . $site[1] . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/youtube.query.php?uid=' . $user_id .
						'&amp;fmt_prefs='     . urlencode($videoFmtPrefs) .
						'&amp;cc_prefs='      . urlencode($videoCCPrefs) .
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

	// local fmt prefs: $fileLocalVideoFmtPrefs
	$sites = array(
		array('',
			'取消本機解析度設定', 'youtube',
			' -- 確認後將改為使用預設值 (' . $videoFmtPrefs . ')'),
		array('37,22,35,18,34,6,5',
			'可接受最高解析度：1920x1080', 'youtube',
			' -- 確認後將設定為: 37,22,35,18,34,6,5'),
		array('22,35,18,34,6,5',
			'可接受最高解析度：1280x720', 'youtube',
			' -- 確認後將設定為: 22,35,18,34,6,5'),
		array('35,18,34,6,5',
			'可接受最高解析度：854x480', 'youtube',
			' -- 確認後將設定為: 35,18,34,6,5'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\tdataFile = \"" . $fileLocalVideoFmtPrefs . "\";\r\n" .
					"\t\t\tdataStr  = \"" . $site[0] . "\";\r\n" .
					"\t\t\twriteStringToFile(dataFile, dataStr);\r\n" .
					"\t\t\tlocalYoutubeVideoFmtPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\tif ((localYoutubeVideoFmtPrefs == null) || (localYoutubeVideoFmtPrefs == \"\")) {\r\n" .
						"\t\t\t\tmessage  = \" -- 已取消\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tmessage  = \" -- 已設定為 {\" + localYoutubeVideoFmtPrefs + \"}\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\tredrawDisplay();\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>\r\n" .
					"\t\t\t<script>\r\n" .
						"\t\t\t\tdataFile = \"" . $fileLocalVideoFmtPrefs . "\";\r\n" .
						"\t\t\t\tlocalYoutubeVideoFmtPrefs = readStringFromFile(dataFile);\r\n" .
						"\t\t\t\tif ((localYoutubeVideoFmtPrefs == null) || (localYoutubeVideoFmtPrefs == \"\")) {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前本機無解析度設定 (正使用預設值: " . $videoFmtPrefs . ")\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前本機解析度為: \" + localYoutubeVideoFmtPrefs;\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
					"\t\t\t</script>\r\n" .
				"\t\t</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
			'自行輸入影片解析度喜好順序 / 本機輸入', 'youtube',
			' -- 逗號隔開勿空格: 9(4K), 37(MP4-1920x1080), 22(MP4-1280x720), 35(FLV-854x480), 18(MP4-640x360), 34(FLV-640x360), 6(FLV-480x270), 5(FLV-400x240)'),
		array('input = getInput("Enter a keyword");',
			'自行輸入影片解析度喜好順序 / 內建輸入', 'youtube',
			' -- 逗號隔開勿空格: 9(4K), 37(MP4-1920x1080), 22(MP4-1280x720), 35(FLV-854x480), 18(MP4-640x360), 34(FLV-640x360), 6(FLV-480x270), 5(FLV-400x240)'),
		array('input = doModalRss("' . $inputMethod . '", "mediaDisplay", "search", 0);',
			'自行輸入影片解析度喜好順序 / 線上輸入', 'youtube',
			' -- 逗號隔開勿空格: 9(4K), 37(MP4-1920x1080), 22(MP4-1280x720), 35(FLV-854x480), 18(MP4-640x360), 34(FLV-640x360), 6(FLV-480x270), 5(FLV-400x240)'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\t" . $site[0] . "\r\n" .
					"\t\t\tif (input != null) {\r\n" .
					"\t\t\t\tdataFile = \"" . $fileLocalVideoFmtPrefs . "\";\r\n" .
					"\t\t\t\twriteStringToFile(dataFile, input);\r\n" .
					"\t\t\t\tlocalYoutubeVideoFmtPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\t\tif ((localYoutubeVideoFmtPrefs == null) || (localYoutubeVideoFmtPrefs == \"\")) {\r\n" .
						"\t\t\t\t\tmessage  = \" -- 已取消\";\r\n" .
					"\t\t\t\t}\r\n" .
					"\t\t\t\telse {\r\n" .
						"\t\t\t\t\tmessage  = \" -- 已設定為 {\" + localYoutubeVideoFmtPrefs + \"}\";\r\n" .
					"\t\t\t\t}\r\n" .
					"\t\t\t\tredrawDisplay();\r\n" .
					"\t\t\t}\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>\r\n" .
					"\t\t\t<script>\r\n" .
						"\t\t\t\tdataFile = \"" . $fileLocalVideoFmtPrefs . "\";\r\n" .
						"\t\t\t\tlocalYoutubeVideoFmtPrefs = readStringFromFile(dataFile);\r\n" .
						"\t\t\t\tif ((localYoutubeVideoFmtPrefs == null) || (localYoutubeVideoFmtPrefs == \"\")) {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前本機無解析度設定 (正使用預設值: " . $videoFmtPrefs . ")\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前本機解析度為: \" + localYoutubeVideoFmtPrefs;\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
					"\t\t\t</script>\r\n" .
				"\t\t</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
