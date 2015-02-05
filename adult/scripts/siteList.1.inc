<?php
	// Display parameters
	$themeMainBackgroundColor = '10:150:105';

	$itemXML   = '';

	// History
	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n"  .
			"\t\t<title>瀏覽觀看與收藏</title>\r\n" .
			"\t\t<link>"  . $scriptsURLprefix  . '/history.php?uid=' . $user_id .
				'&amp;input_method='           . urlencode($inputMethod) .
				'&amp;youtube_video='          . urlencode($localhostYoutubeVideo) .
				'&amp;yv_fmt_prefs='           . urlencode($youtubeVideoFmtPrefs) .
				'&amp;yv_cc_prefs='            . urlencode($youtubeVideoCCPrefs) .
				'&amp;yv_rmt_src='             . urlencode($youtubeVideoRemoteSource) .
				'&amp;history_peer_path='      . urlencode($history_peer_path) .
				'&amp;history_peer_path_supp=' . urlencode($history_peer_path_supp) .
				'&amp;history_peer_name='      . urlencode($history_peer_name) .
				'&amp;history_peer_desc='      . urlencode($history_peer_desc) .
				"</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";

	// 01 -> 02 -> play
	$sites = array(
		array('thisav', ''),
		array('flytube', ''),
		array('hardsextube', ''),
		array('keezmovies', ''),
		array('moviesand', ''),
		array('penthousevideos', ''),
		array('pornhub', ''),
		array('pornomovies', ''),
		array('sexbot', ''),
		array('tjoob', ' (無法選時)'),
		array('tube8', ''),
		array('xvideos', ''),
		array('xxxstash', ' (無法選時)'),
		array('timtube', ''),
	);
	foreach($sites as $site) {
		if (in_array($site[0], $sitesTurnedOff) === false) {
			$itemTotal ++;
			$itemXML   .=
				"\t<item>\r\n"  .
					"\t\t<title>" . $site[0] . $site[1] . "</title>\r\n" .
					"\t\t<link>"  . $scriptsURLprefix . '/' . $site[0] . ".php?uid=" . $user_id . "</link>\r\n" .
					"\t\t" . siteLogo($site[0]) . "\r\n" .
					"\t\t<mediaDisplay />\r\n" .
				"\t</item>\r\n\r\n";
		}
	}

	// 02 -> play
/*
	// Moved to 01 -> 02 -> play on Feb. 5, 2015
	$sites = array(
		array('timtube', 'http://www.timtube.com/'),
	);
	foreach($sites as $site) {
		if (in_array($site[0], $sitesTurnedOff) === false) {
			$itemTotal ++;
			$itemXML   .=
				"\t<item>\r\n"  .
					"\t\t<title>" . $site[0] . "</title>\r\n" .
					"\t\t<link>"  . $scriptsURLprefix . '/' . $site[0] . ".query.php?uid=" . $user_id .
						"&amp;query=1," . urlencode($site[1]) . ",,</link>\r\n" .
					"\t\t" . siteLogo($site[0]) . "\r\n" .
					"\t\t<mediaDisplay />\r\n" .
				"\t</item>\r\n\r\n";
		}
	}
*/

	// podcast
	$podcast_include = local_file_get_contents('10_podcast.inc');
	$sites = array(
		array('xxx4pods', 'XXX 4 Pods', 'http://xxx4pods.com/podcasts/podcast.xml'),
		array('french_maid_tv', 'French Maid TV', 'http://feeds.feedburner.com/FrenchMaidTV'),
		array('playboy', 'Playboy Video-Podcast (德國)', 'http://www.playboy.de/cybercastVID.xml'),
		array('nudes4pods', 'Nudes 4 Pods', 'http://nudes4pods.com/podcasts/podcast.xml'),
	);
	foreach($sites as $site) {
		if (in_array($site[0], $sitesTurnedOff) === false) {
			$itemTotal ++;
			$itemXML   .=
				"\t<item>\r\n" .
					"\t\t<title>$site[1]</title>\r\n" .
					"\t\t<link>$site[2]</link>\r\n" .
					"\t\t" . siteLogo($site[0]) . "\r\n" .
					$podcast_include .
				"\t</item>\r\n";
		}
	}
?>
