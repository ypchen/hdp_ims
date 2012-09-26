<?php
	// Display parameters
	$themeMainBackgroundColor = '10:150:105';

	$itemXML   = '';

	// History
	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n"  .
			"\t\t<title>瀏覽觀看與收藏</title>\r\n" .
			"\t\t<link>"  . $scriptsURLprefix . '/history.php?history=1000&amp;uid=' . $user_id . "</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";

	// 01 -> 02 -> play
	$sites = array(
		array('thisav', ''),
		array('flytube', ''),
		array('friktube', ''),
		array('hardsextube', ''),
		array('keezmovies', ''),
		array('moviesand', ''),
//		array('myjizztube', ' (無法選時)'),
		array('penthousevideos', ''),
		array('pornhub', ''),
		array('pornomovies', ''),
		array('pornrabbit', ''),
		array('sexbot', ''),
		array('tjoob', ' (無法選時)'),
//		array('tnaflix', ''),
		array('tube8', ''),
		array('xvideos', ''),
		array('xxxstash', ' (無法選時)'),
	);
	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n"  .
				"\t\t<title>" . $site[0] . $site[1] . "</title>\r\n" .
				"\t\t<link>"  . $scriptsURLprefix . '/' . $site[0] . ".php?uid=" . $user_id . "</link>\r\n" .
				"\t\t" . siteLogo($site[0]) . "\r\n" .
				"\t\t<mediaDisplay />\r\n" .
			"\t</item>\r\n\r\n";
	}

	// 02 -> play
	$sites = array(
//		array('home-video-tube', 'http://www.home-video-tube.com/'),
		array('timtube', 'http://www.timtube.com/'),
	);
	foreach($sites as $site) {
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

	// podcast
	$podcast_include = local_file_get_contents('10_podcast.inc');

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>XXX 4 Pods</title>\r\n" .
			"\t\t<link>http://xxx4pods.com/podcasts/podcast.xml</link>\r\n" .
			"\t\t" . siteLogo('xxx4pods') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Suicide Girls</title>\r\n" .
			"\t\t<link>http://suicidegirls.com/rss/video/</link>\r\n" .
			"\t\t" . siteLogo('suicidegirls') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>French Maid TV</title>\r\n" .
			"\t\t<link>http://feeds.feedburner.com/FrenchMaidTV</link>\r\n" .
			"\t\t" . siteLogo('french_maid_tv') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Playboy Video-Podcast (德國)</title>\r\n" .
			"\t\t<link>http://www.playboy.de/cybercastVID.xml</link>\r\n" .
			"\t\t" . siteLogo('playboy') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

/*
	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>50 Grillz</title>\r\n" .
			"\t\t<link>http://www.50grillz.com/podcast.xml</link>\r\n" .
			"\t\t" . siteLogo('50grillz') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";
*/

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>My Dirty Ipods</title>\r\n" .
			"\t\t<link>http://www.mydirtyipods.com/Ipod/IpodClips.xml</link>\r\n" .
			"\t\t" . siteLogo('mydirtyipods') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Nudes 4 Pods</title>\r\n" .
			"\t\t<link>http://nudes4pods.com/podcasts/podcast.xml</link>\r\n" .
			"\t\t" . siteLogo('nudes4pods') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";

/*
	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Behind Kink</title>\r\n" .
			"\t\t<link>http://feeds.feedburner.com/kinkcast</link>\r\n" .
			"\t\t" . siteLogo('behindkink') . "\r\n" .
			$podcast_include .
		"\t</item>\r\n";
*/
?>
