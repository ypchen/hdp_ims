<?php
	$sortedVideos = array();

	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, 'playbtn" href="', '"'));
		$image  = trim(str_between($video, ' src="', '"'));
		$extra = '';
		$note   = array('', '', '', '');

		if (strpos($video, '<i style="') !== false) {
			$italic = explode('/i>', trim(str_between($video, '<i style="', '</h2>')));
			unset($italic[count($italic)-1]);	// Suffix
			$italic = array_values($italic);
			$i = 0;
			foreach($italic as $note_item) {
				$note[$i] = trim(str_between($note_item, '">', '<'));
				$i ++;
			}
			// The last italic item should be year
			$title = ($year = $note[count($italic)-1]) . ' ' . trim(str_between($video, '<h2>', '<i style="'));
			$note[count($italic)-1] = '';
		}
		else {
			$title = trim(str_between($video, '<h2>', '<div '));
			$year  = '';
		}
		$title = convertUnicodePoints($title);

		$sortedVideos[] = array(
			$title,
			$data,
			$link,
			$image,
			$note,
			$extra,
			$year
		);
	}

	usort($sortedVideos, "yp_cmp_videos_netstartv");

	foreach($sortedVideos as $video) {
		$title = $video[0];
		$data  = $video[1];
		$link  = $video[2];
		$image = $video[3];
		$note  = $video[4];
		$extra = $video[5];

		$clickPlay = 'no';
		include('04_query.items.link.inc');
	}
?>
<?php
	function yp_cmp_videos_netstartv($a, $b) {
		// Compare their year first
		// Latest first
		if (($strcmp_result = strcmp($a[6], $b[6])) != 0)
			return ((-1) * $strcmp_result);
		else
			return yp_cmp_strings_length_first(trim($a[0]), trim($b[0]));
	}
?>
