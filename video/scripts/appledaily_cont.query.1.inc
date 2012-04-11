<?php
	include($myBaseName . '.utils.inc');

	/*
		$search is like the following strings

			javascript:changeMenu(1,'today','sec','1','','','');
			javascript:changeMenu(3,'entertainment','cat','1','','','');
	*/

	$link = urlFromChangeMenu($search, $page);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$prefix = '';
	if (strpos($html, '<h1>今日動新聞</h1>') !== false) {
		// manually add the overview item for convenience
		$prefix = "<a href=\"javascript:changeMenu(1,'today','sec','1','','','')\">總覽</a>'";
	}
	$html = $prefix . str_between($html, '<nav class="sbmm"', '</nav>');

	$videos = explode('<a hr', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
