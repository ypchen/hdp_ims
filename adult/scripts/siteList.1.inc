<?php
	// Display parameters
	$themeMainBackgroundColor = '10:150:105';

	$itemXML   = '';

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n"  .
			"\t\t<title>瀏覽觀看與收藏</title>\r\n" .
			"\t\t<link>"  . $scriptsURLprefix . '/history.php?history=1000&amp;uid=' . $user_id . "</link>\r\n" .
			"\t\t" . myLogo('history') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n\r\n";

	$sites = array(
		'thisav',
		'friktube',
		'hardsextube',
		'moviesand',
		'myjizztube',
		'penthousevideos',
		'pornhub',
		'pornomovies',
		'pornrabbit',
		'sexbot',
		'tnaflix',
		'xxxstash',
		'pornmehorny',
		'tube8',
		'flytube',
		'keezmovies',
		'snizzshare',
		'tjoob',
		'xvideos'
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"<item>\r\n"  .
				"\t<title>" . $site . "</title>\r\n" .
				"\t<link>"  . $scriptsURLprefix . '/' . $site . ".php?uid=" . $user_id . "</link>\r\n" .
				"\t" . siteLogo($site) . "\r\n" .
				"\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"</item>\r\n\r\n";
	}

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Home Video Tube</title>\r\n" .
			"\t\t<link>http://ims.ypchen.tw/adult/scripts/home-video-tube.query.php?uid=" . $user_id . "&amp;query=1," . urlencode('http://www.home-video-tube.com/') . ",,</link>\r\n" .
			"\t\t" . siteLogo('home-video-tube') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>TimTube</title>\r\n" .
			"\t\t<link>http://ims.ypchen.tw/adult/scripts/timtube.query.php?uid=" . $user_id . "&amp;query=1," . urlencode('http://www.timtube.com/') . ",,</link>\r\n" .
			"\t\t" . siteLogo('timtube') . "\r\n" .
			"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>French Maid TV</title>\r\n" .
			"\t\t<link>http://feeds.feedburner.com/FrenchMaidTV</link>\r\n" .
			"\t\t" . siteLogo('french_maid_tv') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Playboy Video-Podcast (德國)</title>\r\n" .
			"\t\t<link>http://www.playboy.de/cybercastVID.xml</link>\r\n" .
			"\t\t" . siteLogo('playboy') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>XXX 4 Pods</title>\r\n" .
			"\t\t<link>http://xxx4pods.com/podcasts/podcast.xml</link>\r\n" .
			"\t\t" . siteLogo('xxx4pods') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>50 Grillz</title>\r\n" .
			"\t\t<link>http://www.50grillz.com/podcast.xml</link>\r\n" .
			"\t\t" . siteLogo('50grillz') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>My Dirty Ipods</title>\r\n" .
			"\t\t<link>http://www.mydirtyipods.com/Ipod/IpodClips.xml</link>\r\n" .
			"\t\t" . siteLogo('mydirtyipods') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Nudes 4 Pods</title>\r\n" .
			"\t\t<link>http://nudes4pods.com/podcasts/podcast.xml</link>\r\n" .
			"\t\t" . siteLogo('nudes4pods') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Suicide Girls</title>\r\n" .
			"\t\t<link>http://suicidegirls.com/rss/video/</link>\r\n" .
			"\t\t" . siteLogo('suicidegirls') . "\r\n" .
		"\t</item>\r\n";

	$itemTotal ++;
	$itemXML   .=
		"\t<item>\r\n" .
			"\t\t<title>Behind Kink</title>\r\n" .
			"\t\t<link>http://feeds.feedburner.com/kinkcast</link>\r\n" .
			"\t\t" . siteLogo('behindkink') . "\r\n" .
		"\t</item>\r\n";
?>
