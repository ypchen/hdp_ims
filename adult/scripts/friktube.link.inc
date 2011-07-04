<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$player = explode('<div id="player">', $html);
	$link   = 'http://www.friktube.com' . trim(str_between($player[1], '<script type="text/javascript" src="', '"></script>'));

	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link  = urldecode(trim(str_between($html, "'file','", "'")));
	$link  = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
