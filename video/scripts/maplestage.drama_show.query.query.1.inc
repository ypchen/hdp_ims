<?php
	include('15_2_columns.inc');

	$html = yp_file_get_contents($link = $search . '?page=' . strval($page));
	include('05_check.file_contents.inc');

	if ((strpos($html, 'class="pager"') === false) || (strpos($html, 'class="disabled"><span>下一頁') !== false))
		$pageMax = $page;

	$videos = explode('a>', ($htmlToExplode = trim(str_between($html, '<div class="holder">', '</div>'))));
	//unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
