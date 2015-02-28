<?php
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');
	$myBaseName = basename($myName, '.link');

	// Sites that are turned off
	if (strcasecmp($imsDirectory, 'video') == 0) {
		$sitesTurnedOff = explode(',', $imsTurnOffVideoSites);
	}
	else {
		$sitesTurnedOff = explode(',', $imsTurnOffAdultSites);
	}
	$myNameComponents = explode('.', $myName);
	if (in_array($myNameComponents[0], $sitesTurnedOff)) {
		header('Object not found', true, 404);
	}
	else {
?>
<?php
	echo "<?xml version=\"1.0\" encoding=\"UTF8\" ?>\r\n";
	echo "<rss version=\"2.0\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\">\r\n";
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
	$pageTitleBaseElements = explode('__', $titleComponents[0]);
	$pageTitleBase = $pageTitleBaseElements[0];

	$pageTitle = $pageTitleBase;
	if (isset($title)) {
		$pageTitle = $pageTitle . ': ' . $title;
	}

	// Create my own link
	$params  = str_replace('&', '&amp;', $_SERVER['QUERY_STRING']);
	$currUrl = $scriptsURLprefix . '/' . $myName . '.php?' . $params;
?>

<getContMsg>
	continueFlagTotal = 7;
	if (continueFlag == "0") contMsg = "{個別播放} ";
	else if (continueFlag == "1") contMsg = "{個別重覆} ";
	else if (continueFlag == "2") contMsg = "{隨機播放} ";
	else if (continueFlag == "3") contMsg = "{正序連續} ";
	else if (continueFlag == "4") contMsg = "{正序循環} ";
	else if (continueFlag == "5") contMsg = "{反序連續} ";
	else if (continueFlag == "6") contMsg = "{反序循環} ";
	else contMsg = "";
</getContMsg>

<onEnter>
	randSeed = 97;

	if (linkArray == null) {
		postMessage("return");
	}
	n = readStringFromFile(tmpItemSelected);
	if (n == null) {
		n = <?php echo (isset($iStart) ? $iStart : 0) ;?>;
	}
	else {
		n = Integer(n);
	}
	if ((continueFlag == null) || (continueFlag == "")) {
		continueFlag = "<?php echo (isset($continueFlag) ? $continueFlag : '3') ;?>";
	}
	executeScript("getContMsg");

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
	ccTextOffsetYPC = 81.22;
	ccTextHeightPC = 5.98;
	ccBackgroundColor = "-1:-1:-1";
	ccForegroundShadowColor = "0:0:0";
	ccTextWidthPC = 100;
	ccDataCount = 0;

	ccTextFontSizeData = readStringFromFile("<?php echo $fileLocalCCFSize; ?>");
	if ((ccTextFontSizeData == null) || (ccTextFontSizeData == "")) {
		ccTextFontSize = 24;
	}
	else {
		ccTextFontSize = Integer(ccTextFontSizeData);
	}

	ccForegroundColor = readStringFromFile("<?php echo $fileLocalCCFColor; ?>");
	if ((ccForegroundColor == null) || (ccForegroundColor == "")) {
		ccForegroundColor = "255:255:150";
	}

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

		pbCurTickShift = 0;
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

		pbCurTick = Add(pbCurTick, pbCurTickShift);
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
				pbLastInt = -1;
				pbTimeCount = 0;

				showCCStatus = "":
				showCCStatusData = "":
				showCCStatusColor = "":
				showCCStatusWidthPC = 0;
				showCCStatusTimeMark = 0;

				lastPlayStatus = -2;
				playStatus = -1;

				if (ccCleanAtPlayItemURL == 1) {
					writeStringToFile(extraInfoFile, "");
					writeStringToFile(ccDataCountFile, "0");
					writeStringToFile(ccDataStatusFile, "");
				}

				playItemURL(currentUrl, 0, "mediaDisplay", "previewWindow");
			}
			currentTitle = getStringArrayAt(titleArray, n);
			if (currentTitle == null) {
				currentTitle = "";
			}
			writeStringToFile(tmpItemSelected, n);
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
				if ((continueFlag == "0") ||
					((continueFlag == "3") &amp;&amp; ((n+1) &gt; (itemCount-1))) ||
					((continueFlag == "5") &amp;&amp; ((n-1) &lt; 0))) {
					playItemURL(-1, 1);
					setRefreshTime(-1);
					postMessage("return");
				}
				else {
					if ((continueFlag == "2") &amp;&amp; (itemCount &gt; 1)) {
						if (randSeed == 97) {
							urlYVRemoteSrc = "<?php echo $youtubeVideoRemoteSource; ?>";
							urllocalhostYV = "<?php echo $localhostYoutubeVideo; ?>";
							urlYVapi = urllocalhostYV
										+ "?query=get_a_random_int"
										+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc);
							xmlYVapi = loadXMLFile(urlYVapi);
							if (xmlYVapi == null)
								randSeed = 97;
							else
								randSeed = Integer(getXMLText("root", "int")) % 503;
						}

						m = n;
						while (m == n) {
							randSeed = Add((251*randSeed), 113) % 503;
							m = randSeed % itemCount;
						}
						n = m;
					}
					else if ((continueFlag == "3") || (continueFlag == "4"))
						n = Add(n, 1);
					else if ((continueFlag == "5") || (continueFlag == "6"))
						n = n-1;

					if (n &lt; 0)
						n = (itemCount-1);
					n = n % itemCount;
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
		<script>contMsg + runningHeadTwo;</script>
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
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - 0.12;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.22" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - 0.12;</script></offsetYPC>
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
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - (-0.10);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.22" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextThree;</script>
		<offsetYPC><script>((ccTextOffsetYPC - ccTextHeightPC) - ccTextHeightPC) - (-0.10);</script></offsetYPC>
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
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - 0.12;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.22" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - 0.12;</script></offsetYPC>
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
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - (-0.10);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.22" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextTwo;</script>
		<offsetYPC><script>(ccTextOffsetYPC - ccTextHeightPC) - (-0.10);</script></offsetYPC>
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
		<offsetYPC><script>ccTextOffsetYPC - 0.12;</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.22" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC - 0.12;</script></offsetYPC>
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
		<offsetYPC><script>ccTextOffsetYPC - (-0.10);</script></offsetYPC>
		<fontSize><script>ccTextFontSize;</script></fontSize>
		<widthPC><script>ccTextWidthPC;</script></widthPC>
		<heightPC><script>ccTextHeightPC;</script></heightPC>
		<backgroundColor><script>ccBackgroundColor;</script></backgroundColor>
		<foregroundColor><script>ccForegroundShadowColor;</script></foregroundColor>
	</text>
	<text redraw="yes" align="center" fontSize="20"
		offsetXPC="-3.22" offsetYPC="100"
		widthPC="0" heightPC="0"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:0">
		<script>ccTextOne;</script>
		<offsetYPC><script>ccTextOffsetYPC - (-0.10);</script></offsetYPC>
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

		<bar offsetXPC="40" offsetYPC="46"
			widthPC="55" heightPC="10"
			barColor="200:200:200"
			progressColor="26:129:211"
			bufferColor="-1:-1:-1"
			cornerRounding="10" />

		<text align="left" fontSize="20"
			offsetXPC="-1" offsetYPC="-40"
			widthPC="100" heightPC="24"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:150">
			<script>
				contMsg + "請於視訊順利播放後再進行選集、選段、或其他操作";
			</script>
		</text>

		<text align="left" fontSize="20"
			offsetXPC="-1" offsetYPC="0"
			widthPC="100" heightPC="24"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>currentTitle;</script>
		</text>

		<text align="left" fontSize="20"
			offsetXPC="1" offsetYPC="40"
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
			offsetXPC="-1" offsetYPC="80"
			widthPC="100" heightPC="24"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			<script>
				"[藍/9]字幕 [信息/4] [重覆/6] {[上下頁/↔]±1,[↕]±10}+[放大/5]";
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

			if ((userInput == "video_stop") || (userInput == "two")) {
				startVideo = 0;
				postMessage("return");
				ret = "true";
			}
			else if (
				(userInput == "option_red") ||
				(userInput == "seven") ||
				(userInput == "option_green") ||
				(userInput == "one") ||
				(userInput == "option_yellow") ||
				(userInput == "three") ||
				(userInput == "option_blue") ||
				(userInput == "nine")
			) {
				if ((userInput == "option_red") || (userInput == "seven")) {
					/* Delay */
					pbCurTickShift = Minus(pbCurTickShift, 1);
				}
				else if ((userInput == "option_green") || (userInput == "one")) {
					/* Speedup */
					pbCurTickShift = Add(pbCurTickShift, 1);
				}
				else if ((userInput == "option_yellow") || (userInput == "three")) {
					/* Reset */
					pbCurTickShift = 0;
				}
				else if ((userInput == "option_blue") || (userInput == "nine")) {
					/* Toggle the closed caption display */
					ccTextWidthPC = 100 - ccTextWidthPC;
				}

				if (ccDataCount &gt; 0) {
					if (ccTextWidthPC == 0) {
						showCCStatus = "字幕：隱藏 -- 時移(0.1s)：" + pbCurTickShift + " -- [紅/7]減慢 [綠/1]加速 [黃/3]重置";
						showCCStatusColor = "";
					}
					else {
						showCCStatus = "字幕：顯示 -- 時移(0.1s)：" + pbCurTickShift + " -- [紅/7]減慢 [綠/1]加速 [黃/3]重置";
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
			else if ((userInput == "display") || (userInput == "four")) {
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
				/* Toggle the playback status display */
				runningHeadWidthPC = displayRunningHeadWidthPC - runningHeadWidthPC;
				ret = "true";
			}
			else if ((selectClip == 1) &amp;&amp;
				((userInput == "zoom") || (userInput == "five"))) {

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
				(userInput == "video_repeat") ||
				(userInput == "six")
			) {
				if (selectClip == 0) {
					/* Selecting clips always hides the CC status */
					showCCStatusWidthPC = 0;

					/* Selecting clips always hides the playback status display */
					runningHeadWidthPC = 0;

					/* Toggle the select clip display */
					selectClip = 1;
					selectClipStatusWidthPC = displaySelectClipStatusWidthPC;

					clipToPlay = n;
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

				if ((userInput == "video_repeat") || (userInput == "six")) {
					continueFlag = (Add(continueFlag, 1) % continueFlagTotal);
					executeScript("getContMsg");
				}

				selectClipTimeMark = pbCurInt;

				selectClipStatusOne = "按 [放大/5] 播放 [" + Add(clipToPlay, 1) + "] " + getStringArrayAt(titleArray, clipToPlay);
				selectClipStatusTwo = contMsg + "現正播放 [" + now + "/" + itemCount + "] " + currentTitle;

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
	}

	require('00_suffix.php');
?>
