<?php
	// Display parameters
	$themeMainBackgroundColor = '150:105:10';

	$itemXML   = '';

	$sites = array(
		array('favorites', '本地收藏', 3),
		array('browse', '最近瀏覽', 1),
		array('watch', '最近觀看', 2),
	);

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[1] . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/' .
					$myBaseName . '.' . $site[0] . '.php?history=' . $site[2] .
						'&amp;uid=' . $user_id .
						'&amp;query=0,,,' .
				"</link>\r\n" .
				"\t\t" . myLogo($myBaseName . '.' . $site[0]) . "\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
