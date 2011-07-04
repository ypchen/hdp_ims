<?php
	$link = $search . '&page=' . $page;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$main_col_ary = explode('id="content">', $html);
	$main_col = $main_col_ary[1];
	$videos = explode('class="video_box">', $main_col);
	unset($videos[0]);
	$videos = array_values($videos);

	// Remove private videos
	foreach ($videos as $vkey => $vval) {
		if (strpos($vval, 'private-video.png') !== false)
			unset($videos[$vkey]);
	}
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
