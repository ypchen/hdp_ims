
	/* Read the current data */
	dataArray  = readStringFromFile(dataFile);
	dataTypes  = null;
	dataTitles = null;
	dataLinks  = null;

	/* Check if the new item is identical to the first N items on file */
	checkMax = <?php echo $historyCheckMax; ?>;
	foundIdentical = 0;
	i = 0;
	j = 0;
	while ((i &lt; checkMax) &amp;&amp; (foundIdentical == 0)) {
		/* It's ok if getStringArrayAt(dataArray, n) is null */
		if (dataLink == getStringArrayAt(dataArray, (j+2))) {
			foundIdentical = 1;
		}
		i = i+1;
		j = j+3;
	}

	/* Ignore the new item if found */
	if (foundIdentical == 0) {
		/* New item on the top */
		dataTypes  = pushBackStringArray(dataTypes,  dataType);
		dataTitles = pushBackStringArray(dataTitles, dataTitle);
		dataLinks  = pushBackStringArray(dataLinks,  dataLink);
		dataSize   = 1;

		/* Previous items */
		k = 0;
		while ((getStringArrayAt(dataArray, k) != null) &amp;&amp; (dataSize &lt; dataMax)) {
			dataTypes  = pushBackStringArray(dataTypes,  getStringArrayAt(dataArray, k));
			k = k+1;
			dataTitles = pushBackStringArray(dataTitles, getStringArrayAt(dataArray, k));
			k = k+1;
			dataLinks  = pushBackStringArray(dataLinks,  getStringArrayAt(dataArray, k));
			k = k+1;
			dataSize   = dataSize+1;
		}
		/* Save back */
		dataArray = null;
		k = 0;
		while (k &lt; dataSize) {
			dataArray = pushBackStringArray(dataArray, getStringArrayAt(dataTypes,  k));
			dataArray = pushBackStringArray(dataArray, getStringArrayAt(dataTitles, k));
			dataArray = pushBackStringArray(dataArray, getStringArrayAt(dataLinks,  k));
			k = k+1;
		}
		writeStringToFile(dataFile, dataArray);
	}
