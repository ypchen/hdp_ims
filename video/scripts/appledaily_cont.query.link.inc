<script>
	bufferSize  = 262144;

	xmlUrl = getStoragePath("tmp") + "tmp.rss";
	writeStringToFile(xmlUrl, "ok");

	nameArray   = null;
	nameArray   = "<?php echo md5(time()); ?>";

	storagePath = getStoragePath("tmp");
	storagePath = storagePath + nameArray + ".dat";

<?php
	$dataTotal = 0;
	$pass_check = true;
	try {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$strToCheck = trim(str_between($html, '<total>', '</total>'));
		include('05_check.str.inc');

		$dataTotal = intval($strToCheck);
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if (($pass_check) && ($dataTotal > 0)) {
		$videos = explode('<imgdata>', $html);
		unset($videos[0]);
		$videos = array_values($videos);

		$itemTotal = count($videos);
		include('05_check.base.inc');

		$iStart = intval($extra);

		//echo "\titemSize    = " . ($itemTotal-$iStart) . ";\r\n";
		echo "\titemSize    = " . ($itemTotal) . ";\r\n";
		echo "\tlinkArray   = null;\r\n";

		$siteURLprefix = 'http://tw.nextmedia.com';
		foreach($videos as $video) {
			$link = $siteURLprefix . trim(str_between($video, '<artlink>', '</artlink>'));
			$link = $scriptsURLprefix . '/appledaily.video.php' .
				'?uid=' . $user_id  . '&amp;query=' . urlencode($link);
			echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $link . "\");\r\n";
		}
	}
?>

	segmentStr  = "共 " + itemSize + " 段 -- [數字鍵]選段;  [↔]±1;  [上下頁]±10";

</script>
