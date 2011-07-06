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
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$html = str_between($html, '<header>', '</section>');

		$videos = explode('<figure>', $html);
		unset($videos[0]);
		$videos = array_values($videos);

		$itemTotal = count($videos);
		include('05_check.base.inc');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check) {
		$iStart = intval($extra);

		echo "\titemSize    = " . ($itemTotal) . ";\r\n";
		echo "\tlinkArray   = null;\r\n";

		$siteURLprefix = 'http://tw.nextmedia.com';
		foreach($videos as $video) {
			$link = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$link = $scriptsURLprefix . '/appledaily.video.php' .
				'?uid=' . $user_id  . '&amp;query=' . urlencode($link);
			echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $link . "\");\r\n";
		}
	}
?>
</script>
