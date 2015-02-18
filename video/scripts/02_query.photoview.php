<?php
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');
	$myBaseName = basename($myName, '.query');

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
<onEnter>
<?php
	include('06_get.query.inc');

	ini_set('user_agent', $userAgent);

	if (isset($extra)) {
		// $extra may be changed by included scripts
		$extra_02_query = $extra;
	}
	else {
		unset($extra_02_query);
	}

	// To receive $extra propagated from included scripts
	unset($extra_02_query_from_inc);

	$itemTotal  = 0;
	$pass_check = true;
	try {
		include($myName . '.1.inc');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	// Replace the original $extra by the explicitly propagated one
	if (isset($extra_02_query_from_inc)) {
		$extra_02_query = $extra_02_query_from_inc;
	}

	// Default display parameters
	if (!isset($themeMainForegroundColor)) $themeMainForegroundColor = '255:255:255';
	if (!isset($themeMainBackgroundColor)) $themeMainBackgroundColor = '150:10:105';
	if (!isset($themeTextForegroundColor)) $themeTextForegroundColor = '255:255:255';
	if (!isset($themeTextBackgroundColor)) $themeTextBackgroundColor = '0:0:0';
	if (!isset($themeTipsForegroundColor)) $themeTipsForegroundColor = '255:255:0';
	if (!isset($themeTipsBackgroundColor)) $themeTipsBackgroundColor = $themeTextBackgroundColor;
	if (!isset($themeVersionForegroundColor)) $themeVersionForegroundColor = '0:140:140';
	if (!isset($themeVersionBackgroundColor)) $themeVersionBackgroundColor = '-1:-1:-1';
	if (!isset($themeItemForegroundColorFocused)) $themeItemForegroundColorFocused = $themeTextForegroundColor;
	if (!isset($themeItemBackgroundColorFocused)) $themeItemBackgroundColorFocused = $themeMainBackgroundColor;
	if (!isset($themeItemForegroundColorUnfocused)) $themeItemForegroundColorUnfocused = '140:140:140';
	if (!isset($themeItemBackgroundColorUnfocused)) $themeItemBackgroundColorUnfocused = $themeTextBackgroundColor;
	if (!isset($themeItemFontSizeFocused)) $themeItemFontSizeFocused = '16';
	if (!isset($themeItemFontSizeUnfocused)) $themeItemFontSizeUnfocused = $themeItemFontSizeFocused;
	if (!isset($themeTipsFontSize)) $themeTipsFontSize = '16';
	if (!isset($themeVersionFontSize)) $themeVersionFontSize = '10';

	$titleComponents = explode('.', $myBaseName);
	$pageTitleBaseElements = explode('__', $titleComponents[0]);
	$pageTitleBase = $pageTitleBaseElements[0];

	$pageTitle = $pageTitleBase;
	if (isset($cat)) {
		$pageTitle = $pageTitle . ': ' . $cat;
	}
	if ($page > 0) {
		$pageTitle = $pageTitle . ' (第 ' . $page . ' 頁)';
	}

	// Create my own link
	$params  = str_replace('&', '&amp;', $_SERVER['QUERY_STRING']);
	$currUrl = $scriptsURLprefix . '/' . $myName . '.php?' . $params;

	// Create history link
	$historyUrl = $scriptsURLprefix . '/history.php?uid=' . $user_id;
?>

	focus = 0;
	message = "";
	inputNumCount = 0;
	inputNumVal = -1;
	curNumVal = -1;

	dataBrowse   = "<?php echo $fileBrowse; ?>";
	dataWatch    = "<?php echo $fileWatch; ?>";
	dataFavorite = "<?php echo $fileFavorite; ?>";

	dataBrowseMax   = <?php echo $maxBrowse; ?>;
	dataWatchMax    = <?php echo $maxWatch; ?>;
	dataFavoriteMax = <?php echo $maxFavorite; ?>;

	history = <?php echo $history; ?>;
	if (history == 0) {
		/* Parameters */
		dataFile   = dataBrowse;
		dataMax    = dataBrowseMax;
		dataType   = "2";
		dataTitle  = "<?php echo $pageTitle; ?>";
		dataLink   = "<?php echo $currUrl; ?>";
		<?php include('08_history.record.inc'); ?>
	}

	fileQueryMenuItem     = getStoragePath("tmp") + "<?php echo 'ims_query.' . $myBaseName . '-' . $uniquePageId . '.dat'; ?>";
	fileQueryMenuItemOnce = getStoragePath("tmp") + "<?php echo 'ims_query.' . $myBaseName . '-once.dat'; ?>";

	if (dynamicItem == 1) {
		itemCount = itemSize;
		queryMenuItem = readStringFromFile(fileQueryMenuItem);
		if ((queryMenuItem == null) || (queryMenuItem == ""))
			queryMenuItem = 0;
		else
			queryMenuItem = Integer(queryMenuItem);
	}
	else
		itemCount = getPageInfo("itemCount");

	queryMenuItemOnce = readStringFromFile(fileQueryMenuItemOnce);
	if ((queryMenuItemOnce != null) &amp;&amp; (queryMenuItemOnce != "")) {
		queryMenuItem = Integer(queryMenuItemOnce);
		writeStringToFile(fileQueryMenuItemOnce, "");
	}
	setFocusItemIndex(queryMenuItem);

	setRefreshTime(200);

	x = itemCount;
	<?php include('00_utils.digits.inc'); ?>
	itemCountDigits = y;
</onEnter>

<onExit>
	writeStringToFile(fileQueryMenuItem, getFocusItemIndex());
</onExit>

<onRefresh>
	setRefreshTime(-1);
	itemCount = getPageInfo("itemCount");
	x = itemCount;
	<?php include('00_utils.digits.inc'); ?>
	itemCountDigits = y;
	redrawDisplay();
</onRefresh>

<mediaDisplay name="photoView"
	showHeader="no"
	showDefaultInfo="no"
	autoSelectItem="yes"
	itemGapXPC="0"
	itemGapYPC="0"
	itemWidthPC="<?php echo $itemWidthPC; ?>"
	itemHeightPC="<?php echo $itemHeightPC; ?>"
	itemAlignt="center"
	viewAreaXPC="0"
	viewAreaYPC="0"
	viewAreaWidthPC="100"
	viewAreaHeightPC="100"
	rowCount="<?php echo $rowCount; ?>"
	columnCount="<?php echo $columnCount; ?>"
	centerXPC="<?php echo $itemXPC; ?>"
	centerYPC="<?php echo $itemYPC; ?>"
	centerWidthPC="100"
	centerHeightPC="100"
	drawItemBorder="yes"
	backgroundColor="0:0:0"
	itemBackgroundColor="0:0:0"
	itemBorderColor="0:200:0"
>
	<image redraw="no"
		offsetXPC="5" offsetYPC="2.5"
		widthPC="15" heightPC="15"
		backgroundColor="-1:-1:-1">
		<script>
			imgLeftTop;
		</script>
	</image>

	<text align="center" fontSize="26"
		offsetXPC="0" offsetYPC="0" widthPC="100" heightPC="20"
		backgroundColor="<?php echo $themeMainBackgroundColor; ?>"
		foregroundColor="<?php echo $themeMainForegroundColor; ?>">
		<script>
			getPageInfo("pageTitle");
		</script>
	</text>

	<text redraw="yes" fontSize="20"
		offsetXPC="82" offsetYPC="13.5"
		widthPC="20" heightPC="6"
		backgroundColor="<?php echo $themeMainBackgroundColor; ?>"
		foregroundColor="<?php echo $themeMainForegroundColor; ?>">
		<script>
			"" + Add(focus, 1) + " / " + itemCount;
		</script>
	</text>

	<text redraw="no" align="left"
		fontSize="<?php echo $themeTipsFontSize; ?>" lines="1"
		offsetXPC="0" offsetYPC="<?php echo ($itemYPC+(11*$itemHeightPC)); ?>"
		widthPC="100" heightPC="<?php echo $itemHeightPC; ?>"
		backgroundColor="<?php echo $themeTipsBackgroundColor; ?>"
		foregroundColor="<?php echo $themeTipsForegroundColor; ?>">
		<script>
			if ((inputNumCount == 0) ||
					((inputNumCount == itemCountDigits) &amp;&amp;
					((curNumVal &lt; 1) || (curNumVal &gt; itemCount)))) {
				str = "[↕↔上下頁]移動 [紅]收藏夾 [綠]收本頁 [黃]收項目 [數字直選]";
			}
			else {
				str = "[↕↔上下頁]移動 [紅]收藏夾 [綠]收本頁 [黃]收項目 第 " + curNumVal + " 項";
			}
			str + message;
		</script>
	</text>

	<text redraw="no" align="right"
		fontSize="<?php echo $themeVersionFontSize; ?>" lines="1"
		offsetXPC="88" offsetYPC="<?php echo ($itemYPC+(11*$itemHeightPC)); ?>"
		widthPC="9" heightPC="<?php echo ($itemHeightPC*1.4); ?>"
		backgroundColor="<?php echo $themeVersionBackgroundColor; ?>"
		foregroundColor="<?php echo $themeVersionForegroundColor; ?>">
		<script>
			"<?php echo $imsVersion; ?>";
		</script>
	</text>

	<text redraw="yes" align="center"
		fontSize="22"
		offsetXPC="0" offsetYPC="90"
		widthPC="100" heightPC="8"
		backgroundColor="<?php echo $themeMainBackgroundColor; ?>"
		foregroundColor="<?php echo $themeMainForegroundColor; ?>">
		<script>
			if (msgSpecial == null)	itemTitle;
			else msgSpecial;
		</script>
	</text>

	<idleImage>image/<?php echo $idleImagePrefix; ?>1.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>2.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>3.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>4.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>5.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>6.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>7.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>8.png</idleImage>

	<itemDisplay>
		<text align="left" lines="1"
			offsetXPC="0" offsetYPC="0"
			widthPC="100" heightPC="100">
			<script>
				idx = getQueryItemIndex();
				focus = getFocusItemIndex();
				if(focus == idx) {
					itemTitle  = getItemInfo(idx, "title");
					noteOne    = getItemInfo(idx, "note_one");
					noteTwo    = getItemInfo(idx, "note_two");
					noteThree  = getItemInfo(idx, "note_three");
					noteFour   = getItemInfo(idx, "note_four");
					img        = getItemInfo(idx, "image");
					if (img == null) {
						img = "<?php echo siteImage($myBaseName); ?>";
					}
					imgLeftTop = getItemInfo(idx, "channelImage");
					if (imgLeftTop == null) {
						imgLeftTop = "<?php echo siteImage($myBaseName); ?>";
					}
				}

				strItemTitle = "" + Add(idx, 1) + ":　" + getItemInfo(idx, "title");
				numBoundary  = 9;
				maxDigits    = itemCountDigits;
				if (maxDigits &lt; 2) maxDigits = 2;
				while (maxDigits &gt; 1) {
					if (idx &lt; numBoundary) {
						strItemTitle = "0" + strItemTitle;
					}
					numBoundary = (10 * numBoundary) + 9;
					maxDigits -= 1;
				}
				strItemTitle;
			</script>
			<fontSize>
				<script>
					idx = getQueryItemIndex();
					focus = getFocusItemIndex();
					if(focus == idx) "<?php echo $themeItemFontSizeFocused; ?>";
					else "<?php echo $themeItemFontSizeUnfocused; ?>";
				</script>
			</fontSize>
			<foregroundColor>
				<script>
					idx = getQueryItemIndex();
					focus = getFocusItemIndex();
					if(focus == idx) "<?php echo $themeItemForegroundColorFocused; ?>";
					else "<?php echo $themeItemForegroundColorUnfocused; ?>";
				</script>
			</foregroundColor>
			<backgroundColor>
				<script>
					idx = getQueryItemIndex();
					focus = getFocusItemIndex();
					if(focus == idx) "<?php echo $themeItemBackgroundColorFocused; ?>";
					else "<?php echo $themeItemBackgroundColorUnfocused; ?>";
				</script>
			</backgroundColor>
		</text>
	</itemDisplay>

	<onUserInput>
		<script>
			ret = "false";
			message = "";
			userInput = currentUserInput();
			idx = Integer(getFocusItemIndex());
			if (
				(userInput == "pagedown") ||
				(userInput == "pageup") ||
				(userInput == "option_red") ||
				(userInput == "option_green") ||
				(userInput == "option_yellow") ||
				(userInput == "display") ||
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
				if (userInput == "pagedown") {
					idx = itemCount-1;
				}
				else if (userInput == "pageup") {
					idx = 0;
				}
				else if (userInput == "option_red") {
					jumpToLink("historyItem");
					redrawDisplay();
				}
				else if (userInput == "option_green") {
					/* Parameters */
					dataFile   = dataFavorite;
					dataMax    = dataFavoriteMax;
					dataType   = "2";
					dataTitle  = "<?php echo $pageTitle; ?>";
					dataLink   = "<?php echo $currUrl; ?>";
					<?php include('08_history.record.inc'); ?>
					message    = " -- 本頁已收藏";
				}
				else if (userInput == "option_yellow") {
					/* Parameters */
					dataFile   = dataFavorite;
					dataMax    = dataFavoriteMax;
					dataTitle  = getItemInfo(idx, "title");
					dataLink   = getItemInfo(idx, "link");
					clickPlay  = getItemInfo(idx, "click_play");
					if ((dataTitle == "上一頁") || (dataTitle == "下一頁")) {
						message = " -- 無法直接收藏: " + dataTitle;
					}
					else {
						dataTitle  = "<?php echo $pageTitleBase; ?>: " + dataTitle;
						if (clickPlay != null) {
							dataType   = "1";
							if (clickPlay == "yes") {
								dlok = loadXMLFile(dataLink);
								if (dlok != null) {
									dataType = "0";
									dataLink = getXMLText("rss", "channel", "item", "link");
								}
							}
						}
						else {
							dataType   = "2";
						}
						<?php include('08_history.record.inc'); ?>
						message = " -- 項目已收藏";
					}
				}
				else {
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
						idx = (curNumVal - 1);
					}
					else if ((inputNumVal &gt;= 1) &amp;&amp; (inputNumVal &lt;= itemCount)) {
						/* Keep the last digit which makes the value out of range unless invalid */
						inputNumCount = 1;
						curNumVal = inputNumVal;
						idx = (curNumVal - 1);
					}
					else {
						inputNumCount = 0;
						inputNumVal = -1;
						curNumVal = -1;
					}
				}
				setFocusItemIndex(idx);
				redrawDisplay();
				ret = "true";
			}
			else if (userInput == "enter") {
				if (getItemInfo(idx, "click_play") == "yes") {
					showIdle();
					dlok = loadXMLFile(getItemInfo(idx, "link"));
					if (dlok != null) {
						realURL = getXMLText("rss", "channel", "item", "link");
						if ((history == 0) &amp;&amp; (realURL != null) &amp;&amp; (realURL != "")) {
							/* Parameters */
							dataFile   = dataWatch;
							dataMax    = dataWatchMax;
							dataType   = "0";
							dataTitle  = "<?php echo $pageTitleBase; ?>: " + getItemInfo(idx, "title");
							dataLink   = realURL;
							<?php include('08_history.record.inc'); ?>
						}
						playItemURL(realURL, 0);
					}
					cancelIdle();
				}
			}
			ret;
		</script>
	</onUserInput>
</mediaDisplay>

<getInputFromUser>
	inputPrefs = readStringFromFile("<?php echo $fileLocalInputPrefs; ?>");
	input = null;
	if ((inputPrefs == null) || (inputPrefs == "")
	 || (((inputType = getStringArrayAt(inputPrefs, 0)) != "1") &amp;&amp; (inputType != "2"))
	 || ((inputMethod = getStringArrayAt(inputPrefs, 1)) == null)
	 || (inputMethod == "")) {
		input = getInput("Enter a keyword");
	}
	else {
		input = doModalRss(inputMethod, "mediaDisplay", "search", 0);
	}
</getInputFromUser>

<channel>

	<title><?php echo $pageTitle; ?></title>

<?php
	if($page > 1) {
?>
	<item>
		<?php
			$sThisFile = $wholeURL;
			$url = $sThisFile . '?uid=' . $user_id  .
				'&amp;cc_prefs='        . urlencode($videoCCPrefs) .
				'&amp;fmt_prefs='       . urlencode($videoFmtPrefs) .
				'&amp;yv_rmt_src='      . urlencode($youtubeVideoRemoteSource) .
				'&amp;youtube_video='   . urlencode($localhostYoutubeVideo) .
				'&amp;query=' . ($page-1) . ',';
			if (isset($search)) {
				$url = $url . urlencode($search);
			}
			$url = $url . ',';
			if (isset($cat)) {
				$url = $url . urlencode($cat);
			}
			$url = $url . ',';
			if (isset($extra_02_query)) {
				$url = $url . urlencode($extra_02_query);
			}
		?>
		<title>上一頁</title>
		<link><?php echo $url;?></link>
		<annotation>上一頁</annotation>
		<image><?php echo myImage('left'); ?></image>
		<mediaDisplay name="photoView" />
	</item>
<?php } ?>

<?php
	if ($pass_check) {
		include($myName . '.2.inc');
	}
?>

<?php
	if (($page > 0) && (!isset($pageMax) || ($page < $pageMax))) {
?>
	<item>
		<?php
			$sThisFile = $wholeURL;
			$url = $sThisFile . '?uid=' . $user_id  .
				'&amp;cc_prefs='        . urlencode($videoCCPrefs) .
				'&amp;fmt_prefs='       . urlencode($videoFmtPrefs) .
				'&amp;yv_rmt_src='      . urlencode($youtubeVideoRemoteSource) .
				'&amp;youtube_video='   . urlencode($localhostYoutubeVideo) .
				'&amp;query=' . ($page+1) . ',';
			if (isset($search)) {
				$url = $url . urlencode($search);
			}
			$url = $url . ',';
			if (isset($cat)) {
				$url = $url . urlencode($cat);
			}
			$url = $url . ',';
			if (isset($extra_02_query)) {
				$url = $url . urlencode($extra_02_query);
			}
		?>
		<title>下一頁</title>
		<link><?php echo $url;?></link>
		<annotation>下一頁</annotation>
		<image><?php echo myImage('right'); ?></image>
		<mediaDisplay name="photoView" />
	</item>
<?php } ?>

</channel>

<?php
	// refresh this page
	echo "<refreshItem>\r\n";
	echo "\t<link>$currUrl</link>\r\n";
	echo "</refreshItem>\r\n";

	// history
	echo "<historyItem>\r\n";
	echo "\t<link>$historyUrl</link>\r\n";
	echo "</historyItem>\r\n";
?>

</rss>
<?php
	}

	require('00_suffix.php');
?>
