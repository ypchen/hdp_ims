<?php
	$link = $search = 'http://edition.cnn.com/services/podcasting/';
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$htmlBlocks = explode('<div class="cnnPODhdr cnnPODtop12">AUDIO PODCASTS</div>', $html);

	$videos = explode('<td class="cnnPODcast', $htmlBlocks[0]); // Audio Podcasts Not included
	unset($videos[0]);
	$videos = array_values($videos);

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
