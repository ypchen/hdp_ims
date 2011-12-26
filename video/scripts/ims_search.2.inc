<channel>

<title>IMS 搜索</title>

	<item>
		<title>HAOIMS: 全網搜索 / 本機輸入</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);
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
		<note>※ 需安裝 hdp_input</note>
		<?php echo siteLogo('haoims'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HAOIMS: 全網搜索 / 內建輸入</title>
		<onClick>
			input = getInput("Enter a keyword");
			/* input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0); */
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
		<note>使用播放機內建輸入功能</note>
		<?php echo siteLogo('haoims'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HAOIMS: 全網搜索 / 線上輸入</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("<?php echo $inputMethod; ?>", "mediaDisplay", "search", 0);
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
		<note>Input method: <?php echo $inputMethod; ?></note>
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
		<title>HDPfans: 全網搜索 / 本機輸入</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0);
			if (input != null) {
				keyword = urlEncode(input);
				searchUrl = "http://tv3.hdpfans.com/search_kw.php?keyword=" + keyword;
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
		<note>※ 需安裝 hdp_input</note>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HDPfans: 全網搜索 / 內建輸入</title>
		<onClick>
			input = getInput("Enter a keyword");
			/* input = doModalRss("rss_file://./etc/ypInput/keyboard.rss", "mediaDisplay", "search", 0); */
			if (input != null) {
				keyword = urlEncode(input);
				searchUrl = "http://tv3.hdpfans.com/search_kw.php?keyword=" + keyword;
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
		<note>使用播放機內建輸入功能</note>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HDPfans: 全網搜索 / 線上輸入</title>
		<onClick>
			/* input = getInput("Enter a keyword"); */
			input = doModalRss("<?php echo $inputMethod; ?>", "mediaDisplay", "search", 0);
			if (input != null) {
				keyword = urlEncode(input);
				searchUrl = "http://tv3.hdpfans.com/search_kw.php?keyword=" + keyword;
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
		<note>Input method: <?php echo $inputMethod; ?></note>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

	<item>
		<title>HDPfans: 最近搜索紀錄</title>
		<link>http://tv3.hdpfans.com/search_history.php</link>
		<?php echo siteLogo('hdpfans'); ?>
		<mediaDisplay />
	</item>

</channel>
