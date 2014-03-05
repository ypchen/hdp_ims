<?php
	include('15_3_columns.inc');

	$html = yp_file_get_contents($link = $search);
	include('05_check.file_contents.inc');

	$queryYear = $extra;

	$years = explode('iv>', ($htmlToExplode = trim(str_between($html, '<div class="listing-block', '<div class="sidebar'))));
	//unset($years[0]);
	$years = array_values($years);

	$videos = array();
	foreach($years as $year) {
		$listYear = trim(str_between($year, ' class="year">', '</'));
		$listYear = convertUnicodePoints($listYear);

		if (strcmp($listYear, $queryYear) == 0) {
			$year = trim(str_between($year, ' class="holder"', '</d'));
			$videos = explode('a>', $year);
			//unset($videos[0]);
			$videos = array_values($videos);
			break;
		}
	}

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
