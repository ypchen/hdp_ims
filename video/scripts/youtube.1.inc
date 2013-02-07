<?php
	$itemXML   = '';

	$sites = array(
		array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
			'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
			'search', 'continue=0|&amp;orderby=relevance',
			'搜索', '[關聯]'),
		array('input = getInput("Enter a keyword");',
			'內建輸入', $myBaseName, '使用播放機內建輸入功能',
			'search', 'continue=0|&amp;orderby=relevance',
			'搜索', '[關聯]'),
		array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
			'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
			'search', 'continue=0|&amp;orderby=published',
			'搜索', '[上傳]'),
		array('input = getInput("Enter a keyword");',
			'內建輸入', $myBaseName, '使用播放機內建輸入功能',
			'search', 'continue=0|&amp;orderby=published',
			'搜索', '[上傳]'),
		array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
			'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
			'search', 'continue=0|&amp;orderby=viewCount',
			'搜索', '[觀看]'),
		array('input = getInput("Enter a keyword");',
			'內建輸入', $myBaseName, '使用播放機內建輸入功能',
			'search', 'continue=0|&amp;orderby=viewCount',
			'搜索', '[觀看]'),
		array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
			'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
			'search', 'continue=0|&amp;orderby=rating',
			'搜索', '[評分]'),
		array('input = getInput("Enter a keyword");',
			'內建輸入', $myBaseName, '使用播放機內建輸入功能',
			'search', 'continue=0|&amp;orderby=rating',
			'搜索', '[評分]'),
/*
		array('input = doModalRss("' . $inputMethod . '", "mediaDisplay", "search", 0);',
			'線上輸入', $myBaseName, 'Input method: ' . $inputMethod,
			'search', 'continue=0',
			'搜索', ''),
*/
	);

	foreach($sites as $site) {
		$searchTitle   = $site[6] . ': ' . $site[1] . ' ' . $site[7];
		$searchUrlBase = $scriptsURLprefix . '/' . $myBaseName . '.query.php?uid=' . $user_id .
				'&amp;input_method='  . urlencode($inputMethod) .
				'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
				'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
				'&amp;yv_cc_prefs='   . urlencode($youtubeVideoCCPrefs) .
				'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
				'&amp;query=1';

		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $searchTitle . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\t" . $site[0] . "\r\n" .
					"\t\t\tif (input != null) {\r\n" .
					"\t\t\t\tsearchUrl = \"" . $searchUrlBase  . "\"" .
						" + \",%26q%3D\" + urlEncode(urlEncode(input))" .
						" + \",\" + urlEncode(\"" . $site[6] . " '\" + input + \"' " . $site[7] . "\")" .
						" + \",\" + urlEncode(\"" . $site[4] . '|' . $site[5] . "\");" .
					"\r\n" .
					"\t\t\t\tsearchUrl;\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
					"\t\t\t\tredrawDisplay();\r\n" .
					"\t\t\t}\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>" . $site[3] . "</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('youtube.set_cc',
			'設定: 字幕', 'youtube',
			'取消或設定: 嘗試載入順序 (YouTube)、字型大小 (YouTube, TED)、字幕顏色 (YouTube, TED)'),
		array('youtube.set_resolution',
			'設定: 影片解析度之喜好順序', 'youtube',
			'取消本機設定或設定影片解析度之喜好順序'),
	);

	foreach($sites as $site) {
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
				"\t\t" . siteLogo($site[2]) . "\r\n" .
				"\t\t<note>" . $site[3] . "</note>\r\n" .
				"\t\t<mediaDisplay />\r\n" .
			"\t</item>\r\n\r\n";
	}
?>
