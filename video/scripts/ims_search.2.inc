<channel>

<title>IMS 搜索 (本機輸入)</title>

	<item>
		<title>HAOIMS: 全網搜索</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("rss_file://./etc/ypInput/ypKeyboard.rss", "mediaDisplay", "search", 0);
			if (input != null) {
			    keyword = urlEncode(input);
			    searchUrl = "http://ims.haoims.com/ims/search.php?q=chl-search-word-" + keyword;
				sPath = "/usr/local/etc/dvdplayer/";
				searchPath=sPath+"haoims_search.dat";
				searchArray=readStringFromFile(searchPath);
				if (getStringArrayAt(searchArray, 19) != null) {
					searchArray = deleteStringArrayAt(searchArray, 0);
				}
				k=0;
				while (getStringArrayAt(searchArray, k) != null) {
					title=getStringArrayAt(searchArray, k);
					if(title==input) {
						searchArray = deleteStringArrayAt(searchArray, k);
					}
					else {
						k=k+1;
					}
				}
				searchArray=pushBackStringArray(searchArray, input);
				writeStringToFile(searchPath,searchArray);
				searchUrl;
			}
			else {
			    redrawDisplay();
			}
		</onClick>
		<?php echo siteLogo('haoims'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HAOIMS: 搜索紀錄</title>
		<link>http://ims.haoims.com/ims/fav.php?q=chl-search</link>
		<?php echo siteLogo('haoims'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HDPfans: 全網搜索</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("rss_file://./etc/ypInput/ypKeyboard.rss", "mediaDisplay", "search", 0);
			if (input != null) {
				keyword = urlEncode(input);
				searchUrl = "http://tv.hdpfans.com:80/sp_search.php?name=" + keyword;
				sPath = "/usr/local/etc/dvdplayer/";
				searchPath=sPath+"hdpfans_search.dat";
				searchArray=readStringFromFile(searchPath);
				if (getStringArrayAt(searchArray, 19) != null) {
					searchArray = deleteStringArrayAt(searchArray, 0);
				}
				k=0;
				while (getStringArrayAt(searchArray, k) != null) {
					title=getStringArrayAt(searchArray, k);
					if(title == input){
						searchArray = deleteStringArrayAt(searchArray, k);
					}
					else{
						k=k+1;
					}
				}
				searchArray=pushBackStringArray(searchArray, input);
				writeStringToFile(searchPath,searchArray);
				searchUrl;
			}
			else {
				redrawDisplay();
			}
		</onClick>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HDPfans: 站內搜索</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("rss_file://./etc/ypInput/ypKeyboard.rss", "mediaDisplay", "search", 0);
			if (input != null) {
				keyword = urlEncode(input);
				searchUrl = "http://tv.hdpfans.com:80/~rss.index.search/rss/1/ajax/1/?keyword=" + keyword;
				searchUrl;
			}
			else {
				redrawDisplay();
			}
		</onClick>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HDPfans: 最近搜索紀錄</title>
		<link>http://tv.hdpfans.com:80/search_history.php</link>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

</channel>
