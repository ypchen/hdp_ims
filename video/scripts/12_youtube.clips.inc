<script>
	bufferSize  = 262144;

	xmlUrl = getStoragePath("tmp") + "tmp.rss";
	writeStringToFile(xmlUrl, "ok");

	nameArray   = null;
	nameArray   = "<?php echo md5(time()); ?>";

	storagePath = getStoragePath("tmp");
	storagePath = storagePath + nameArray + ".dat";

<?php
	$pass_check = true;
	try {
		if (isset($title)) {
			$title_03_play = $title;
		}
		else {
			unset($title_03_play);
		}

		unset($title);
		unset($titles);

		unset($ids);
		unset($links);

		include($myBaseName . '.link.ids.inc');

		// 日本廣告 (測試用)
		//$ids = array('tBsA2Bk2rpk', '2tkt86hirVY', 'hrv6P0Ckz7w');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check) {

		if (isset($ids)) {
			$itemTotal = count($ids);
			echo "\titemSize    = " . ($itemTotal) . ";\r\n";
			echo "\tlinkArray   = null;\r\n";
			foreach ($ids as $id) {
				// 一定要使用來源本機做解析
				// 不能用 ims 網站做解析，因為 youtube 會鎖 client IP
				$link = $localhostYoutubeVideo . '?query=' . $id .
							'&amp;yv_fmt_prefs=' . urlencode($youtubeVideoFmtPrefs) .
							'&amp;yv_rmt_src='   . urlencode($youtubeVideoRemoteSource);

				echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $link . "\");\r\n";
			}
		}
		else {
			$itemTotal = count($links);
			echo "\titemSize    = " . ($itemTotal) . ";\r\n";
			echo "\tlinkArray   = null;\r\n";

			foreach ($links as $link) {
				echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $link . "\");\r\n";
			}
		}

		$hasTitleInfo = (isset($titles) || isset($title));
		if ($hasTitleInfo) {
			echo "\ttitleArray  = null;\r\n";

			if (isset($titles)) {
				for ($i = 0 ; $i < $itemTotal ; $i ++) {
					echo "\ttitleArray  = pushBackStringArray(titleArray, \"" . str_replace('"', '\"', $titles[$i]) . "\");\r\n";
				}
			}
			else {
				for ($i = 0 ; $i < $itemTotal ; $i ++) {
					echo "\ttitleArray  = pushBackStringArray(titleArray, \"" . str_replace('"', '\"', $title) . "\");\r\n";
				}
			}
		}
		else {
			// Read titles from the local disk if no title information is passed
			$yvTitleFilePath = '/usr/local/etc/dvdplayer/youtubeTitles.dat';
			echo "\ttitleArray  = readStringFromFile(\"" . $yvTitleFilePath . "\");\r\n";
		}

		if (isset($extraInfo)) {
			echo "\textraInfoArray = null;\r\n";
			for ($i = 0 ; $i < $itemTotal ; $i ++) {
				echo "\textraInfoArray = pushBackStringArray(extraInfoArray, \"" . $extraInfo[$i] . "\");\r\n";
			}
		}
	}
?>
</script>
