<script>
	/* Default to be 1 for YouTube (handling CC at local) */
	ccCleanAtPlayItemURL = 1;
	bufferSize  = 262144;
	tmpItemSelected = getStoragePath("tmp") + "<?php echo 'ims_clips.' . $myBaseName . '-' . $uniquePageId . '.dat'; ?>";

	writeStringToFile("/tmp/yv_url_redir.exit", "");
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
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check) {

		if ($infoFromLocalFile) {
?>
	itemSize   = <?php echo $itemTotal; ?>;
	idArray    = readStringFromFile("/usr/local/etc/dvdplayer/ims_yv_api.ids");
	titleArray = readStringFromFile("/usr/local/etc/dvdplayer/ims_yv_api.titles");
	linkArray  = null;

	k = 0;
	while (k &lt; itemSize) {
		link = "<?php echo $localhostYoutubeVideo; ?>"
				+ "?query="          + getStringArrayAt(idArray, k)
				+ "&amp;cc_prefs="   + urlEncode("<?php echo $videoCCPrefs; ?>")
				+ "&amp;fmt_prefs="  + urlEncode("<?php echo $videoFmtPrefs; ?>")
				+ "&amp;yv_rmt_src=" + urlEncode("<?php echo $youtubeVideoRemoteSource; ?>");
		linkArray = pushBackStringArray(linkArray, link);
		k = k+1;
	}
<?php
		}
		else {
			if (isset($ids)) {
				$itemTotal = count($ids);
				echo "\titemSize    = " . ($itemTotal) . ";\r\n";
				echo "\tlinkArray   = null;\r\n";
				foreach ($ids as $id) {
					// 一定要使用來源本機做解析
					$link = $localhostYoutubeVideo . '?query=' . $id .
								'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
								'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
								'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource);
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
