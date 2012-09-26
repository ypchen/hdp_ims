<?php
	// 153 = 15.3 seconds
	$tedSubtitleDelay = 153;
	$tedFinalDuration = 100;

	// Get the talk page
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	// Get the content of the download dialog
	$link = 'http://www.ted.com' .
			rtrim(trim(str_between($html, "download_dialog.load('", "'")), '/');
	$htmlDownload = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	// Get the URL base
	$urlBase = 'http://' . trim(str_between($htmlDownload, "var url = 'http://", "'"));

	// Get the quality list
	$qualityList = explode('name="download_quality"', $htmlDownload);
	// Use the best quality (at the bottom of the list)
	$extraInfo = trim(str_between($qualityList[count($qualityList)-1], '">', '</label>'));
	$quality = trim(str_between($qualityList[count($qualityList)-1], 'value="', '"'));

	// Construct the URL (without the embeded subtitle)
	$url = str_replace('{quality}', $quality,
			str_replace('{lang}', '', $urlBase));

	// Handle the subtitles
	$htmlSubtitle = str_between($html, '<div id="transcriptText">', '</div>');
	$subtitles = explode('<a hr', $htmlSubtitle);
	unset($subtitles[0]);
	$subtitles = array_values($subtitles);
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
				$start = $tedSubtitleDelay + (intval(trim(str_between($subtitles[$i], 'ef="#', '"'))) / 100);
			else
				$start = $end;

			if ($i < (count($subtitles)-1))
				$end = $tedSubtitleDelay + (intval(trim(str_between($subtitles[$i+1], 'ef="#', '"'))) / 100);
			else
				$end = $start + $tedFinalDuration;

			$text  = trim(htmlspecialchars_decode(
						convertUnicodePoints(
							str_between($subtitles[$i], '">', '</a>')), ENT_QUOTES));

			$textLines = explode("\n", $text);
			foreach ($textLines as $textLine) {
				$dataCount ++;
?>
	ccDataStart = pushBackStringArray(ccDataStart, "<?php echo strval($start); ?>");
	ccDataEnd = pushBackStringArray(ccDataEnd, "<?php echo strval($end); ?>");
	ccDataText = pushBackStringArray(ccDataText, "<?php echo str_replace('"', '\"', $textLine); ?>");
<?php
			}
		}
		// 'Update the data count
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
