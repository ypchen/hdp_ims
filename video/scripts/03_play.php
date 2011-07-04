<?php
	echo "<?xml version=\"1.0\" encoding=\"UTF8\" ?>\r\n";
	echo "<rss version=\"2.0\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\">\r\n";
?>
<?php
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');
	$myBaseName = basename($myName, '.link');
?>
<?php
	include('06_get.link.inc');

	ini_set('user_agent', $userAgent);

	include($myName . '.inc');

	$titleComponents = explode('.', $myBaseName);
	$pageTitleBase = $titleComponents[0];
	$pageTitle = $pageTitleBase;
	if (isset($title)) {
		$pageTitle = $pageTitle . ': ' . $title;
	}

	// Create my own link
	$params  = str_replace('&', '&amp;', $_SERVER['QUERY_STRING']);
	$currUrl = $scriptsURLprefix . '/' . $myName . '.php?' . $params;
?>

<onEnter>
	pre = "previewWindow";
	m = 0;
	if (linkArray == null) {
		postMessage("return");
	}
	if (thunder != null) {
		Thunder_adjustSpeed("max");
	}
	setRefreshTime(100);
	startVideo = 1;
	n = readStringFromFile(storagePath);
	if (n == null) {
		n = <?php echo (isset($iStart) ? $iStart : 0) ;?>;
	}
	else {
		n = Integer(n);
	}

	dataBrowse   = "<?php echo $fileBrowse; ?>";
	dataWatch    = "<?php echo $fileWatch; ?>";
	dataFavorite = "<?php echo $fileFavorite; ?>";

	dataBrowseMax   = <?php echo $maxBrowse; ?>;
	dataWatchMax    = <?php echo $maxWatch; ?>;
	dataFavoriteMax = <?php echo $maxFavorite; ?>;

	history = <?php echo $history; ?>;
	if (history == 0) {
		/* Parameters */
		dataFile   = dataWatch;
		dataMax    = dataWatchMax;
		dataType   = "1";
		dataTitle  = "<?php echo $pageTitle; ?>";
		dataLink   = "<?php echo $currUrl; ?>";
		<?php include('08_history.record.inc'); ?>
	}
</onEnter>

<onExit>
	playItemURL(-1, 1);
	setRefreshTime(-1);
</onExit>

<onRefresh>
	if (n &lt; 0 || n &gt; (itemSize-1)) {
		postMessage("return");
	}
	else {
		vidProgress = getPlaybackStatus();
		if (thunder == null) {
			bufProgress = getCachedStreamDataSize(0, bufferSize);
		}
		else {
			bufProgress = Thunder_getCachedStreamDataSize(0, bufferSize);
		}
		playElapsed = getStringArrayAt(vidProgress, 0);
		playStatus  = getStringArrayAt(vidProgress, 3);

		if (startVideo == 1) {
			currentUrl = getStringArrayAt(linkArray, n);
			if (currentUrl == null || currentUrl == "") {
				postMessage("return");
			}
			else {
				playItemURL(currentUrl, 0, "mediaDisplay", pre);
			}
			writeStringToFile(storagePath, n);
			setRefreshTime(100);
			showLoading = 1;
			startVideo = 0;
			updatePlaybackProgress(bufProgress, "mediaDisplay", "progressBar");
		}
		else {
			if (playElapsed != 0) {
				if (startVideo == 0) {
					updatePlaybackProgress("delete", "mediaDisplay", "progressBar");
					startVideo = 2;
				}
			}
			else if (playStatus == 0) {
				if ((n+1) &gt; (itemSize-1)) {
					playItemURL(-1, 1);
					setRefreshTime(-1);
					postMessage("return");
				}
				else {
					n = Add(n, 1);
					if (n &lt; 0) {
						n = 0;
					}
					startVideo = 1;
					pre = "previewWindow";
				}
			}
			else {
				print("no playing yet, update buffer progress ", bufProgress);
				updatePlaybackProgress(bufProgress, "mediaDisplay", "progressBar");
			}
		}
	}
</onRefresh>

<mediaDisplay name="threePartsView" viewAreaWidthPC="100" viewAreaHeightPC="100">

	<previewWindow windowColor="-1:-1:-1"
		offsetXPC="0" offsetYPC="0"
		widthPC="100" heightPC="100">
	</previewWindow>

	<previewWindow1 windowColor="-1:-1:-1"
		offsetXPC="2.5" offsetYPC="2.5"
		widthPC="95" heightPC="95">
	</previewWindow1>

	<previewWindow11 windowColor="-1:-1:-1"
		offsetXPC="5" offsetYPC="5"
		widthPC="90" heightPC="90">
	</previewWindow11>

	<progressBar backgroundColor="-1:-1:-1"
		offsetXPC="15" offsetYPC="70"
		widthPC="70" heightPC="20">

		<bar offsetXPC="33" offsetYPC="48"
			widthPC="60" heightPC="6"
			barColor="200:200:200"
			progressColor="26:129:211"
			bufferColor="-1:-1:-1"
			cornerRounding="10" />

		<text fontSize="16"
			offsetXPC="5" offsetYPC="40"
			widthPC="27" heightPC="20"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>
				if (playStatus == 2) {
					showstr = "讀取資料中...";
				}
				else {
					now = Add(n, 1);
					showstr = "正在載入第 " + now + " 段";
				}
				showstr;
			</script>
		</text>

		<text fontSize="16"
			offsetXPC="5.5" offsetYPC="80"
			widthPC="100" heightPC="20"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>
				segmentStr;
			</script>
		</text>

		<destructor offsetXPC="0" offsetYPC="0"
			widthPC="100" heightPC="100"
			Color="-1:-1:-1">
		</destructor>

	</progressBar>

	<onUserInput>
		<script>
			input = currentUserInput();

			if (input == "video_stop") {
				startVideo = 0;
				postMessage("return");
				"true";
			}
			else if (input == "down") {
				pre = pre + "1";
				if (pre == "previewWindow111") {
					pre = "previewWindow";
				}
				startVideo = 1;
				postMessage("video_stop");
				"true";
			}
			else if (input == "up") {
				pre = "autoresume";
				startVideo = 1;
				postMessage("video_stop");
				"true";
			}
			else if (input == "one" || input == "two" || input == "three" || input == "four" || input == "five" || input == "six" || input == "seven" || input == "eight" || input == "nine" || input == "zero" || input == "pagedown" || input == "right" || input == "pageup" || input == "left" || input == "video_abrepeat" || input == "video_repeat") {
				x = Integer(n/10)*10;
				if (input == "right")			n = Add(n, 1);
				if (input == "pagedown")		n = Add(n, 10);
				if (input == "pageup")			n = Minus(n, 10);
				if (input == "left")			n = Minus(n, 1);
				if (input == "one" || input == "video_abrepeat") n = 0;
				if (input == "video_repeat")	n = itemSize-1;
				if (input == "one")				n = x;
				if (input == "two")				n = Add(x, 1);
				if (input == "three")			n = Add(x, 2);
				if (input == "four")			n = Add(x, 3);
				if (input == "five")			n = Add(x, 4);
				if (input == "six")				n = Add(x, 5);
				if (input == "seven")			n = Add(x, 6);
				if (input == "eight")			n = Add(x, 7);
				if (input == "nine")			n = Add(x, 8);
				if (input == "zero")			n = Add(x, 9);
				if(n &lt; 0)					n = 0;
				if(n &gt; (itemSize-1))			n = itemSize-1;
				startVideo = 1;
				if(itemSize &gt; 1)				postMessage("video_stop");
				"true";
			}
			else {
				"false";
			}
		</script>
	</onUserInput>
</mediaDisplay>

<channel>

	<title>Media Play</title>
	<link>.</link>

</channel>

</rss>
<?php
	require('00_suffix.php');
?>
