<script>
	urlYVRemoteSrc = "<?php echo $youtubeVideoRemoteSource; ?>";
	urllocalhostYV = "<?php echo $localhostYoutubeVideo; ?>";

	urlYVapi = urllocalhostYV
				+ "?query=yv_api"
				+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
				+ "&amp;cmd="  + urlEncode("channels?part=id&amp;mine=true");
	xmlYVapi = loadXMLFile(urlYVapi);
	if (xmlYVapi == null)
		msgSpecial = "叫用本機 youtube.video.php 失敗";
	else {
		code = getXMLText("root", "code");
		if (code != "200") {
			imgSpecial     = getXMLText("root", "imgSpecial");
			msgSpecial     = "[" + code + "]" + getXMLText("root", "msgSpecial");
			msgSpecialNote = getXMLText("root", "msgSpecialNote");
		}
	}
</script>

<?php
	$searchUrlBase = $scriptsURLprefix . '/' . $myBaseName . '.query.php?uid=' . $user_id .
			'&amp;cc_prefs='      . urlencode($videoCCPrefs) .
			'&amp;fmt_prefs='     . urlencode($videoFmtPrefs) .
			'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
			'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
			'&amp;query=1';

	$itemXML   = '';

	$sites = array(
		array('我的清單', $myBaseName, '預設: 正序連續播放',
			'mine|continue=3|playlists'),
		array('我的頻道', $myBaseName, '預設: 正序連續播放',
			'mine|continue=3|channels'),
	);
	foreach($sites as $site) {
		$searchTitle   = $site[0];

		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $searchTitle . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\t\tsearchUrl = \"" . $searchUrlBase  . "\"" .
						" + \",%26amp%3Bmine%3Dtrue\"" .
						" + \",\" + urlEncode(\"" . $site[0] . "\")" .
						" + \",\" + urlEncode(\"" . $site[3] . "\");" .
					"\r\n" .
					"\t\t\t\tsearchUrl;\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[1]) . "\r\n" .
				"\t\t<note>" . $site[2] . "</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('視訊搜索', $myBaseName, '預設: 個別視訊播放',
			'search|continue=0|&amp;amp;type=video'),
		array('直播搜索', $myBaseName, '預設: 個別視訊播放　　　　　　　直播較難成功啟動　　　　　　　　若持讀取資料卻未播放　　　　　　請停止並重試',
			'search|continue=0|&amp;amp;type=video&amp;amp;eventType=live'),
		array('清單搜索', $myBaseName, '預設: 正序連續播放',
			'search|continue=3|&amp;amp;type=playlist'),
		array('頻道搜索', $myBaseName, '預設: 正序連續播放',
			'search|continue=3|&amp;amp;type=channel'),
	);
	foreach($sites as $site) {
		$searchTitle   = $site[0];

		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $searchTitle . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\texecuteScript(\"getInputFromUser\");\r\n" .
					"\t\t\tif (input != null) {\r\n" .
						"\t\t\t\tdataFile    = \"/usr/local/etc/dvdplayer/ims_yv_search_order.dat\";\r\n" .
						"\t\t\t\tsearchOrder = readStringFromFile(dataFile);\r\n" .
						"\t\t\t\tif ((searchOrder == null) || (searchOrder == \"\")) {\r\n" .
							"\t\t\t\t\torderName   = \"[關聯]\";\r\n" .
							"\t\t\t\t\torderPara   = \"&amp;order=relevance\";\r\n" .
							"\t\t\t\t\tcontentItem = null;\r\n" .
							"\t\t\t\t\tcontentItem = pushBackStringArray(contentItem, orderName);\r\n" .
							"\t\t\t\t\tcontentItem = pushBackStringArray(contentItem, orderPara);\r\n" .
							"\t\t\t\t\twriteStringToFile(dataFile, contentItem);\r\n" .
						"\t\t\t\t}\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\torderName = getStringArrayAt(searchOrder, 0);\r\n" .
							"\t\t\t\t\torderPara = getStringArrayAt(searchOrder, 1);\r\n" .
						"\t\t\t\t}\r\n" .
					"\t\t\t\tsearchUrl = \"" . $searchUrlBase  . "\"" .
						" + \",%26amp%3Bq%3D\" + urlEncode(urlEncode(input))" .
						" + \",\" + urlEncode(\"" . $site[0] . " '\" + input + \"' \" + orderName)" .
						" + \",\" + urlEncode(\"" . $site[3] . "\");" .
					"\r\n" .
					"\t\t\t\tsearchUrl;\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
					"\t\t\t\tredrawDisplay();\r\n" .
					"\t\t\t}\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[1]) . "\r\n" .
				"\t\t<note>" . $site[2] . "</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$dataFilePath = '/usr/local/etc/dvdplayer/';
	$sites = array(
		array('設定搜索排序為 [關聯性]', $myBaseName,
			array($dataFilePath . 'ims_yv_search_order.dat'),
			array('[關聯]', '&amp;order=relevance')),
		array('設定搜索排序為 [上傳日期]', $myBaseName,
			array($dataFilePath . 'ims_yv_search_order.dat'),
			array('[日期]', '&amp;order=date')),
		array('設定搜索排序為 [觀看次數]', $myBaseName,
			array($dataFilePath . 'ims_yv_search_order.dat'),
			array('[觀看]', '&amp;order=viewCount')),
		array('設定搜索排序為 [評分]', $myBaseName,
			array($dataFilePath . 'ims_yv_search_order.dat'),
			array('[評分]', '&amp;order=rating')),
		array('設定搜索排序為 [標題]', $myBaseName,
			array($dataFilePath . 'ims_yv_search_order.dat'),
			array('[標題]', '&amp;order=title')),
	);
	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[0] . "</title>\r\n" .
				"\t\t<onClick>\r\n";
				foreach ($site[2] as $file) {
		$itemXML .= "\t\t\tcontentItem = null;\r\n";
					foreach ($site[3] as $contentItem) {
		$itemXML .= "\t\t\tcontentItem = pushBackStringArray(contentItem, \"" . $contentItem . "\");\r\n";
					}
		$itemXML .= "\t\t\twriteStringToFile(\"" . $file . "\", contentItem);\r\n";
				}
		$itemXML .= "\t\t\tmessage  = \" -- 已" . $site[0] . "\";\r\n" .
					"\t\t\tredrawDisplay();\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[1]) . "\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('設定每頁項目數量', $myBaseName, $dataFilePath . 'ims_yv_item_per_page.dat'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[0] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\texecuteScript(\"getInputFromUser\");\r\n" .
					"\t\t\tif ((input != null) &amp;&amp; (input != \"\") &amp;&amp; (Integer(input) &gt; 0) &amp;&amp; (Integer(input) &lt;= 50)) {\r\n" .
					"\t\t\t\tdataFile = \"" . $site[2] . "\";\r\n" .
					"\t\t\t\twriteStringToFile(dataFile, input);\r\n" .
					"\t\t\t\tsavedData = getStringArrayAt(readStringFromFile(dataFile), 0);\r\n" .
					"\t\t\t\tif ((savedData == null) || (savedData == \"\")) {\r\n" .
						"\t\t\t\t\tmessage  = \" -- 存入錯誤無法設定\";\r\n" .
					"\t\t\t\t}\r\n" .
					"\t\t\t\telse {\r\n" .
						"\t\t\t\t\tmessage  = \" -- 已設定為 {\" + savedData + \"}\";\r\n" .
					"\t\t\t\t}\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
						"\t\t\t\tmessage  = \" -- 不合法的設定值 {\" + input + \"}\";\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\tredrawDisplay();\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[1]) . "\r\n" .
				"\t\t<note><script>\r\n" .
					"\t\t\tdataFile = \"" . $site[2] . "\";\r\n" .
					"\t\t\tsavedData = getStringArrayAt(readStringFromFile(dataFile), 0);\r\n" .
					"\t\t\tif ((savedData == null) || (savedData == \"\"))\r\n" .
						"\t\t\t\tnoteStr = \"目前未設定每頁項目數量 (預設: $defaultYVItemPerPage)\";\r\n" .
					"\t\t\telse\r\n" .
						"\t\t\t\tnoteStr = \"目前設定為每頁 \" + savedData + \" 個項目\";\r\n" .
					"\t\t\tnoteStr;\r\n" .
				"\t\t</script></note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('新增播放清單', $myBaseName, '新增播放清單至 YouTube 帳戶',
			'playlist-add|continue=3|'),
	);
	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[0] . "</title>\r\n" .
				"\t\t<onClick>\r\n" .
					"\t\t\texecuteScript(\"getInputFromUser\");\r\n" .
					"\t\t\tif (input != null) {\r\n" .
						"\t\t\t\turlYVRemoteSrc = \"" . $youtubeVideoRemoteSource . "\";\r\n" .
						"\t\t\t\turllocalhostYV = \"" . $localhostYoutubeVideo . "\";\r\n" .
						"\t\t\t\trequestBody = \"{\\\"snippet\\\":{\\\"title\\\":\\\"\" + input + \"\\\"},\\\"status\\\":{\\\"privacyStatus\\\":\\\"private\\\"}}\";\r\n" .
						"\t\t\t\turlYVapi = urllocalhostYV\r\n" .
							"\t\t\t\t\t+ \"?query=yv_api\"\r\n" .
							"\t\t\t\t\t+ \"&amp;yv_rmt_src=\" + urlEncode(urlYVRemoteSrc)\r\n" .
							"\t\t\t\t\t+ \"&amp;cmd=\" + urlEncode(\"playlists?part=snippet,status\")\r\n" .
							"\t\t\t\t\t+ \"&amp;post=\" + urlEncode(requestBody);\r\n" .
						"\t\t\t\txmlYVapi = loadXMLFile(urlYVapi);\r\n" .
						"\t\t\t\tmessage  = \" -- " . $site[0] . "失敗\";\r\n" .
						"\t\t\t\tif (xmlYVapi == null)\r\n" .
							"\t\t\t\t\tmsgSpecial = \"叫用本機 youtube.video.php 失敗\";\r\n" .
						"\t\t\t\telse {\r\n" .
							"\t\t\t\t\tcode = getXMLText(\"root\", \"code\");\r\n" .
							"\t\t\t\t\tif (code != \"200\") {\r\n" .
								"\t\t\t\t\t\timgSpecial     = getXMLText(\"root\", \"imgSpecial\");\r\n" .
								"\t\t\t\t\t\tmsgSpecial     = \"[\" + code + \"]\" + getXMLText(\"root\", \"msgSpecial\");\r\n" .
								"\t\t\t\t\t\tmsgSpecialNote = getXMLText(\"root\", \"msgSpecialNote\");\r\n" .
							"\t\t\t\t\t}\r\n" .
							"\t\t\t\t\telse\r\n" .
								"\t\t\t\t\t\tmessage  = \" -- 已" . $site[0] . " \\\"\" + input + \"\\\"\";\r\n" .
						"\t\t\t\t}\r\n" .
							"\t\t\t\t\tredrawDisplay();\r\n" .
					"\t\t\t}\r\n" .
					"\t\t\telse {\r\n" .
					"\t\t\t\tredrawDisplay();\r\n" .
					"\t\t\t}\r\n" .
				"\t\t</onClick>\r\n" .
				"\t\t" . siteLogo($site[1]) . "\r\n" .
				"\t\t<note>" . $site[2] . "</note>\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}

	$sites = array(
		array('清除每頁項目數量設定', $myBaseName,
			array($dataFilePath . 'ims_yv_item_per_page.dat'),
			array(''),
				'yvItemPerPage = getStringArrayAt(readStringFromFile("' . $dataFilePath . 'ims_yv_item_per_page.dat' . '"), 0);' . "\r\n" .
				'if ((yvItemPerPage == null) || (yvItemPerPage == ""))' . "\r\n" .
				'"目前未設定每頁項目數量 (預設: ' . $defaultYVItemPerPage . ')";' . "\r\n" .
				'else' . "\r\n" .
				'"目前設定為每頁 " + yvItemPerPage + " 個項目";'),
		array('清除指定之播放清單', $myBaseName,
			array($dataFilePath . 'ims_yv_playlist_dest.dat'),
			array(''),
				'plDest = readStringFromFile("' . $dataFilePath . 'ims_yv_playlist_dest.dat' . '");' . "\r\n" .
				'if ((plDest == null) || (getStringArrayAt(plDest, 0) == ""))' . "\r\n" .
				'"目前未指定播放清單";' . "\r\n" .
				'else' . "\r\n" .
				'"目前指定: \"" + getStringArrayAt(plDest, 1) + "\"";'),
		array('清除 YouTube 授權', $myBaseName,
			array($dataFilePath . 'ims_yv_oa_code_device.dat',
				  $dataFilePath . 'ims_yv_oa_token_refresh.dat',
				  $dataFilePath . 'ims_yv_oa_token_access.dat'),
			array(''), false),
		array('清除 API 使用憑證', $myBaseName,
			array($dataFilePath . 'ims_yv_api_client_id.dat',
				  $dataFilePath . 'ims_yv_api_client_secret.dat'),
			array(''), false),
	);
	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
				"\t<item>\r\n" .
					"\t\t<title>" . $site[0] . "</title>\r\n" .
					"\t\t<onClick>\r\n";
					foreach ($site[2] as $file) {
		$itemXML .=		"\t\t\tcontentItem = null;\r\n";
						foreach ($site[3] as $contentItem) {
		$itemXML .=		"\t\t\tcontentItem = pushBackStringArray(contentItem, \"" . $contentItem . "\");\r\n";
						}
		$itemXML .=		"\t\t\twriteStringToFile(\"" . $file . "\", contentItem);\r\n";
					}
		$itemXML .=		"\t\t\tmessage  = \" -- 已" . $site[0] . "\";\r\n" .
						"\t\t\tredrawDisplay();\r\n" .
					"\t\t</onClick>\r\n" .
					"\t\t" . siteLogo($site[1]) . "\r\n";
					if ($site[4] !== false) {
		$itemXML .=	"\t\t<note><script>\r\n" .
						"\t\t\t" . $site[4] . "\r\n" .
					"\t\t</script></note>\r\n";
					}
		$itemXML .=	"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
				"\t</item>\r\n";
	}
?>
