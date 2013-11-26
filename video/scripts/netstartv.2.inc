<channel>

<?php
	echo "<title>$myBaseName: 導覽選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = 'http://v.netstartv.com';
		foreach($videos as $video) {

			if (strpos($video, 'class="dropdown"') !== false)
				continue;

			if (strpos($video, 'role="presentation"') !== false)
				continue;

			$title = convertUnicodePoints(trim(str_between($video, '">', '</a>')));
			$data  = '';
			$link  = $siteURLprefix . trim(str_between($video, 'href="', '"'));
			$image = '';
			$note  = '';
			$extra = '';

			$pageStart = 0;

			include('04_query.inc');
		}

		$itemXML   = '';

		$sites = array(
			array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
				'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
				'http://v.netstartv.com/search?q=', 'http://v.netstartv.com',
				'搜索'),
			array('input = getInput("Enter a keyword");',
				'內建輸入', $myBaseName, '使用播放機內建輸入功能',
				'http://v.netstartv.com/search?q=', 'http://v.netstartv.com',
				'搜索'),
		);
		foreach($sites as $site) {
			$searchTitle   = $site[6] . ': ' . $site[1];
			$searchUrlBase = $scriptsURLprefix . '/' . $myBaseName . '.query.query.php?uid=' . $user_id .
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
							" + \"," . urlencode($site[4]) . "\" + urlEncode(urlEncode(input))" .
							" + \",\" + urlEncode(\"" . $site[6] . " '\" + input + \"'\")" .
							" + \",\" + urlEncode(\"" . $site[5] . "\");" .
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
			array('netstartv',	'百家讲坛',			'http://baijia.netstartv.com',		'http://baijia.netstartv.com'),
			array('netstartv',	'曲艺',				'http://xiqu.netstartv.com',		'http://xiqu.netstartv.com'),
			array('netstartv',	'凤凰卫视',			'http://ifeng.netstartv.com',		'http://ifeng.netstartv.com'),
			array('netstartv',	'超清HD: 电视剧',	'http://hd.netstartv.com/tv',		'http://hd.netstartv.com'),
			array('netstartv',	'超清HD: 电影',		'http://hd.netstartv.com/movie',	'http://hd.netstartv.com'),
			array('netstartv',	'超清HD: 综艺',		'http://hd.netstartv.com/show',		'http://hd.netstartv.com'),
		);
		foreach($sites as $site) {
			$itemTotal ++;
			$itemXML   .=
				"\t<item>\r\n"  .
					"\t\t<title>" . $site[1] . "</title>\r\n" .
					"\t\t<link>"  . $scriptsURLprefix . '/' . $myBaseName . '.query.query.php?uid=' . $user_id .
						'&amp;input_method='  . urlencode($inputMethod) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
						'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
						'&amp;yv_cc_prefs='   . urlencode($youtubeVideoCCPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						'&amp;query=1,'       . urlencode($site[2]) .
						','                   . urlencode($site[1]) .
						','                   . urlencode($site[3]) .
						"</link>\r\n" .
					"\t\t" . siteLogo($site[0]) . "\r\n" .
					"\t\t<note></note>\r\n" .
					"\t\t<mediaDisplay />\r\n" .
				"\t</item>\r\n\r\n";
		}

		$sites = array(
			array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
				'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
				'http://hd.netstartv.com/search?q=', 'http://hd.netstartv.com',
				'超清HD: 搜索'),
			array('input = getInput("Enter a keyword");',
				'內建輸入', $myBaseName, '使用播放機內建輸入功能',
				'http://hd.netstartv.com/search?q=', 'http://hd.netstartv.com',
				'超清HD: 搜索'),
		);
		foreach($sites as $site) {
			$searchTitle   = $site[6] . ': ' . $site[1];
			$searchUrlBase = $scriptsURLprefix . '/' . $myBaseName . '.query.query.php?uid=' . $user_id .
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
							" + \"," . urlencode($site[4]) . "\" + urlEncode(urlEncode(input))" .
							" + \",\" + urlEncode(\"" . $site[6] . " '\" + input + \"'\")" .
							" + \",\" + urlEncode(\"" . $site[5] . "\");" .
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

		echo $itemXML;
	}
?>

</channel>
