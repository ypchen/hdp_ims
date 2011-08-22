<?php
	// For maplestage
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$ids  = explode(',', trim(str_between($html, '<div class="video_ids">', '</div>')));
	include('05_check.link.idcount.inc');
?>
