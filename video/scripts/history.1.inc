<?php
	// Display parameters
	$themeMainBackgroundColor = '150:105:10';

	$itemXML   = '';

	// Local data
	$sites = array(
		array('favorites', 3, '本地收藏', $fileFavorite),
		array('browse',    1, '最近瀏覽', $fileBrowse),
		array('watch',     2, '最近觀看', $fileWatch),
	);

	// Peer data
	$peer_name = explode('|', $history_peer_name);
	unset($peer_name[0]);
	$peer_name = array_values($peer_name);
	if (($peer_num = count($peer_name)) > 0) {
		$peer_desc = explode('|', $history_peer_desc);
		unset($peer_desc[0]);
		$peer_desc = array_values($peer_desc);
		if (count($peer_desc) == $peer_num) {
			for ($i = 0 ; $i < $peer_num ; $i ++) {
				$sites[] = array('favorites',
					3, '收藏 -- ' . $peer_desc[$i],
					$history_peer_path . '/' . $peer_name[$i] . '/' . $history_peer_path_supp . '/ims_' . $imsDirectory . '_favorites.dat');
				$sites[] = array('browse',
					1, '瀏覽 -- ' . $peer_desc[$i],
					$history_peer_path . '/' . $peer_name[$i] . '/' . $history_peer_path_supp . '/ims_' . $imsDirectory . '_browse.dat');
				$sites[] = array('watch',
					2, '觀看 -- ' . $peer_desc[$i],
					$history_peer_path . '/' . $peer_name[$i] . '/' . $history_peer_path_supp . '/ims_' . $imsDirectory . '_watch.dat');
			}
		}
	}

	foreach($sites as $site) {
		$itemTotal ++;
		$itemXML   .=
			"\t<item>\r\n" .
				"\t\t<title>" . $site[2] . "</title>\r\n" .
				"\t\t<link>" .
					$scriptsURLprefix . '/' .
					$myBaseName . '.' . $site[0] . '.php?uid=' . $user_id .
						'&amp;history=' . $site[1] .
						'&amp;query=0,' . urlencode($site[2]) . ',' . urlencode($site[3]) . ',' .
				"</link>\r\n" .
				"\t\t" . myLogo($myBaseName . '.' . $site[0]) . "\r\n" .
				"\t\t<mediaDisplay name=\"photoView\" />\r\n" .
			"\t</item>\r\n";
	}
?>
