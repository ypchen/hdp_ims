<script>
	bufferSize  = 262144;

	xmlUrl = getStoragePath("tmp") + "tmp.rss";
	writeStringToFile(xmlUrl, "ok");

	nameArray   = null;
	nameArray   = "<?php echo md5(time()); ?>";

	storagePath = getStoragePath("tmp");
	storagePath = storagePath + nameArray + ".dat";

<?php
	$ids = array();
	$pass_check = true;
	try {
		include($myBaseName . '.link.ids.inc');

		// 日本廣告 (測試用)
		//$ids = array('tBsA2Bk2rpk', '2tkt86hirVY', 'hrv6P0Ckz7w');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check) {

		echo "\titemSize    = " . count($ids) . ";\r\n";
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
?>
</script>
