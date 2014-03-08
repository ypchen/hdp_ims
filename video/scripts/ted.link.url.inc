<?php
	// 115 = 11.5 seconds
	$tedSubtitleDelay = 115;
	$tedFinalDuration = 100;

	// Get the talk page
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	// Quality: from high to low
	$qualityOrders = array(
		array('High (854x480)', '"high":"', '"'),
		array('Medium (512x288)', '"medium":"', '"'),
		array('Low (320x180)', '"low":"', '"')
	);
	foreach ($qualityOrders as $qk => $qv) {
		if (strpos($html, $qv[1]) !== false) {
			$url = trim(str_between($html, $qv[1], $qv[2]));
			$extraInfo = $qv[0];
			break;
		}
	}

	// Get the content of the download dialog
//	$link = 'http://www.ted.com' .
//				'/download/links/slug/' .
//					trim(str_between($html, '"mediaSlug":"', '",')) .
//				'/type/talks/ext/mp4';
//	$htmlDownload = yp_file_get_contents($link);
//	include('05_check.file_contents.inc');

	// Get the URL base
//	$urlBase = 'http://' . trim(str_between($htmlDownload, "var url = 'http://", "'"));

	// Get the quality list
//	$qualityList = explode('name="download_quality"', $htmlDownload);
	// Use the best quality (at the bottom of the list)
//	$extraInfo = trim(str_between($qualityList[count($qualityList)-1], '">', '</label>'));
//	$quality = trim(str_between($qualityList[count($qualityList)-1], 'value="', '"'));

	// Construct the URL (without the embeded subtitle)
//	$url = str_replace('{quality}', $quality,
//			str_replace('{lang}', '', $urlBase));

	$siteURLprefix = 'http://www.ted.com';

	$link = $siteURLprefix . trim(str_between($html, "transcript-link' href='", "'")) . '?lang=' . $extra;
	$html = yp_file_get_contents($link);
	if (($html === false) || (strlen($html) == 0)) {
		$subtitles = array();
	}
	else {
		// Handle the subtitles
		$htmlSubtitle = str_between($html, " talk-transcript__body'>", '<footer ');
		$subtitles = explode("<span class='talk-transcript__fragment", $htmlSubtitle);
		unset($subtitles[0]);
		$subtitles = array_values($subtitles);
	}

	if (count($subtitles) > 0) {
		// Save the subtitle information on the local disk of HDP
?>
	ccDataStart = null;
	ccDataEnd = null;
	ccDataText = null;
	ccDataStart = pushBackStringArray(ccDataStart, "-60");
	ccDataEnd = pushBackStringArray(ccDataEnd, "-50");
	ccDataText = pushBackStringArray(ccDataText, "");
	ccDataStart = pushBackStringArray(ccDataStart, "-40");
	ccDataEnd = pushBackStringArray(ccDataEnd, "-30");
	ccDataText = pushBackStringArray(ccDataText, "");
	ccDataStart = pushBackStringArray(ccDataStart, "-20");
	ccDataEnd = pushBackStringArray(ccDataEnd, "-10");
	ccDataText = pushBackStringArray(ccDataText, "");
<?php
		$dataCount = 3;

		for ($i = 0 ; $i < count($subtitles) ; $i ++) {

			if ($i == 0)
				$start = $tedSubtitleDelay + round((floatval(trim(str_between($subtitles[$i], "data-time='", "'"))) / 10), 0);
			else
				$start = $end;

			if ($i < (count($subtitles)-1))
				$end = $tedSubtitleDelay + round((floatval(trim(str_between($subtitles[$i+1], "data-time='", "'"))) / 10), 0);
			else
				$end = $start + $tedFinalDuration;

			$text  = trim(htmlspecialchars_decode(
						convertUnicodePoints(
							str_between($subtitles[$i], "'>", '</')), ENT_QUOTES));

			$textLines = explode("\n", $text);
			foreach ($textLines as $textLine) {

				$textLineWidthLimit = 45;
				$textLineWraps = array();

				if (strlen($textLine) > $textLineWidthLimit) {
					$words = explode(' ', $textLine);
					$oneLine = array();
					$oneLineLength = 0;
					foreach ($words as $word) {
						if ((($wordLength = strlen($word)) + $oneLineLength) > $textLineWidthLimit) {
							$textLineWraps[] = implode(' ', $oneLine);
							$oneLine = array();
							$oneLineLength = 0;
						}
						$oneLine[] = $word;
						$oneLineLength += $wordLength;
					}
					if (count($oneLine) > 0)
						$textLineWraps[] = implode(' ', $oneLine);
				}
				else
					$textLineWraps[] = $textLine;

				foreach ($textLineWraps as $textLineWrap) {

					$dataCount ++;
?>
	ccDataStart = pushBackStringArray(ccDataStart, "<?php echo strval($start); ?>");
	ccDataEnd = pushBackStringArray(ccDataEnd, "<?php echo strval($end); ?>");
	ccDataText = pushBackStringArray(ccDataText, "<?php echo str_replace('"', '\"', $textLineWrap); ?>");
<?php
				}
			}
		}

		// Update the data count
		$dataCount ++;
		$ccStatus = '';
?>
	ccDataStart = pushBackStringArray(ccDataStart, "864000");
	ccDataEnd = pushBackStringArray(ccDataEnd, "864010");
	ccDataText = pushBackStringArray(ccDataText, "");

	writeStringToFile("<?php echo $fileLocalCCStart; ?>", ccDataStart);
	writeStringToFile("<?php echo $fileLocalCCEnd; ?>", ccDataEnd);
	writeStringToFile("<?php echo $fileLocalCCText; ?>", ccDataText);
	writeStringToFile("<?php echo $fileLocalCCCount; ?>", "<?php echo strval($dataCount); ?>");

	writeStringToFile("<?php echo $fileLocalCCStatus; ?>", "成功處理字幕資訊");

	writeStringToFile("<?php echo $fileLocalExtraInfo; ?>", "<?php echo strval($extraInfo); ?>");
<?php
	}
	else {
?>
	showCCStatusData = null;
	showCCStatusData = pushBackStringArray(showCCStatusData, "不含任何字幕資訊");
	showCCStatusData = pushBackStringArray(showCCStatusData, "255:0:0");
	writeStringToFile("<?php echo $fileLocalCCStatus; ?>", showCCStatusData);

	writeStringToFile("<?php echo $fileLocalExtraInfo; ?>", "<?php echo strval($extraInfo); ?>");
<?php
	}

	$links = array($url);
	$titles = array($title);

	$itemTotal = count($links);
?>
