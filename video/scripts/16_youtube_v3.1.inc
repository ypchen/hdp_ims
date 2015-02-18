<?php
	$extraSettings = explode('|', $extra);
	$youtubeType   = $extraSettings[0];
	$typeExtraInfo = '';
	$fromType      = '';
	$continueFlag  = $extraSettings[1];

	// Disable the control for static items
	$disableStaticPageControl = true;
	$useItemTemplate = 'YouTube';

	$dataFilePath  = '/usr/local/etc/dvdplayer/';

	switch ($youtubeType) {
		case 'search':
			$apiCMD = 'search' .
					'?part=snippet' .
					((count($extraSettings) > 2) ? ($extraSettings[2]) : ('')) .
					$search;
			$appendSearchOrder = true;
			break;
		case 'playlist':
			$apiCMD = 'playlistItems' .
					'?part=snippet' .
					$search;
			$thisItemId	= ((count($extraSettings) > 2) ? ($extraSettings[2]) : (''));
			$fromType	= ((count($extraSettings) > 3) ? ($extraSettings[3]) : (''));
			break;
		case 'channel':
			$thisItemId	= $extraSettings[2];
			break;
		case 'mine':
			$apiCMD = $extraSettings[2] .
					'?part=snippet' . ((strcmp($extraSettings[2], 'channels') == 0) ? ',statistics' : '') .
					$search;
			$typeExtraInfo = $extraSettings[2];
			break;
	}
?>
	urlYVRemoteSrc   = "<?php echo $youtubeVideoRemoteSource; ?>";
	urllocalhostYV   = "<?php echo $localhostYoutubeVideo; ?>";
	dataFilePath     = "<?php echo $dataFilePath; ?>";
	youtubeType      = "<?php echo $youtubeType; ?>";
	typeExtraInfo    = "<?php echo $typeExtraInfo; ?>";
	fromType         = "<?php echo $fromType; ?>";
	fileSearchOrder  = dataFilePath + "ims_yv_search_order.dat";
	filePlaylistDest = dataFilePath + "ims_yv_playlist_dest.dat";
	fileItemPerPage  = dataFilePath + "ims_yv_item_per_page.dat"

	cachedItemId     = null;
	cachedItemInfo   = null;

	yvItemPerPage = getStringArrayAt(readStringFromFile(fileItemPerPage), 0);
	if ((yvItemPerPage == null) || (yvItemPerPage == ""))
		yvItemPerPage = <?php echo $defaultYVItemPerPage; ?>;
	else
		yvItemPerPage = Integer(yvItemPerPage);

	if (youtubeType != "channel") {
		apiCMD = "<?php echo $apiCMD; ?>" + "&amp;maxResults=" + yvItemPerPage;
<?php
		if (!empty($appendSearchOrder)) {
?>
		searchOrder = readStringFromFile(fileSearchOrder);
		orderName = getStringArrayAt(searchOrder, 0);
		orderPara = getStringArrayAt(searchOrder, 1);
		apiCMD = apiCMD + orderPara;
<?php
		}
?>
		page = <?php echo $page; ?>;
		filePageToken = dataFilePath + "ims_yv_api.pageToken." + page;
		if (page == 1) {
			pageToken = "";
			writeStringToFile(filePageToken, "");
		}
		pageToken = getStringArrayAt(readStringFromFile(filePageToken), 0);
		urlYVapi = urllocalhostYV
					+ "?query=yv_api"
					+ "&amp;yv_rmt_src=" + urlEncode(urlYVRemoteSrc)
					+ "&amp;page=" + page
					+ "&amp;type=" + "<?php echo $youtubeType; ?>"
					+ "&amp;cmd=" + urlEncode(apiCMD + pageToken);
		xmlYVapi = loadXMLFile(urlYVapi);
		if (xmlYVapi == null)
			msgSpecial = "叫用本機 youtube.video.php 失敗";
		else {
			code = getXMLText("root", "code");
			if (code != "200") {
				imgSpecial     = getXMLText("root", "imgSpecial");
				msgSpecial     = "[" + code + "]" + getXMLText("root", "msgSpecial");
				msgSpecialNote = getXMLText("root", "msgSpecialNote");
			}
		}

		hasNextPage  = Integer(getStringArrayAt(readStringFromFile(dataFilePath + "ims_yv_api.hasNextPage"), 0));
		hasPrevPage  = Integer(getStringArrayAt(readStringFromFile(dataFilePath + "ims_yv_api.hasPrevPage"), 0));

		dynamicItem  = 1;
		totalResults = Integer(getStringArrayAt(readStringFromFile(dataFilePath + "ims_yv_api.total"), 0));
		contentCount = Integer(getStringArrayAt(readStringFromFile(dataFilePath + "ims_yv_api.item_count"), 0));
		itemSize     = Add(Add(contentCount, hasNextPage), hasPrevPage);
		idArray      = readStringFromFile(dataFilePath + "ims_yv_api.ids");
		kindArray    = readStringFromFile(dataFilePath + "ims_yv_api.kinds");
		titleArray   = readStringFromFile(dataFilePath + "ims_yv_api.titles");
		imageArray   = readStringFromFile(dataFilePath + "ims_yv_api.images");
		pubTimeArray = readStringFromFile(dataFilePath + "ims_yv_api.pubtime");

		contentType  = getStringArrayAt(kindArray, 0);

		plIdsArray   = readStringFromFile(dataFilePath + "ims_yv_api.pl_ids");
		plPosArray   = readStringFromFile(dataFilePath + "ims_yv_api.pl_pos");
	}
	else {
		hasNextPage  = 0;
		hasPrevPage  = 0;

		dynamicItem  = 1;

		itemId = "<?php echo $thisItemId; ?>";
		fileItemInfo = getStoragePath("tmp") + "ims_yv_api.channelId_" + itemId;
		itemInfo = readStringFromFile(fileItemInfo);

		idArray      = null;
		kindArray    = null;
		titleArray   = null;
		imageArray   = null;
		pubTimeArray = null;

		itemSize = 0;
		pubTime = getStringArrayAt(itemInfo, 3);
		k = 4;
		while (((plItem = getStringArrayAt(itemInfo, k)) != null) &amp;&amp; (plItem != "")) {
			k = k+1;
			idArray    = pushBackStringArray(idArray, getStringArrayAt(itemInfo, k));
			kindArray  = pushBackStringArray(kindArray, "playlist");
			titleArray = pushBackStringArray(titleArray, plItem);
			pubTimeArray = pushBackStringArray(pubTimeArray, pubTime);
			k = k+1;
			itemSize = itemSize+1;
		}
		idArray    = pushBackStringArray(idArray, itemId);
		kindArray  = pushBackStringArray(kindArray, "channel-playlist");
		titleArray = pushBackStringArray(titleArray, "此頻道建立之播放清單");
		pubTimeArray = pushBackStringArray(pubTimeArray, pubTime);
		itemSize = itemSize+1;
		contentCount = itemSize;

		contentType  = getStringArrayAt(kindArray, 0);
	}
