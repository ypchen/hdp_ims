<?php
	include($myBaseName . '.utils.inc');

	/*
		$search is like the following strings

			javascript:changeMenu(1,'today','sec','1','','','');
			javascript:changeMenu(3,'entertainment','cat','1','','','');

			javascript:changeRnews(1,'videonoembed','1');
			javascript:changeRnews(2,'beauty','1');
	*/

	$strAppendix = $extra;

	if (strpos($search, "changeMenu") !== false)
		$link = urlFromChangeMenu($search, $page, $strAppendix);
	else
		$link = urlFromChangeRnews($search, $page, $strAppendix);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '>下一頁</a>') === false)
		$pageMax = $page;
	else
		$pageMax = $page+1;

	$videos = explode('<div class="ecs">', ($htmlToExplode = $html));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
