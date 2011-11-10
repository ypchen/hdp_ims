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
		$itemTotal = 0;

		include($myBaseName . '.link.url.inc');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check) {
		echo "\titemSize    = " . ($itemTotal) . ";\r\n";
		echo "\tlinkArray   = null;\r\n";
		echo "\ttitleArray  = null;\r\n";

		for ($i = 0 ; $i < $itemTotal ; $i ++) {
			echo "\tlinkArray   = pushBackStringArray(linkArray, \"" . $links[$i] . "\");\r\n";
			echo "\ttitleArray  = pushBackStringArray(titleArray, \"" . $titles[$i] . "\");\r\n";
		}
	}
?>
</script>
