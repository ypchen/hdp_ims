<?php
	$itemXML   = '';

	// local fmt prefs: $fileLocalVideoFmtPrefs
	$sites = array(
		array('',
			'取消本機解析度設定', 'prefs',
			' -- 確認後將改為使用預設值 (' . $videoFmtPrefs . ')'),
		array('37,22,35,18,34,6,5',
			'可接受最高解析度：1080p', 'prefs',
			' -- 確認後將設定為: 37,22,35,18,34,6,5'),
		array('22,35,18,34,6,5',
			'可接受最高解析度：720p', 'prefs',
			' -- 確認後將設定為: 22,35,18,34,6,5'),
		array('35,18,34,6,5',
			'可接受最高解析度：480p', 'prefs',
			' -- 確認後將設定為: 35,18,34,6,5'),
		array('18,34,6,5',
			'可接受最高解析度：360p', 'prefs',
			' -- 確認後將設定為: 18,34,6,5'),
		array('6,5',
			'可接受最高解析度：270p', 'prefs',
			' -- 確認後將設定為: 6,5'),
		array('5',
			'可接受最高解析度：240p', 'prefs',
			' -- 確認後將設定為: 5'),
		array('9,37,22,35,18,34,6,5',
			'可接受最高解析度：4K 或更高 (飛驢)', 'prefs',
			' -- 確認後將設定為: 9,37,22,35,18,34,6,5'),
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
				"\t\t<note><script>\r\n" .
					"\t\t\tdataFile = \"" . $fileLocalVideoFmtPrefs . "\";\r\n" .
					"\t\t\tlocalYoutubeVideoFmtPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\tif ((localYoutubeVideoFmtPrefs == null) || (localYoutubeVideoFmtPrefs == \"\")) {\r\n" .
						"\t\t\t\tnoteStr = \"目前本機無解析度設定 (正使用預設值: " . $videoFmtPrefs . ")\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tnoteStr = \"目前本機解析度為: \" + localYoutubeVideoFmtPrefs;\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
				"\t\t</script></note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('N/A',
			'自行輸入影片解析度喜好順序', 'prefs',
			' -- 逗號隔開勿空格: 9(4K), 37(MP4-1920x1080), 22(MP4-1280x720), 35(FLV-854x480), 18(MP4-640x360), 34(FLV-640x360), 6(FLV-480x270), 5(FLV-400x240)'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\texecuteScript(\"getInputFromUser\");\r\n" .
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
				"\t\t<note><script>\r\n" .
					"\t\t\tdataFile = \"" . $fileLocalVideoFmtPrefs . "\";\r\n" .
					"\t\t\tlocalYoutubeVideoFmtPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\tif ((localYoutubeVideoFmtPrefs == null) || (localYoutubeVideoFmtPrefs == \"\")) {\r\n" .
						"\t\t\t\tnoteStr = \"目前本機無解析度設定 (正使用預設值: " . $videoFmtPrefs . ")\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tnoteStr = \"目前本機解析度為: \" + localYoutubeVideoFmtPrefs;\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
				"\t\t</script></note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
