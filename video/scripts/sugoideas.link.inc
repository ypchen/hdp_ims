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
		$link = str_replace(
				'http://sugoitw.sugoideas.com/',
				'http://tw.sugoitw.com/',
				str_replace(
					'http://sugoideas.com/', 'http://tw.sugoitw.com/', $link));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		// This one, i.e., Part 1
		$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));

		$videoList = explode('<li>', trim(str_between($html, '<ul class="contentlist">', '</ul>')));
		unset($videoList[1]);	// This one, i.e., Part 1, no link
		unset($videoList[0]);	// Prefix
		foreach ($videoList as $v) {
			$link = trim(str_between($v, ' href="', '"'));
			if (strlen($link) > 0) {
				$link = str_replace(
						'http://sugoitw.sugoideas.com/',
						'http://tw.sugoitw.com/',
						str_replace(
							'http://sugoideas.com/', 'http://tw.sugoitw.com/', $link));
				$html = yp_file_get_contents($link);
				include('05_check.file_contents.inc');

				$ids[] = trim(str_between($html, 'http://www.youtube.com/embed/', '?'));
			}
		}
		include('05_check.link.idcount.inc');

		// 日本廣告 (測試用)
		//$ids = array('tBsA2Bk2rpk', '2tkt86hirVY', 'hrv6P0Ckz7w');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	echo "\titemSize    = " . count($ids) . ";\r\n";
	echo "\tlinkArray   = null;\r\n";

	if ($pass_check) {
		foreach ($ids as $id) {

			// 一定要使用來源本機做解析
			// 不能用 ims 網站做解析，因為 youtube 會鎖 client IP
			$link = $localhostYoutubeVideo . '?query=' . $id;

			echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $link . "\");\r\n";
		}
	}
?>
</script>
