<?php
	$link = $search;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$imageAll = str_between(
					str_between($html, '<div class="singleview">', '</div>'),
					' src="',
					'"'
				);

	$videos = explode('<li>', ($htmlToExplode = trim(str_between($html, '<h3>Episodes:</h3>', '</div>'))));
	unset($videos[0]);					// Prefix
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
