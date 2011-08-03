<?php
	// Display parameters
	$themeMainBackgroundColor = '10:150:105';

	$itemXML   = '';

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n"  .
			"\t\t<title>瀏覽觀看與收藏</title>\r\n" .
			"\t\t<link>"  . $scriptsURLprefix . '/history.php?uid=' . $user_id .
				'&amp;input_method='  . urlencode($inputMethod) .
				'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
				"</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";
	$itemTotal ++;

	$sites = array(
		array('maplestage', '台灣綜藝戲劇 (楓林網)', '※ 需安裝 youtube.video.php'),
		array('sugoideas', '台灣綜藝戲劇 (sugoideas)', '※ 需安裝 youtube.video.php'),
		array('appledaily', '台灣蘋果動新聞', ''),
		array('appledaily_cont', '台灣蘋果動新聞 (連續播放模式)', ''),
//		array('hk_appleactionews', '香港蘋果動新聞', ''),
		array('ims_search', 'IMS 搜索 (本機輸入)', '※ 需安裝 hdp_input'),
		array('ims_search_ol', 'IMS 搜索 (線上輸入)', 'URL: ' . $inputMethod),
		array('ted', 'TED Talks 中文字幕 youtube / podcast', '※ 需安裝 youtube.video.php'),
		array('youtube_pl', '公開播放清單 on youtube', '※ 需安裝 youtube.video.php'),
		array('CNN', 'CNN 影音播放 (podcast)', ''),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n"  .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<link>"  . $scriptsURLprefix . '/' . $site[0] . ".php?uid=" . $user_id .
					'&amp;input_method='  . urlencode($inputMethod) .
					'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
					"</link>\r\n" .
				"\t\t" . siteLogo($site[0]) . "\r\n" .
				"\t\t<note>" . $site[2] . "</note>\r\n" .
				"\t\t<mediaDisplay />\r\n" .
			"\t</item>\r\n\r\n";
	}

	// I do this because I would like to combine my own running site with the released code
	if (file_exists('ypSiteList.inc')) {
		include('ypSiteList.inc');
	}
?>
