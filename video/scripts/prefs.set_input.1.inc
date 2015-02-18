<?php
	$itemXML   = '';

	// local input prefs: $fileLocalInputPrefs
	$sites = array(
		array(1,
			'使用本機輸入 (使用 hdp_input)', 'prefs',
			' -- 確認後將設定為: 本機輸入 (需安裝 hdp_input)',
			'rss_file://./etc/ypInput/keyboard.rss', ''),
		array(0,
			'使用內建輸入 (播放機內建輸入功能)', 'prefs',
			' -- 確認後將設定為: 播放機內建輸入',
			'N/A', ''),
		array(2,
			'以 hdp_input 自訂輸入方式', 'prefs',
			' -- 確認後將設定為: 自訂輸入方式',
			'', 'input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);'),
		array(2,
			'以內建輸入自訂輸入方式', 'prefs',
			' -- 確認後將設定為: 自訂輸入方式',
			'', 'input = getInput("Enter a keyword");'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<onClick>\r\n";
					if ($site[0] >= 2) {
			$itemXML .=	"\t\t\t" . $site[5] . "\r\n" .
						"\t\t\tif (input != null) {\r\n";
					}
					else {
			$itemXML .=	"\t\t\tinput = \"" . $site[4] . "\";\r\n";
					}
		$itemXML .=	"\t\t\tdataFile = \"" . $fileLocalInputPrefs . "\";\r\n" .
					"\t\t\tdataStr  = null;\r\n" .
					"\t\t\tdataStr  = pushBackStringArray(dataStr, \"" . strval($site[0]) . "\");\r\n" .
					"\t\t\tdataStr  = pushBackStringArray(dataStr, input);\r\n" .
					"\t\t\twriteStringToFile(dataFile, dataStr);\r\n" .
					"\t\t\tlocalInputPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\tif ((localInputPrefs == null) || (localInputPrefs == \"\")) {\r\n" .
						"\t\t\t\tmessage  = \" -- 已設定為播放機內建輸入\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tif ((inputType = getStringArrayAt(localInputPrefs, 0)) == \"0\") {\r\n" .
							"\t\t\t\t\tmessage  = \" -- 已設定為播放機內建輸入\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse if (inputType == \"1\") {\r\n" .
							"\t\t\t\t\tmessage  = \" -- 已設定為使用 hdp_input\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tmessage  = \" -- 已設定為 {\" + getStringArrayAt(localInputPrefs, 1) + \"}\";\r\n" .
						"\t\t\t\t}\r\n" .
					"\t\t\t}\r\n";
					if ($site[0] >= 2) {
			$itemXML .=	"\t\t\t}\r\n";
					}
		$itemXML .=	"\t\t\tredrawDisplay();\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note><script>\r\n" .
					"\t\t\tdataFile = \"" . $fileLocalInputPrefs . "\";\r\n" .
					"\t\t\tlocalInputPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\tif ((localInputPrefs == null) || (localInputPrefs == \"\")) {\r\n" .
						"\t\t\t\tnoteStr  = \"目前設定為播放機內建輸入\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tif ((inputType = getStringArrayAt(localInputPrefs, 0)) == \"0\") {\r\n" .
							"\t\t\t\t\tnoteStr  = \"目前設定為播放機內建輸入\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse if (inputType == \"1\") {\r\n" .
							"\t\t\t\t\tnoteStr  = \"目前設定為使用 hdp_input\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tnoteStr  = \"目前設定為 {\" + getStringArrayAt(localInputPrefs, 1) + \"}\";\r\n" .
						"\t\t\t\t}\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
				"\t\t</script></note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
