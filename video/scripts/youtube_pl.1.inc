<?php
	$itemXML   = '';

	$sites = array(
		array('julianzart', '1080p HD Trailers', 'PL980F96CA7FC4B708'),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . ' (' . $site[0] . ' 的播放清單)' . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/' . $myBaseName . '.' . $site[0] . '.php?uid=' . $user_id .
						'&amp;input_method='  . urlencode($inputMethod) .
						'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
						'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
						'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
						'&amp;query=0,' . urlencode($site[2]) . ',' . $site[0] . ',' .
				"</link>\r\n" .
				"\t\t" . siteLogo($myBaseName) . "\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
