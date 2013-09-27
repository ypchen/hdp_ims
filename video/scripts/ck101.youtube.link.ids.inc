<?php
	// For v.ck101.com
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(
				str_replace('卡提諾影音', '',
					str_between($html, '<title>', '</title>'))
			);
	$title = convertUnicodePoints($title);

	$idString = trim(str_between($html, ' src="http://www.youtube.com/embed/', '"'));
	if (strlen($idString) == 0) {
		$idString = trim(str_between($html, ' id="youtubeids">', '</div>'));
	}
	if (strlen($idString) == 0) {
		$idString = trim(str_between($html, 'so.addVariable("file", "http://www.youtube.com/watch?v=', '"'));
	}

	$ids  = explode(',', $idString);
	include('05_check.link.idcount.inc');
?>
