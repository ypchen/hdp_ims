<?php
	// Display parameters
	$themeMainBackgroundColor = '10:150:105';

	$itemXML   = '';

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n"  .
			"\t\t<title>瀏覽觀看與收藏</title>\r\n" .
			"\t\t<link>"  . $scriptsURLprefix . '/history.php?uid=' . $user_id .
				'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) . "</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";
	$itemTotal ++;

	$sites = array(
		array('maplestage', '楓林網 (台灣綜藝戲劇)'),
		array('appledaily', '蘋果動新聞'),
		array('appledaily_cont', '蘋果動新聞 (連續播放模式)'),
		array('CNN', 'CNN 影音播放 (podcast)'),
		array('ted', 'TED Talks 中文字幕 on youtube'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n"  .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<link>"  . $scriptsURLprefix . '/' . $site[0] . ".php?uid=" . $user_id .
					'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) . "</link>\r\n" .
				"\t\t" . siteLogo($site[0]) . "\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n\r\n";
	}

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>TEDTalks (podcast)</title>\r\n" .
			"\t\t<link>http://feeds.feedburner.com/tedtalks_video</link>\r\n" .
			"\t\t" . siteLogo('ted') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\"\r\n" .
			"\t\t\tshowHeader=\"no\"\r\n" .
			"\t\t\tshowDefaultInfo=\"yes\"\r\n" .
			"\t\t\titemBackgroundColor=\"0:0:0\"\r\n" .
			"\t\t\tbackgroundColor=\"0:0:0\"\r\n" .
			"\t\t\tsideLeftWidthPC=\"0\"\r\n" .
			"\t\t\titemImageXPC=\"5\"\r\n" .
			"\t\t\titemXPC=\"20\"\r\n" .
			"\t\t\titemYPC=\"20\"\r\n" .
			"\t\t\titemWidthPC=\"75\"\r\n" .
			"\t\t\tcapWidthPC=\"75\"\r\n" .
			"\t\t\tunFocusFontColor=\"101:101:101\"\r\n" .
			"\t\t\tfocusFontColor=\"255:255:255\"\r\n" .
			"\t\t\tpopupXPC=\"40\"\r\n" .
			"\t\t\tpopupYPC=\"55\"\r\n" .
			"\t\t\tpopupWidthPC=\"22.3\"\r\n" .
			"\t\t\tpopupHeightPC=\"5.5\"\r\n" .
			"\t\t\tpopupFontSize=\"14\"\r\n" .
			"\t\t\tpopupBorderColor=\"28:35:51\"\r\n" .
			"\t\t\tpopupForegroundColor=\"255:255:255\"\r\n" .
			"\t\t\tpopupBackgroundColor=\"28:35:51\"\r\n" .
			"\t\t\tidleImageWidthPC=\"10\"\r\n" .
			"\t\t\tidleImageHeightPC=\"10\"\r\n" .
			"\t\t>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "1.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "2.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "3.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "4.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "5.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "6.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "7.png</idleImage>\r\n" .
			"\t\t\t<idleImage>image/" . $idleImagePrefix . "8.png</idleImage>\r\n" .
			"\t\t\t<backgroundDisplay>\r\n" .
			"\t\t\t\t<image offsetXPC=\"0\" offsetYPC=\"0\" widthPC=\"100\" heightPC=\"100\">\r\n" .
			"\t\t\t\t\timage/mele/backgd.jpg\r\n" .
			"\t\t\t\t</image>\r\n" .
			"\t\t\t</backgroundDisplay>\r\n" .
			"\t\t\t<image offsetXPC=\"0\" offsetYPC=\"2.8\" widthPC=\"100\" heightPC=\"15.6\">\r\n" .
			"\t\t\t\timage/mele/rss_title.jpg\r\n" .
			"\t\t\t</image>\r\n" .
			"\t\t\t<text offsetXPC=\"40\" offsetYPC=\"8\"\r\n" .
			"\t\t\t\twidthPC=\"35\" heightPC=\"10\"\r\n" .
			"\t\t\t\tfontSize=\"20\"\r\n" .
			"\t\t\t\tbackgroundColor=\"-1:-1:-1\" foregroundColor=\"255:255:255\">\r\n" .
			"\t\t\t\t[確定]: 播放\r\n" .
			"\t\t\t</text>\r\n" .
			"\t\t</mediaDisplay>\r\n" .
		"\t</item>\r\n";

	// I do this because I would like to combine my own running site with the released code
	if (file_exists('ypSiteList.inc')) {
		include('ypSiteList.inc');
	}
?>
