<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(str_between($html, '<title>', '</title>'));
	$title = convertUnicodePoints($title);

	// YouTube ids
	$playlist = explode('], [', ($playlistString = trim(str_between($html, 'var playlist = [', '];'))));
	$ids = array();
	$titles = array();
	$i = 0;
	foreach ($playlist as $item) {
		$i ++;
		$item_title = trim(str_between($item, '"', '", "'));
		if ((is_numeric($item_title)) && (intval($item_title) == $i)) {
			$titles[] = $title . ' 第 ' . $item_title . ' 段/集';
		}
		else {
			$titles[] = $item_title;
		}
		$ids[] = trim(str_between($item, ', "', '"'));
	}
	include('05_check.link.idcount.inc');
?>
