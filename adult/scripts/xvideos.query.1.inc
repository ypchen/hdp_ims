<?php
	$searchComponents = explode('/', str_replace(' ', '+', $search . '/' . ($page-1)));
	$searchCompoentsNo = count($searchComponents);
	$swap = $searchComponents[$searchCompoentsNo-1];
	$searchComponents[$searchCompoentsNo-1] = $searchComponents[$searchCompoentsNo-2];
	$searchComponents[$searchCompoentsNo-2] = $swap;
	$link = implode('/', $searchComponents);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$main_col_ary = explode('<!-- END PAGINATION -->', $html);
	$main_col = $main_col_ary[1];
	$videos = explode('<div class="thumbBlo', ($htmlToExplode = $main_col));
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
