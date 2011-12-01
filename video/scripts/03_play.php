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

	if (isset($extra)) {
		// $extra may be changed by included scripts
		$extra_03_play = $extra;
	}
	else {
		unset($extra_03_play);
	}

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
	inputNumCount = 0;
	inputNumVal = -1;
	curNumVal = -1;

	if (linkArray == null) {
		postMessage("return");
	}
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

	itemCount = itemSize;

	x = itemCount;
	<?php include('00_utils.digits.inc'); ?>
	itemCountDigits = y;

	extraInfoFile = "<?php echo $fileLocalExtraInfo; ?>";

	lastPlayStatus = -2;
	playStatus = -1;

	runningHeadOne = "";
	runningHeadTwo = "";
	runningHeadWidthPC = 0;
	displayRunningHeadWidthPC = 100;

	clipToPlay = 0;
	selectClip = 0;
	selectClipTimeMark = 0;
	selectClipStatusOne = "";
	selectClipStatusTwo = "";
	selectClipStatusWidthPC = 0;
	displaySelectClipStatusWidthPC = 100;

	ccDataCountFile  = "<?php echo $fileLocalCCCount; ?>";
	ccDataStartFile  = "<?php echo $fileLocalCCStart; ?>";
	ccDataEndFile    = "<?php echo $fileLocalCCEnd; ?>";
	ccDataTextFile   = "<?php echo $fileLocalCCText; ?>";
	ccDataStatusFile = "<?php echo $fileLocalCCStatus; ?>";

	pbLastInt = -1;
	pbTimeCount = 0;
	ccTextFontSize = 24;
	ccTextOffsetYPC = 81.22;
	ccTextHeightPC = 5.98;
	ccBackgroundColor = "-1:-1:-1";
	ccForegroundColor = "255:255:0";
	ccForegroundShadowColor = "0:0:0";
	ccTextWidthPC = 100;
	ccDataCount = 0;

	showCCStatus = "";
	showCCStatusData = "";
	showCCStatusColor = "";
	showCCStatusWidthPC = 0;
	showCCStatusTimeMark = 0;

	startVideo = 1;
	setRefreshTime(100);
</onEnter>

<onExit>
	playItemURL(-1, 1);
	setRefreshTime(-1);
</onExit>

<onRefresh>
	pbStatus = getPlaybackStatus();
	pbCur = getStringArrayAt(pbStatus, 0);
	pbMax = getStringArrayAt(pbStatus, 1);
	if ((pbCur == "0") &amp;&amp; (pbMax == "100")) {
		runningHeadOne = "";
		runningHeadTwo = "";

		pbLastInt = -1;
		pbTimeCount = 0;

		pbCurTick = 0;
	}
	else {
		pbMaxInt = Integer(pbMax);
		pbMaxH = Integer(pbMaxInt / 3600);
		pbMaxM = pbMaxInt % 3600;
		pbMaxM = Integer(pbMaxM / 60);
		if (pbMaxM &lt; 10) pbMaxM = "0" + pbMaxM;
		pbMaxS = pbMaxInt % 60;
		if (pbMaxS &lt; 10) pbMaxS = "0" + pbMaxS;
		pbCurInt = Integer(pbCur);
		pbCurH = Integer(pbCurInt / 3600);
		pbCurM = pbCurInt % 3600;
		pbCurM = Integer(pbCurM / 60);
		if (pbCurM &lt; 10) pbCurM = "0" + pbCurM;
		pbCurS = pbCurInt % 60;
		if (pbCurS &lt; 10) pbCurS = "0" + pbCurS;
		runningHeadOne = pbCurH + ":" + pbCurM + ":" + pbCurS + " / " + pbMaxH + ":" + pbMaxM + ":" + pbMaxS + " [" + now + "/" + itemCount + "] " + currentTitle;

		if (pbLastInt != pbCurInt) {
			pbLastInt = pbCurInt;
			pbTimeCount = 0;
		}
		else {
			pbTimeCount = Add(pbTimeCount, 1);
			if (pbTimeCount &gt; 9)
				pbTimeCount = 9;
		}

		pbCurTick = Add(Integer(pbCurInt * 10), pbTimeCount);
	}

	if (ccDataCount &gt; 0) {
		ccLower = 0;
		ccUpper = ccDataCount-1;
		ccFound = 0;
		while (ccFound == 0) {
			ccIndex = Integer(Add(ccLower, ccUpper) / 2);
			ccStart = Integer(getStringArrayAt(ccDataStart, ccIndex));
			if (pbCurTick &lt; ccStart) {
				ccUpper = ccIndex;
			}
			else if (pbCurTick &gt; ccStart) {
				if (ccLower == (ccUpper-1)) {
					ccFound = 1;
				}
				else {
					ccLower = ccIndex;
				}
			}
			else {
				ccFound = 1;
			}
		}

		ccEnd = Integer(getStringArrayAt(ccDataEnd, ccIndex-2));
		if (pbCurTick &lt; ccEnd) {
			ccTextThree = getStringArrayAt(ccDataText, ccIndex-2);
		}
		else {
			ccTextThree = "";
		}
		ccEnd = Integer(getStringArrayAt(ccDataEnd, ccIndex-1));
		if (pbCurTick &lt; ccEnd) {
			ccTextTwo = getStringArrayAt(ccDataText, ccIndex-1);
		}
		else {
			ccTextTwo = "";
		}
		ccEnd = Integer(getStringArrayAt(ccDataEnd, ccIndex));
		if (pbCurTick &lt; ccEnd) {
			ccTextOne = getStringArrayAt(ccDataText, ccIndex);
		}
		else {
			ccTextOne = "";
		}
	}

	if (selectClip == 1) {
		if (pbCurInt &gt; Add(selectClipTimeMark, 6)) {
			selectClip = 0;
			selectClipStatusWidthPC = 0;
			inputNumCount = 0;
			inputNumVal = -1;
			curNumVal = -1;
		}
	}

	if (showCCStatusWidthPC &gt; 0) {
		if (pbCurInt &gt; Add(showCCStatusTimeMark, 3)) {
			showCCStatusWidthPC = 0;
		}
	}

	if ((n &lt; 0) || (n &gt; (itemCount-1))) {
		postMessage("return");
	}
	else {
		vidProgress = getPlaybackStatus();
		bufProgress = getCachedStreamDataSize(0, bufferSize);
		playElapsed = Integer(getStringArrayAt(vidProgress, 0));
		lastPlayStatus = playStatus;
		playStatus  = Integer(getStringArrayAt(vidProgress, 3));

		if ((playStatus == 2) &amp;&amp; (lastPlayStatus != 2)) {
			runningHeadTwo = readStringFromFile(extraInfoFile);
			if ((runningHeadTwo == null) || (runningHeadTwo == "")) {
				runningHeadTwo = getStringArrayAt(extraInfoArray, n);
			}

			ccDataCountString = readStringFromFile(ccDataCountFile);
			if ((ccDataCountString == null) || (ccDataCountString == "")) {
				ccDataCount = 0;
			}
			else {
				ccDataCount = Integer(ccDataCountString);
				ccDataStart = readStringFromFile(ccDataStartFile);
				ccDataEnd = readStringFromFile(ccDataEndFile);
				ccDataText = readStringFromFile(ccDataTextFile);
			}

			showCCStatusData = readStringFromFile(ccDataStatusFile);
			if ((showCCStatusData == null) || (showCCStatusData == "")) {
				showCCStatus = "";
				showCCStatusColor = "";
			}
			else {
				showCCStatus = getStringArrayAt(showCCStatusData, 0);
				showCCStatusColor = getStringArrayAt(showCCStatusData, 1);
				showCCStatusWidthPC = 100;
				showCCStatusTimeMark = 2;
			}
		}

		if (startVideo == 1) {
			currentUrl = getStringArrayAt(linkArray, n);
			if ((currentUrl == null) || (currentUrl == "")) {
				postMessage("return");
			}
			else {
				inputNumCount = 0;
				inputNumVal = -1;
				curNumVal = -1;

				pbLastInt = -1;
				pbTimeCount = 0;

				showCCStatus = "":
				showCCStatusData = "":
				showCCStatusColor = "":
				showCCStatusWidthPC = 0;
				showCCStatusTimeMark = 0;

				lastPlayStatus = -2;
				playStatus = -1;
				writeStringToFile(extraInfoFile, "");
				writeStringToFile(ccDataCountFile, "0");
				writeStringToFile(ccDataStatusFile, "");

				playItemURL(currentUrl, 0, "mediaDisplay", "previewWindow");
			}
			currentTitle = getStringArrayAt(titleArray, n);
			if (currentTitle == null) {
				currentTitle = "";
			}
			writeStringToFile(storagePath, n);
			startVideo = 0;
			setRefreshTime(100);
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
				if ((n+1) &gt; (itemCount-1)) {
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
				}
			}
			else {
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

	<text redraw="yes" align="left" fontSize="20"
		offsetXPC="0" offsetYPC="6"
		widthPC="0" heightPC="6"
		backgroundColor="0:0:0" foregroundColor="255:255:255">
		<script>runningHeadOne;</script>
		<widthPC><script>runningHeadWidthPC;</script></widthPC>
	</text>

	<text redraw="yes" align="left" fontSize="20"
		offsetXPC="0" offsetYPC="12"
		widthPC="0" heightPC="6"
		backgroundColor="0:0:0" foregroundColor="255:255:255">
		<script>runningHeadTwo;</script>
		<widthPC>
			<script>
				if ((runningHeadTwo == null) || (runningHeadTwo == ""))
					0;
				else
					runningHeadWidthPC;
			</script>
		</widthPC>
	</text>

	<text redraw="yes" align="left" fontSize="20"
		offsetXPC="0" offsetYPC="6"
		widthPC="0" heightPC="6"
		backgroundColor="0:0:0" foregroundColor="255:255:255">
		<script>selectClipStatusOne;</script>
		<widthPC><script>selectClipStatusWidthPC;</script></widthPC>
	</text>

	<text redraw="yes" align="left" fontSize="20"
		offsetXPC="0" offsetYPC="12"
		widthPC="0" heightPC="6"
		backgroundColor="0:0:0" foregroundColor="255:255:255">
		<script>selectClipStatusTwo;</script>
		<widthPC><script>selectClipStatusWidthPC;</script></widthPC>
	</text>

	<text redraw="yes" align="left" fontSize="20"
		offsetXPC="0" offsetYPC="6"
		widthPC="0" heightPC="6"
		backgroundColor="0:0:0" foregroundColor="255:255:0">
		<script>showCCStatus;</script>
		<widthPC><script>showCCStatusWidthPC;</script></widthPC>
		<foregroundColor>
			<script>
				if ((showCCStatusColor == null) || (showCCStatusColor == ""))
					"255:255:0";
				else
					showCCStatusColor;
			</script>
		</foregroundColor>
	</text>

	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.4" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - 0.1;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.2" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - 0.1;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.4" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - (-0.2);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.2" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - (-0.2);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.3" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundColor;</script></foregroundColor>
	</text>

	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.4" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - 0.1;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.2" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - 0.1;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.4" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - (-0.2);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.2" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - (-0.2);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.3" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>ccTextOffsetYPC - ccTextHeightPC;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundColor;</script></foregroundColor>
	</text>

	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.4" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC - 0.1;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.2" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC - 0.1;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.4" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC - (-0.2);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.2" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC - (-0.2);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.3" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundColor;</script></foregroundColor>
	</text>

	<progressBar backgroundColor="-1:-1:-1"
		offsetXPC="10" offsetYPC="64"
		widthPC="80" heightPC="24">

		<bar offsetXPC="45" offsetYPC="46"
			widthPC="55" heightPC="10"
			barColor="200:200:200"
			progressColor="26:129:211"
			bufferColor="-1:-1:-1"
			cornerRounding="10" />

		<text align="left" fontSize="20"
			offsetXPC="3" offsetYPC="0"
			widthPC="97" heightPC="24"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>
				currentTitle;
			</script>
		</text>

		<text align="left" fontSize="20"
			offsetXPC="5" offsetYPC="40"
			widthPC="40" heightPC="24"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>
				if (playStatus == 2) {
					showstr = "讀取資料中...";
				}
				else {
					now = Add(n, 1);
					showstr = "正在載入第 " + now + " / " + itemCount + " 段";
				}
				showstr;
			</script>
		</text>

		<text align="left" fontSize="20"
			offsetXPC="3" offsetYPC="80"
			widthPC="97" heightPC="24"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>
				if ((inputNumCount == 0) ||
						((inputNumCount == itemCountDigits) &amp;&amp;
						((curNumVal &lt; 1) || (curNumVal &gt; itemCount)))) {
					str = "[藍]字幕 | [信息] | [上下頁]±1 | {[↔]±1,[↕]±10,[數字]}+[放大]";
				}
				else {
					str = "[藍]字幕 | [信息] | [上下頁]±1 | {[↔]±1,[↕]±10} [放大]播第 " + curNumVal + " 項";
				}
				str;
			</script>
		</text>

		<destructor offsetXPC="0" offsetYPC="0"
			widthPC="100" heightPC="100"
			Color="-1:-1:-1">
		</destructor>

	</progressBar>

	<onUserInput>
		<script>
			ret = "false";
			userInput = currentUserInput();

			if (userInput == "video_stop") {
				startVideo = 0;
				postMessage("return");
				ret = "true";
			}
			else if (userInput == "option_blue") {
				/* Toggle the closed caption display */
				ccTextWidthPC = 100 - ccTextWidthPC;

				if (ccDataCount &gt; 0) {
					if (ccTextWidthPC == 0) {
						showCCStatus = "字幕：隱藏";
						showCCStatusColor = "";
					}
					else {
						showCCStatus = "字幕：顯示";
						showCCStatusColor = "";
					}
				}
				else {
					showCCStatus = "無字幕資訊";
					showCCStatusColor = "255:0:0";
				}
				showCCStatusWidthPC = 100;
				showCCStatusTimeMark = pbCurInt;

				ret = "true";
			}
			else if (userInput == "display") {
				/* If there is no extra information present, try again */
				if ((runningHeadTwo == null) || (runningHeadTwo == "")) {
					runningHeadTwo = readStringFromFile(extraInfoFile);
					if ((runningHeadTwo == null) || (runningHeadTwo == "")) {
						runningHeadTwo = getStringArrayAt(extraInfoArray, n);
					}
				}

				/* Pressing display always hides the CC status */
				showCCStatusWidthPC = 0;

				/* Pressing display always hides the select clip status */
				selectClip = 0;
				selectClipStatusWidthPC = 0;
				inputNumCount = 0;
				inputNumVal = -1;
				curNumVal = -1;

				/* Toggle the playback status display */
				runningHeadWidthPC = displayRunningHeadWidthPC - runningHeadWidthPC;
				ret = "true";
			}
			else if ((selectClip == 1) &amp;&amp; (userInput == "zoom")) {

				selectClip = 0;
				selectClipStatusWidthPC = 0;

				startVideo = 1;
				/* Set n to play */
				n = clipToPlay;

				if (itemCount &gt; 0)
					postMessage("video_stop");

				ret = "true";
			}
			else if (userInput == "pagedown") {

				startVideo = 1;

				/* Set n to play */
				n = Add(n, 1);

				if (itemCount &gt; 0)
					postMessage("video_stop");

				ret = "true";
			}
			else if (userInput == "pageup") {

				startVideo = 1;

				/* Set n to play */
				n = Minus(n, 1);

				if (n &lt; 0)
					n = 0;
				else if (itemCount &gt; 0)
					postMessage("video_stop");

				ret = "true";
			}
			else if (
				(userInput == "down") ||
				(userInput == "up") ||
				(userInput == "right") ||
				(userInput == "left") ||
				(userInput == "one") ||
				(userInput == "two") ||
				(userInput == "three") ||
				(userInput == "four") ||
				(userInput == "five") ||
				(userInput == "six") ||
				(userInput == "seven") ||
				(userInput == "eight") ||
				(userInput == "nine") ||
				(userInput == "zero")
			) {
				if (
					(userInput == "one") ||
					(userInput == "two") ||
					(userInput == "three") ||
					(userInput == "four") ||
					(userInput == "five") ||
					(userInput == "six") ||
					(userInput == "seven") ||
					(userInput == "eight") ||
					(userInput == "nine") ||
					(userInput == "zero")
				) {
					if (userInput == "one") {
						inputNumVal = 1;
					}
					else if (userInput == "two") {
						inputNumVal = 2;
					}
					else if (userInput == "three") {
						inputNumVal = 3;
					}
					else if (userInput == "four") {
						inputNumVal = 4;
					}
					else if (userInput == "five") {
						inputNumVal = 5;
					}
					else if (userInput == "six") {
						inputNumVal = 6;
					}
					else if (userInput == "seven") {
						inputNumVal = 7;
					}
					else if (userInput == "eight") {
						inputNumVal = 8;
					}
					else if (userInput == "nine") {
						inputNumVal = 9;
					}
					else if (userInput == "zero") {
						inputNumVal = 0;
					}

					if ((inputNumCount == 0) || (inputNumCount == itemCountDigits)) {
						inputNumCount = 1;
						curNumVal = inputNumVal;
					}
					else {
						inputNumCount = inputNumCount + 1;
						curNumVal = (10*curNumVal) + inputNumVal;
					}

					if ((curNumVal &gt;= 1) &amp;&amp; (curNumVal &lt;= itemCount)) {
						if (selectClip == 1)
							clipToPlay = (curNumVal - 1);
					}
					else if ((inputNumVal &gt;= 1) &amp;&amp; (inputNumVal &lt;= itemCount)) {
						/* Keep the last digit which makes the value out of range unless invalid */
						inputNumCount = 1;
						curNumVal = inputNumVal;
						if (selectClip == 1)
							clipToPlay = (curNumVal - 1);
					}
					else {
						inputNumCount = 0;
						inputNumVal = -1;
						curNumVal = -1;
					}
				}

				if (selectClip == 0) {
					/* Selecting clips always hides the CC status */
					showCCStatusWidthPC = 0;

					/* Selecting clips always hides the playback status display */
					runningHeadWidthPC = 0;

					/* Toggle the select clip display */
					selectClip = 1;
					selectClipStatusWidthPC = displaySelectClipStatusWidthPC;
					if ((inputNumCount == 0) ||
							((inputNumCount == itemCountDigits) &amp;&amp;
							((curNumVal &lt; 1) || (curNumVal &gt; itemCount)))) {
						clipToPlay = n;
					}
					else {
						clipToPlay = (curNumVal - 1);
					}
				}
				else if (
					(userInput == "down") ||
					(userInput == "up") ||
					(userInput == "right") ||
					(userInput == "left")
				) {
					if (userInput == "down") {
						clipToPlay = Add(clipToPlay, 10);
					}
					else if (userInput == "up") {
						clipToPlay = Minus(clipToPlay, 10);
					}
					else if (userInput == "right") {
						clipToPlay = Add(clipToPlay, 1);
					}
					else if (userInput == "left") {
						clipToPlay = Minus(clipToPlay, 1);
					}

					/* Make clipToPlay valid */
					if (clipToPlay &lt; 0)
						clipToPlay = 0;
					else if (clipToPlay &gt; (itemCount-1))
						clipToPlay = (itemCount-1);
				}

				selectClipTimeMark = pbCurInt;

				selectClipStatusOne = "按 [放大] 播放 [" + Add(clipToPlay, 1) + "] " + getStringArrayAt(titleArray, clipToPlay);
				selectClipStatusTwo = "現正播放 [" + now + "/" + itemCount + "] " + currentTitle;

				ret = "true";
			}
			ret;
		</script>
	</onUserInput>
</mediaDisplay>

<channel>
	<title>Media Play</title>
</channel>

</rss>
<?php
	require('00_suffix.php');
?>
