<?php
	include('15_3_columns.inc');

	$queryYear = $search;

	$link = 'http://www.maplestage.com/drama/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBody = explode('<ul class="yearS', $html);

	$years = explode('<li>', ($htmlToExplode = trim(str_between($htmlBody[1], 'orting"', '</ul>'))));
	unset($years[0]);
	$years = array_values($years);

	$videos = array();
	foreach($years as $year) {
		$listYear = trim(str_between($year, '">', '</h2>'));
		$listYear = convertUnicodePoints($listYear);

		if (strcmp($listYear, $queryYear) == 0) {
			$year = trim(str_between($year, '<div class="compact-list">', '</div>'));
			$videos = explode('</a>', $year);
			//unset($videos[0]);
			$videos = array_values($videos);
			break;
		}
	}

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
