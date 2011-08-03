<?php
	$sortedVideos = array();

	$siteURLprefix = '';
	foreach($videos as $video) {

		$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
		$title = trim(str_between($video, 'title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, ' src="', '"'));
		$note   = array();
		$note[] = trim(str_between($video, '<span class="searchOne">', '</span>'));
		$note[] = '';
		$note[] = '';
		$note[] = '';

		$sortedVideos[] = array(
			$title,
			$data,
			$link,
			$image,
			$note,
			$extra,
		);
	}

	if ($itemNo == 0) {
		// Show
		usort($sortedVideos, "yp_cmp_videos_maplestage_show");
	}
	else {
		// Drama
		usort($sortedVideos, "yp_cmp_videos_sugoideas_drama");
	}

	foreach($sortedVideos as $video) {
		$title = $video[0];
		$data  = $video[1];
		$link  = $video[2];
		$image = $video[3];
		$note  = $video[4];
		$extra = $video[5];

		$pageStart = 0;
		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
<?php
	function yp_cmp_videos_sugoideas_drama($a, $b) {
		// Compare their Chinese titles
		$aexp = explode('/', $a[0]);
		$bexp = explode('/', $b[0]);
		return yp_cmp_strings_length_first(trim($aexp[count($aexp)-1]), trim($bexp[count($bexp)-1]));
	}
	function yp_cmp_videos_maplestage_show($a, $b) {
		return yp_cmp_strings_length_first(trim($a[0]), trim($b[0]));
	}
?>
