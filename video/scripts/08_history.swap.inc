
	/* Read the current data */
	dataArray  = readStringFromFile(dataFile);
	dataTypes  = null;
	dataTitles = null;
	dataLinks  = null;

	/* Swap items dataIdx and dataIdx+1 */

	/* Copy everything before dataIdx */
	dataSize = 0;
	k = 0;
	while (dataSize &lt; dataIdx) {
		dataTypes  = pushBackStringArray(dataTypes,  getStringArrayAt(dataArray, k));
		k = k+1;
		dataTitles = pushBackStringArray(dataTitles, getStringArrayAt(dataArray, k));
		k = k+1;
		dataLinks  = pushBackStringArray(dataLinks,  getStringArrayAt(dataArray, k));
		k = k+1;
		dataSize   = dataSize+1;
	}

	/* Copy dataIdx+1 */
	dataTypes  = pushBackStringArray(dataTypes,  getStringArrayAt(dataArray, k+3));
	k = k+1;
	dataTitles = pushBackStringArray(dataTitles, getStringArrayAt(dataArray, k+3));
	k = k+1;
	dataLinks  = pushBackStringArray(dataLinks,  getStringArrayAt(dataArray, k+3));
	k = k+1;
	dataSize   = dataSize+1;

	/* Copy dataIdx */
	dataTypes  = pushBackStringArray(dataTypes,  getStringArrayAt(dataArray, k-3));
	k = k+1;
	dataTitles = pushBackStringArray(dataTitles, getStringArrayAt(dataArray, k-3));
	k = k+1;
	dataLinks  = pushBackStringArray(dataLinks,  getStringArrayAt(dataArray, k-3));
	k = k+1;
	dataSize   = dataSize+1;

	/* Copy everything after dataIdx+1 */
	while (getStringArrayAt(dataArray, k) != null) {
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
