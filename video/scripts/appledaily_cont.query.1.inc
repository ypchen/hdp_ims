<?php
	include($myBaseName . '.utils.inc');

	/*
		$search is like the following strings

			javascript:changeMenu(1,'today','sec','1','','','');
			javascript:changeMenu(3,'entertainment','cat','1','','','');
	*/

	$extraArr = explode('|', $extra);
	$strAppendix = $extraArr[0];

	$link = urlFromChangeMenu($search, $page, $strAppendix);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$prefix = '';
	$htmlToExplode = $html;
	if (strpos($htmlToExplode, '<h1>今日動新聞</h1>') !== false) {
		// manually add the overview item for convenience
		$prefix = '<a href="' . urldecode($extraArr[1]) . '">總覽</a>';
	}
	$htmlToExplode = $prefix . str_between($htmlToExplode, '<nav class="sbmm"', '</nav>');

	$videos = explode('<a hr', $htmlToExplode);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
