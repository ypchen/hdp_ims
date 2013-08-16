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

			if (strpos($link, '/children') !== false) {
				// Special case for children: No secondary menu
				$queryLevel = '.query.query';
			}
			else {
				$pageStart = 0;
			}
			include('04_query.inc');
		}

		$itemXML   = '';

		$sites = array(
			array('input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);',
				'本機輸入', $myBaseName, '※ 需安裝 hdp_input',
				'search', '',
				'搜索', ''),
			array('input = getInput("Enter a keyword");',
				'內建輸入', $myBaseName, '使用播放機內建輸入功能',
				'search', '',
				'搜索', '')
		);

		foreach($sites as $site) {
			$searchTitle   = $site[6] . ': ' . $site[1] . ' ' . $site[7];
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
							" + \",http%3A%2F%2Fv.netstartv.com%2Fsearch%3Fq%3D\" + urlEncode(urlEncode(input))" .
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

		echo $itemXML;
	}
?>

</channel>
