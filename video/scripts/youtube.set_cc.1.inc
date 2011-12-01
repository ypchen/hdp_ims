<?php
	$itemXML   = '';

	$sites = array(
		array('ED089C2E405CE1D6', '字幕測試影片', 'youtube',
			'建立者：ypchentube', 'playlist', 'continue=0'),
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

	// local cc prefs: $fileLocalYoutubeVideoCCPrefs
	$sites = array(
		array('',
			'取消字幕嘗試載入', 'youtube',
			' -- 確認後將改為不自動嘗試載入字幕'),
		array('en',
			'字幕嘗試載入順序: 英文', 'youtube',
			' -- 確認後將設定為: en'),
		array('zh-Hant,zh-TW,zh-HK,en',
			'字幕嘗試載入順序: 正體中文、英文', 'youtube',
			' -- 確認後將設定為: zh-Hant,zh-TW,zh-HK,en'),
		array('zh-Hans,en',
			'字幕嘗試載入順序: 简体中文、英文', 'youtube',
			' -- 確認後將設定為: zh-Hans,en'),
		array('zh-Hant,zh-TW,zh-HK,zh-Hans,en',
			'字幕嘗試載入順序: 中文(正體優先)、英文', 'youtube',
			' -- 確認後將設定為: zh-Hant,zh-TW,zh-HK,zh-Hans,en'),
		array('zh-Hant,zh-TW,zh-HK,zh-Hans,en',
			'字幕嘗試載入順序: 中文(简体優先)、英文', 'youtube',
			' -- 確認後將設定為: zh-Hans,zh-Hant,zh-TW,zh-HK,en'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\tdataFile = \"" . $fileLocalYoutubeVideoCCPrefs . "\";\r\n" .
					"\t\t\tdataStr  = \"" . $site[0] . "\";\r\n" .
					"\t\t\twriteStringToFile(dataFile, dataStr);\r\n" .
					"\t\t\tlocalYoutubeVideoCCPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\tif ((localYoutubeVideoCCPrefs == null) || (localYoutubeVideoCCPrefs == \"\")) {\r\n" .
						"\t\t\t\tmessage  = \" -- 已取消自動嘗試載入字幕\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tmessage  = \" -- 已設定為 {\" + localYoutubeVideoCCPrefs + \"}\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\tredrawDisplay();\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>\r\n" .
					"\t\t\t<script>\r\n" .
						"\t\t\t\tdataFile = \"" . $fileLocalYoutubeVideoCCPrefs . "\";\r\n" .
						"\t\t\t\tlocalYoutubeVideoCCPrefs = readStringFromFile(dataFile);\r\n" .
						"\t\t\t\tif ((localYoutubeVideoCCPrefs == null) || (localYoutubeVideoCCPrefs == \"\")) {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前設定為不自動嘗試載入字幕\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前嘗試載入字幕順序為: \" + localYoutubeVideoCCPrefs;\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
					"\t\t\t</script>\r\n" .
				"\t\t</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
			'自行輸入字幕嘗試載入順序 / 本機輸入', 'youtube',
			' -- 逗號隔開勿空格, 常用代碼: en(英文), zh-Hant(正體), zh-Hans(简体), zh-TW(台灣), zh-HK(香港), ja(日本語), ko(韓語)'),
		array('input = getInput("Enter a keyword");',
			'自行輸入字幕嘗試載入順序 / 內建輸入', 'youtube',
			' -- 逗號隔開勿空格, 常用代碼: en(英文), zh-Hant(正體), zh-Hans(简体), zh-TW(台灣), zh-HK(香港), ja(日本語), ko(韓語)'),
		array('input = doModalRss("' . $inputMethod . '", "mediaDisplay", "search", 0);',
			'自行輸入字幕嘗試載入順序 / 線上輸入', 'youtube',
			' -- 逗號隔開勿空格, 常用代碼: en(英文), zh-Hant(正體), zh-Hans(简体), zh-TW(台灣), zh-HK(香港), ja(日本語), ko(韓語)'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\t" . $site[0] . "\r\n" .
					"\t\t\tif (input != null) {\r\n" .
					"\t\t\t\tdataFile = \"" . $fileLocalYoutubeVideoCCPrefs . "\";\r\n" .
					"\t\t\t\twriteStringToFile(dataFile, input);\r\n" .
					"\t\t\t\tlocalYoutubeVideoCCPrefs = readStringFromFile(dataFile);\r\n" .
					"\t\t\t\tif ((localYoutubeVideoCCPrefs == null) || (localYoutubeVideoCCPrefs == \"\")) {\r\n" .
						"\t\t\t\t\tmessage  = \" -- 已取消自動嘗試載入字幕\";\r\n" .
					"\t\t\t\t}\r\n" .
					"\t\t\t\telse {\r\n" .
						"\t\t\t\t\tmessage  = \" -- 已設定為 {\" + localYoutubeVideoCCPrefs + \"}\";\r\n" .
					"\t\t\t\t}\r\n" .
					"\t\t\t\tredrawDisplay();\r\n" .
					"\t\t\t}\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>\r\n" .
					"\t\t\t<script>\r\n" .
						"\t\t\t\tdataFile = \"" . $fileLocalYoutubeVideoCCPrefs . "\";\r\n" .
						"\t\t\t\tlocalYoutubeVideoCCPrefs = readStringFromFile(dataFile);\r\n" .
						"\t\t\t\tif ((localYoutubeVideoCCPrefs == null) || (localYoutubeVideoCCPrefs == \"\")) {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前設定為不自動嘗試載入字幕\";\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tnoteStr = \"目前設定: \" + localYoutubeVideoCCPrefs;\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\tnoteStr + \"" . $site[3] . "\";\r\n" .
					"\t\t\t</script>\r\n" .
				"\t\t</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
