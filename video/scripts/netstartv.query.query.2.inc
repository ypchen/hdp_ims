<?php
	$sortedVideos = array();

	$siteURLprefix = 'http://v.netstartv.com';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, 'playbtn" href="', '"'));
		$image  = trim(str_between($video, ' src="', '"'));
		$extra = '';
		$note   = array('', '', '', '');

		if (strpos($video, '<i style="') !== false) {
			// Several items in <h3 />
			// Title [note] year
			$italic = explode('/i>', trim(str_between($video, '<i style="', '<div ')));
			unset($italic[count($italic)-1]);	// Suffix
			$italic = array_values($italic);
			$i = 0;
			foreach($italic as $note_item) {
				$note[$i] = trim(str_between($note_item, '">', '<'));
				$i ++;
			}
			// The last italic item should be year
			$title = ($year = $note[count($italic)-1]) . ' ' .
						trim(str_between(str_between($video, '<h3>', '<i style="'), '">', '<'));
			$note[count($italic)-1] = '';
		}
		else {
			// Title only
			$title = trim(str_between(str_between($video, '<h3>', '<div '), '">', '<'));
			$year  = '';
		}
		$title = convertUnicodePoints($title);

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
