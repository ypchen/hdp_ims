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

	$sThisFile = $wholeURL;
	$urlPrevPage = $sThisFile . '?uid=' . $user_id  .
		'&amp;cc_prefs='        . urlencode($videoCCPrefs) .
		'&amp;fmt_prefs='       . urlencode($videoFmtPrefs) .
		'&amp;yv_rmt_src='      . urlencode($youtubeVideoRemoteSource) .
		'&amp;youtube_video='   . urlencode($localhostYoutubeVideo) .
		'&amp;query=' . ($page-1) . ',';
	if (isset($search)) {
		$urlPrevPage .= urlencode($search);
	}
	$urlPrevPage .= ',';
	if (isset($cat)) {
		$urlPrevPage .= urlencode($cat);
	}
	$urlPrevPage .= ',';
	if (isset($extra_02_query)) {
		$urlPrevPage .= urlencode($extra_02_query);
	}
	$urlNextPage = $sThisFile . '?uid=' . $user_id  .
		'&amp;cc_prefs='        . urlencode($videoCCPrefs) .
		'&amp;fmt_prefs='       . urlencode($videoFmtPrefs) .
		'&amp;yv_rmt_src='      . urlencode($youtubeVideoRemoteSource) .
		'&amp;youtube_video='   . urlencode($localhostYoutubeVideo) .
		'&amp;query=' . ($page+1) . ',';
	if (isset($search)) {
		$urlNextPage .= urlencode($search);
	}
	$urlNextPage .= ',';
	if (isset($cat)) {
		$urlNextPage .= urlencode($cat);
	}
	$urlNextPage .= ',';
	if (isset($extra_02_query)) {
		$urlNextPage .= urlencode($extra_02_query);
	}
?>

	focus = 0;
	message = "";

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

<mediaDisplay name="threePartsView"
	showHeader="no"
	showDefaultInfo="no"
	autoSelectMenu="no"
	autoSelectItem="no"
	selectMenuOnRight="no"
	itemXPC="<?php echo $itemXPC; ?>"
	itemYPC="<?php echo $itemYPC; ?>"
	itemWidthPC="<?php echo $itemWidthPC; ?>"
	itemHeightPC="<?php echo $itemHeightPC; ?>"
	itemPerPage="<?php echo $itemPerPage; ?>"
	itemImageWidthPC="0"
	itemImageHeightPC="0"
	itemGap="0"
	sliding="no"
	capXPC="<?php echo $itemXPC; ?>"
	capYPC="<?php echo $itemYPC; ?>"
	capWidthPC="50"
	capHeightPC="64"
	sideLeftWidthPC="0"
	sideRightWidthPC="0"
	headerImageWidthPC="0"
	backgroundColor="0:0:0"
	itemBackgroundColor="0:0:0"
	bottomYPC="90"
	imageFocus=""
	idleImageWidthPC="10"
	idleImageHeightPC="10"
>
	<image redraw="no"
		offsetXPC="5" offsetYPC="2.5"
		widthPC="15" heightPC="15"
		backgroundColor="-1:-1:-1">
		<script>
			imgLeftTop;
		</script>
	</image>

	<text redraw="no" align="center" fontSize="26"
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

	<text redraw="yes" align="left"
		fontSize="16" lines="5"
		offsetXPC="60" offsetYPC="<?php echo $itemYPC+(((7*$itemHeightPC)-$myImgHeight)/2); ?>"
		widthPC="<?php echo $myImgWidth; ?>" heightPC="<?php echo $myImgHeight; ?>"
		backgroundColor="0:0:0">
		<script>
			"";
		</script>
	</text>

	<image redraw="yes"
		offsetXPC="60" offsetYPC="<?php echo $itemYPC+(((7*$itemHeightPC)-$myImgHeight)/2); ?>"
		widthPC="<?php echo $myImgWidth; ?>" heightPC="<?php echo $myImgHeight; ?>"
		backgroundColor="0:0:0">
		<script>
			if (imgSpecial == null)	img;
			else imgSpecial;
		</script>
	</image>

	<text redraw="yes" align="left"
		fontSize="16" lines="1"
		offsetXPC="59" offsetYPC="<?php echo ($itemYPC+(7*$itemHeightPC)); ?>"
		widthPC="41" heightPC="<?php echo $itemHeightPC; ?>"
		backgroundColor="<?php echo $themeTextBackgroundColor; ?>"
		foregroundColor="<?php echo $themeTextForegroundColor; ?>">
		<script>
			noteOne;
		</script>
	</text>

	<text redraw="yes" align="left"
		fontSize="16" lines="1"
		offsetXPC="59" offsetYPC="<?php echo ($itemYPC+(8*$itemHeightPC)); ?>"
		widthPC="41" heightPC="<?php echo $itemHeightPC; ?>"
		backgroundColor="<?php echo $themeTextBackgroundColor; ?>"
		foregroundColor="<?php echo $themeTextForegroundColor; ?>">
		<script>
			noteTwo;
		</script>
	</text>

	<text redraw="yes" align="left"
		fontSize="16" lines="1"
		offsetXPC="59" offsetYPC="<?php echo ($itemYPC+(9*$itemHeightPC)); ?>"
		widthPC="41" heightPC="<?php echo $itemHeightPC; ?>"
		backgroundColor="<?php echo $themeTextBackgroundColor; ?>"
		foregroundColor="<?php echo $themeTextForegroundColor; ?>">
		<script>
			noteThree;
		</script>
	</text>

	<text redraw="yes" align="left"
		fontSize="16" lines="1"
		offsetXPC="59" offsetYPC="<?php echo ($itemYPC+(10*$itemHeightPC)); ?>"
		widthPC="41" heightPC="<?php echo $itemHeightPC; ?>"
		backgroundColor="<?php echo $themeTextBackgroundColor; ?>"
		foregroundColor="<?php echo $themeTextForegroundColor; ?>">
		<script>
			noteFour;
		</script>
	</text>

	<text redraw="no" align="left"
		fontSize="<?php echo $themeTipsFontSize; ?>" lines="1"
		offsetXPC="0" offsetYPC="<?php echo ($itemYPC+(11*$itemHeightPC)); ?>"
		widthPC="100" heightPC="<?php echo $itemHeightPC; ?>"
		backgroundColor="<?php echo $themeTipsBackgroundColor; ?>"
		foregroundColor="<?php echo $themeTipsForegroundColor; ?>">
		<script>
			if ((youtubeType == "mine") &amp;&amp; (typeExtraInfo == "playlists"))
				str = "[↕↔上下頁]移動 [紅/7]收藏夾 [綠/1]收本頁 [黃/3]收項目 [藍/9]指定清單";
			else if (contentType == "video") {
				str = "[↕↔上下頁]移動 [紅/7]收藏夾 [綠/1]收本頁 [黃/3]收項目 [藍/9]加入清單";
				if (fromType == "mine")
					str = "[↕↔上下頁]移動 [藍/9]加入清單 [停止/2]上移 [播放/8]下移 [信息/4]刪除";
			}
			else
				str = "[↕↔上下頁]移動 [紅/7]收藏夾 [綠/1]收本頁 [黃/3]收項目";
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
				(userInput == "left") ||
				(userInput == "right") ||
				(userInput == "option_red") ||
				(userInput == "seven") ||
				(userInput == "option_green") ||
				(userInput == "one") ||
				(userInput == "option_yellow") ||
				(userInput == "three")
			) {
				if (userInput == "pagedown") {
					idx = itemCount-1;
				}
				else if (userInput == "pageup") {
					idx = 0;
				}
				else if (userInput == "right") {
					idx -= -<?php echo $itemPerPage; ?>;
					if(idx &gt;= itemCount) idx = itemCount-1;
				}
				else if (userInput == "left") {
					idx -= <?php echo $itemPerPage; ?>;
					if(idx &lt; 0) idx = 0;
				}
				else if ((userInput == "option_red") || (userInput == "seven")) {
					jumpToLink("historyItem");
					redrawDisplay();
				}
				else if ((userInput == "option_green") || (userInput == "one")) {
					/* Parameters */
					dataFile   = dataFavorite;
					dataMax    = dataFavoriteMax;
					dataType   = "2";
					dataTitle  = "<?php echo $pageTitle; ?>";
					dataLink   = "<?php echo $currUrl; ?>";
					<?php include('08_history.record.inc'); ?>
					message    = " -- 本頁已收藏";
				}
				else if ((userInput == "option_yellow") || (userInput == "three")) {
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
				setFocusItemIndex(idx);
				redrawDisplay();
				ret = "true";
			}
			else if ((userInput == "option_blue") || (userInput == "nine")) {
				if ((youtubeType == "mine") &amp;&amp; (typeExtraInfo == "playlists")) {
					plID    = getStringArrayAt(idArray, (idx - hasPrevPage));
					plTitle = getStringArrayAt(titleArray, (idx - hasPrevPage));
					plDest  = null;
					plDest  = pushBackStringArray(plDest, plID);
					plDest  = pushBackStringArray(plDest, plTitle);
					writeStringToFile(filePlaylistDest, plDest);
					message = " -- 指定 \"" + plTitle + "\"";
				}
				else if (contentType == "video") {
					plDest = readStringFromFile(filePlaylistDest);
					if (((plID = getStringArrayAt(plDest, 0)) == null) || (plID == ""))
						message = " -- 錯誤: 未指定播放清單";
					else {
						plTitle = getStringArrayAt(plDest, 1);
						videoId = getStringArrayAt(idArray, (idx - hasPrevPage));

						requestBody = "{\"snippet\":{\"playlistId\":\"" + plID + "\",\"resourceId\":{\"kind\":\"youtube#video\",\"videoId\":\"" + videoId + "\"}}}";
						urlYVapi = urllocalhostYV
							+ "?query=yv_api"
							+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
							+ "&amp;cmd=" + urlEncode("playlistItems?part=snippet")
							+ "&amp;post=" + urlEncode(requestBody);
						xmlYVapi = loadXMLFile(urlYVapi);
						message  = " -- " . $site[0] . "失敗";
						if (xmlYVapi == null)
							msgSpecial = "叫用本機 youtube.video.php 失敗";
						else {
							code = getXMLText("root", "code");
							if (code != "200") {
								imgSpecial     = getXMLText("root", "imgSpecial");
								msgSpecial     = "[" + code + "]" + getXMLText("root", "msgSpecial");
								msgSpecialNote = getXMLText("root", "msgSpecialNote");
							}
							else
								message = " -- 已加入 \"" + plTitle + "\"";
						}
					}
				}
				redrawDisplay();
				ret = "true";
			}
			else if ((userInput == "video_stop") || (userInput == "two") ||
					(userInput == "video_play") || (userInput == "eight") ||
					(userInput == "display") || (userInput == "four")) {
				if ((contentType == "video") &amp;&amp; (fromType == "mine")) {
					videoId = getStringArrayAt(idArray, (idx - hasPrevPage));
					plID    = getStringArrayAt(plIdsArray, (idx - hasPrevPage));
					plPos   = Integer(getStringArrayAt(plPosArray, (idx - hasPrevPage)));
					if ((userInput == "video_stop") || (userInput == "two")) {
						if (plPos &gt; 0) {
							newPLPos = plPos-1;
							requestBody = "{\"id\":\"" + plID + "\",\"snippet\":{\"playlistId\":\"<?php echo $thisItemId; ?>\",\"position\":" + newPLPos + ",\"resourceId\":{\"kind\":\"youtube#video\",\"videoId\":\"" + videoId + "\"}}}";
							urlYVapi = urllocalhostYV
								+ "?query=yv_api"
								+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
								+ "&amp;cmd=" + urlEncode("playlistItems?part=snippet")
								+ "&amp;put=" + urlEncode(requestBody);
							xmlYVapi = loadXMLFile(urlYVapi);
							message  = " -- 上移失敗";
							if (xmlYVapi == null)
								msgSpecial = "叫用本機 youtube.video.php 失敗";
							else {
								code = getXMLText("root", "code");
								if (code != "200") {
									imgSpecial     = getXMLText("root", "imgSpecial");
									msgSpecial     = "[" + code + "]" + getXMLText("root", "msgSpecial");
									msgSpecialNote = getXMLText("root", "msgSpecialNote");
								}
								else {
									itemPerPage = yvItemPerPage;
									if ((newPLPos % itemPerPage) == (itemPerPage-1)) {
										if (newPLPos &gt;= itemPerPage)
											writeStringToFile(fileQueryMenuItemOnce, itemPerPage);
										else
											writeStringToFile(fileQueryMenuItemOnce, (itemPerPage-1));
										jumpToLink("prevPageItem");
									}
									else {
										writeStringToFile(fileQueryMenuItemOnce, (idx-1));
										jumpToLink("refreshItem");
									}
								}
							}
						}
						else
							message = " -- 無法上移";
					}
					else if ((userInput == "video_play") || (userInput == "eight")) {
						if (plPos &lt; (totalResults-1)) {
							newPLPos = Add(plPos,1);
							requestBody = "{\"id\":\"" + plID + "\",\"snippet\":{\"playlistId\":\"<?php echo $thisItemId; ?>\",\"position\":" + newPLPos + ",\"resourceId\":{\"kind\":\"youtube#video\",\"videoId\":\"" + videoId + "\"}}}";
							urlYVapi = urllocalhostYV
								+ "?query=yv_api"
								+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
								+ "&amp;cmd=" + urlEncode("playlistItems?part=snippet")
								+ "&amp;put=" + urlEncode(requestBody);
							xmlYVapi = loadXMLFile(urlYVapi);
							message  = " -- 下移失敗";
							if (xmlYVapi == null)
								msgSpecial = "叫用本機 youtube.video.php 失敗";
							else {
								code = getXMLText("root", "code");
								if (code != "200") {
									imgSpecial     = getXMLText("root", "imgSpecial");
									msgSpecial     = "[" + code + "]" + getXMLText("root", "msgSpecial");
									msgSpecialNote = getXMLText("root", "msgSpecialNote");
								}
								else {
									itemPerPage = yvItemPerPage;
									if ((newPLPos % itemPerPage) == 0) {
										writeStringToFile(fileQueryMenuItemOnce, "1");
										jumpToLink("nextPageItem");
									}
									else {
										writeStringToFile(fileQueryMenuItemOnce, Add(idx,1));
										jumpToLink("refreshItem");
									}
								}
							}
						}
						else
							message = " -- 無法下移";
					}
					else if ((userInput == "display") || (userInput == "four")) {
						urlYVapi = urllocalhostYV
							+ "?query=yv_api"
							+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
							+ "&amp;cmd=" + urlEncode("playlistItems?id=" + urlEncode(plID))
							+ "&amp;delete=YES";
						xmlYVapi = loadXMLFile(urlYVapi);
						message  = " -- 刪除失敗";
						if (xmlYVapi == null)
							msgSpecial = "叫用本機 youtube.video.php 失敗";
						else {
							code = getXMLText("root", "code");
							if ((code != "200") &amp;&amp; (code != "204")) {
								imgSpecial     = getXMLText("root", "imgSpecial");
								msgSpecial     = "[" + code + "]" + getXMLText("root", "msgSpecial");
								msgSpecialNote = getXMLText("root", "msgSpecialNote");
							}
							else {
								if (plPos &lt; (totalResults-1)) {
									writeStringToFile(fileQueryMenuItemOnce, idx);
									jumpToLink("refreshItem");
								}
								else {
									itemPerPage = yvItemPerPage;
									if ((idx - hasPrevPage) == 0) {
										if (plPos &gt; itemPerPage)
											writeStringToFile(fileQueryMenuItemOnce, itemPerPage);
										else
											writeStringToFile(fileQueryMenuItemOnce, (itemPerPage-1));
										jumpToLink("prevPageItem");
									}
									else {
										writeStringToFile(fileQueryMenuItemOnce, (idx-1));
										jumpToLink("refreshItem");
									}
								}
							}
						}
					}
					redrawDisplay();
					ret = "true";
				}
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

<?php
	if (!empty($useItemTemplate)) {
		switch ($useItemTemplate) {
			case 'YouTube':
?>
<item_template>
	<title><script>
		idx = getQueryItemIndex();
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1))
			"上一頁";
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1))
			"下一頁";
		else
			getStringArrayAt(titleArray, (idx - hasPrevPage));
	</script></title>
	<link><script>
		idx = getQueryItemIndex();
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1)) {
			writeStringToFile(fileQueryMenuItem, "0");
			"<?php echo $urlPrevPage; ?>";
		}
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1)) {
			writeStringToFile(fileQueryMenuItem, "0");
			"<?php echo $urlNextPage; ?>";
		}
		else {
			writeStringToFile(fileQueryMenuItem, getFocusItemIndex());
			kind = getStringArrayAt(kindArray, (idx - hasPrevPage));
			if (kind == "video") {
				"<?php echo $scriptsURLprefix . '/' . $myBaseName . '.link.php?uid=' . $user_id; ?>"
					+ "&amp;cc_prefs="      + "<?php echo urlencode($videoCCPrefs); ?>"
					+ "&amp;fmt_prefs="     + "<?php echo urlencode($videoFmtPrefs); ?>"
					+ "&amp;yv_rmt_src="    + "<?php echo urlencode($youtubeVideoRemoteSource); ?>"
					+ "&amp;youtube_video=" + "<?php echo urlencode($localhostYoutubeVideo); ?>"
					+ "&amp;query=" + getStringArrayAt(idArray, (idx - hasPrevPage))
						+ "," + urlEncode(getStringArrayAt(titleArray, (idx - hasPrevPage)))
						+ "," + urlEncode("<?php echo $continueFlag; ?>" + "|" + contentCount + "|" + (idx - hasPrevPage));
			}
			else if (kind == "playlist") {
				urlPara = "playlistId";
				"<?php echo $scriptsURLprefix . '/' . $myBaseName . '.query.php?uid=' . $user_id; ?>"
					+ "&amp;cc_prefs="      + "<?php echo urlencode($videoCCPrefs); ?>"
					+ "&amp;fmt_prefs="     + "<?php echo urlencode($videoFmtPrefs); ?>"
					+ "&amp;yv_rmt_src="    + "<?php echo urlencode($youtubeVideoRemoteSource); ?>"
					+ "&amp;youtube_video=" + "<?php echo urlencode($localhostYoutubeVideo); ?>"
					+ "&amp;query=1"
						+ ",%26amp%3B" + urlPara + "%3D" + urlEncode(itemId = getStringArrayAt(idArray, (idx - hasPrevPage)))
						+ "," + urlEncode(getStringArrayAt(titleArray, (idx - hasPrevPage)))
						+ "," + urlEncode(kind + "|<?php echo $continueFlag; ?>|" + itemId + "|" + youtubeType);
			}
			else if (kind == "channel") {
				executeScript("getItemInfo");
				urlPara = "id";
				"<?php echo $scriptsURLprefix . '/' . $myBaseName . '.query.php?uid=' . $user_id; ?>"
					+ "&amp;cc_prefs="      + "<?php echo urlencode($videoCCPrefs); ?>"
					+ "&amp;fmt_prefs="     + "<?php echo urlencode($videoFmtPrefs); ?>"
					+ "&amp;yv_rmt_src="    + "<?php echo urlencode($youtubeVideoRemoteSource); ?>"
					+ "&amp;youtube_video=" + "<?php echo urlencode($localhostYoutubeVideo); ?>"
					+ "&amp;query=1"
						+ ",%26amp%3B" + urlPara + "%3D" + urlEncode(itemId = getStringArrayAt(idArray, (idx - hasPrevPage)))
						+ "," + urlEncode(getStringArrayAt(titleArray, (idx - hasPrevPage)))
						+ "," + urlEncode(kind + "|<?php echo $continueFlag; ?>|" + itemId);
			}
			else if (kind == "channel-playlist") {
				urlPara = "channelId";
				"<?php echo $scriptsURLprefix . '/' . $myBaseName . '.query.php?uid=' . $user_id; ?>"
					+ "&amp;cc_prefs="      + "<?php echo urlencode($videoCCPrefs); ?>"
					+ "&amp;fmt_prefs="     + "<?php echo urlencode($videoFmtPrefs); ?>"
					+ "&amp;yv_rmt_src="    + "<?php echo urlencode($youtubeVideoRemoteSource); ?>"
					+ "&amp;youtube_video=" + "<?php echo urlencode($localhostYoutubeVideo); ?>"
					+ "&amp;query=1"
						+ ",%26amp%3B" + urlPara + "%3D" + urlEncode(getStringArrayAt(idArray, (idx - hasPrevPage)))
						+ "," + urlEncode(getStringArrayAt(titleArray, (idx - hasPrevPage)))
						+ "," + urlEncode("search|<?php echo $continueFlag; ?>|&amp;amp;type=playlist");
			}
		}
	</script></link>
	<image><script>
		idx = getQueryItemIndex();
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1))
			"<?php echo myImage('left'); ?>";
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1))
			"<?php echo myImage('right'); ?>";
		else
			getStringArrayAt(imageArray, (idx - hasPrevPage));
	</script></image>
	<note_one><script>
		idx = getQueryItemIndex();
		kind = getStringArrayAt(kindArray, (idx - hasPrevPage));
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1))
			"";
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1))
			"";
		else
			"<?php echo $caption_publish . ': '; ?>" + getStringArrayAt(pubTimeArray, (idx - hasPrevPage));
	</script></note_one>
	<note_two><script>
		idx = getQueryItemIndex();
		kind = getStringArrayAt(kindArray, (idx - hasPrevPage));
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1))
			"";
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1))
			"";
		else {
			executeScript("getItemInfo");
			getStringArrayAt(itemInfo, 0);
		}
	</script></note_two>
	<note_three><script>
		idx = getQueryItemIndex();
		kind = getStringArrayAt(kindArray, (idx - hasPrevPage));
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1))
			"";
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1))
			"";
		else {
			executeScript("getItemInfo");
			getStringArrayAt(itemInfo, 1);
		}
	</script></note_three>
	<note_four><script>
		idx = getQueryItemIndex();
		kind = getStringArrayAt(kindArray, (idx - hasPrevPage));
		if ((idx == 0) &amp;&amp; (hasPrevPage == 1))
			"";
		else if ((idx == (itemCount-1)) &amp;&amp; (hasNextPage == 1))
			"";
		else {
			executeScript("getItemInfo");
			getStringArrayAt(itemInfo, 2);
		}
	</script></note_four>
	<mediaDisplay />
</item_template>

<getItemInfo>
	if (kind == "channel-playlist") {
		itemInfo = null;
		itemInfo = pushBackStringArray(itemInfo, "");
		itemInfo = pushBackStringArray(itemInfo, "");
		itemInfo = pushBackStringArray(itemInfo, "");
	}
	else {
		itemId = getStringArrayAt(idArray, (idx - hasPrevPage));
		kindItemId = kind + "Id_" + itemId;
		if (cachedItemId == kindItemId) {
			itemInfo = cachedItemInfo;
		}
		else {
			fileItemInfo = getStoragePath("tmp") + "ims_yv_api." + kindItemId;
			itemInfo = readStringFromFile(fileItemInfo);
			if ((itemInfo == null) || (itemInfo == "")) {
				if ((kind == "video") || (kind == "channel"))
					cmd = kind + "s?part=snippet,contentDetails,statistics&amp;id=" + itemId;
				else if (kind == "playlist")
					cmd = kind + "s?part=snippet,contentDetails&amp;id=" + itemId;
				urlYVapi = urllocalhostYV
							+ "?query=yv_api"
							+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
							+ "&amp;cmd=" + urlEncode(cmd);
				xmlYVapi = loadXMLFile(urlYVapi);
				if (xmlYVapi != null) {
					httpStatus = getXMLText("root", "code");
					if (httpStatus == "200") {
						itemInfo = null;
						if (kind == "video") {
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_uploader . ': '; ?>" + getXMLText("root", "snippet", "channelTitle"));
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_length . ': '; ?>" + getXMLText("root", "contentDetails", "duration"));
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_view . ': '; ?>" + getXMLText("root", "statistics", "viewCount"));
						}
						else if (kind == "playlist") {
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_uploader . ': '; ?>" + getXMLText("root", "snippet", "channelTitle"));
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_itemcount . ': '; ?>" + getXMLText("root", "contentDetails", "itemCount"));
						}
						else if (kind == "channel") {
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_subscriber . ': '; ?>" + getXMLText("root", "statistics", "subscriberCount"));
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_itemcount . ': '; ?>" + getXMLText("root", "statistics", "videoCount"));
							itemInfo = pushBackStringArray(itemInfo, "<?php echo $caption_view . ': '; ?>" + getXMLText("root", "statistics", "viewCount"));
							itemInfo = pushBackStringArray(itemInfo, getStringArrayAt(pubTimeArray, (idx - hasPrevPage)));
							plItem = "uploads";
							executeScript("saveChannelInfo");
							plItem = "favorites";
							executeScript("saveChannelInfo");
							plItem = "likes";
							executeScript("saveChannelInfo");
							plItem = "watchHistory";
							executeScript("saveChannelInfo");
							plItem = "watchLater";
							executeScript("saveChannelInfo");
						}
						cachedItemInfo = itemInfo;
						cachedItemId   = kindItemId;
						if ((youtubeType != "mine") || (typeExtraInfo != "playlists"))
							writeStringToFile(fileItemInfo, itemInfo);
					}
				}
			}
		}
	}
</getItemInfo>

<saveChannelInfo>
	if (((plID = getXMLText("root", "relatedPlaylists", plItem)) != null) &amp;&amp; (plID != "")) {
		itemInfo = pushBackStringArray(itemInfo, plItem);
		itemInfo = pushBackStringArray(itemInfo, plID);
	}
</saveChannelInfo>

<prevPageItem><link><?php echo $urlPrevPage; ?></link></prevPageItem>
<nextPageItem><link><?php echo $urlNextPage; ?></link></nextPageItem>
<?php
				break;
			default:
				break;
		}
	}
?>

<channel>

	<title><?php echo $pageTitle; ?></title>

<?php
	if (empty($disableStaticPageControl) && ($page > 1)) {
?>
	<item>
		<title>上一頁</title>
		<link><?php echo $urlPrevPage;?></link>
		<image><?php echo myImage('left'); ?></image>
		<mediaDisplay name="threePartsView" />
	</item>
<?php } ?>

<?php
	if ($pass_check) {
		include($myName . '.2.inc');
	}
?>

<?php
	if (empty($disableStaticPageControl) && (($page > 0) && (!isset($pageMax) || ($page < $pageMax)))) {
?>
	<item>
		<title>下一頁</title>
		<link><?php echo $urlNextPage;?></link>
		<image><?php echo myImage('right'); ?></image>
		<mediaDisplay name="threePartsView" />
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
