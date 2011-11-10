<?php
	$link = $search . 'page' . $page . '.html?' . $extra;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	if (strpos($html, '>Next &raquo;</a></div>') === false)
		$pageMax = $page;

	$videos = explode('<div id="miniatura">', $html);
	unset($videos[0]);
	$videos = array_values($videos);

	// Remove cam ads
	foreach ($videos as $vkey => $vval) {
		if (strpos($vval, 'camsinabox.php') !== false)
			unset($videos[$vkey]);
	}
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.query.inc');
?>
