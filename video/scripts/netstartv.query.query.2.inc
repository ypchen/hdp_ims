<?php
	$sortedVideos = array();

	if (empty($extra)) {
		$siteURLprefix = 'http://v.aibuka.com';
	}
	else {
		// for baijia, xiqu, & ifeng
		$siteURLprefix = $extra;
	}

	switch ($typeLayout) {

		case '<li class="grid-item col-xs-6 col-md-2 " ':
		case '<li class="grid-item col-xs-6 col-md-2 ">':
		case '<li class="grid-item col-xs-6 col-md-2">':
		case '<li class="grid-item col-md-2">':
		case '<li class="col-md-6 col-sm-8">':
		case '<li class="col-md-6">':
			foreach($videos as $video) {

				$year = '';
				if (strpos($video, '<i>(') !== false) {
					$year = trim(str_between($video, '<i>(', ')</i>'));
					if (!is_numeric($year)) {
						$year = '';
					}
					else {
						$year = "($year) ";
					}
				}

				$link  = $siteURLprefix . trim(str_between($video, ' href="', '"'));
				$title = $year . trim(str_between(str_between($video, '<div class="name">', '</div>'), '">', '<'));
				$title = convertUnicodePoints($title);
				$image = trim(str_between($video, ' src="', '"'));
				$extra = '';
				$note  = array('', '', '', '');

				$clickPlay = 'no';
				include('04_query.items.link.inc');
			}
			break;

		case '<section class="video clearfix">':
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
			break;

		default:
			break;

	}
?>
