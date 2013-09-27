<?php
	$sortedVideos = array();

	$siteURLprefix = 'http://v.ck101.com';
	foreach($videos as $video) {

		// Remove the title part in the link such that "next page" may work
		$link_href = trim(str_between($video, ' href="', '"'));
		$link_components = explode('/', $link_href);
		$title_components = explode('-', $link_components[($lc_last = (count($link_components)-1))]);
		$link_components[$lc_last] = $title_components[0];

		$link  = $siteURLprefix . implode('/', $link_components);
		$title = trim(str_between($video, ' title="', '"'));
		$title = convertUnicodePoints($title);
		$extra = '';

		$image  = trim(str_between($video, '<img lz_src="', '"'));
		$note   = array();
		$note[] = trim(str_between($video, '<p>', '</p>'));
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
		// Drama
		usort($sortedVideos, "yp_cmp_videos_maplestage_drama");
	}
	else {
		// Others
		usort($sortedVideos, "yp_cmp_videos_maplestage_show");
	}

	foreach($sortedVideos as $video) {
		$title = $video[0];
		$data  = $video[1];
		$link  = $video[2];
		$image = $video[3];
		$note  = $video[4];
		$extra = $video[5];

		$pageStart = 1;
		$queryLevel = '.query.query';
		include('04_query.inc');
	}
?>
<?php
	function yp_cmp_videos_maplestage_drama($a, $b) {
		// Compare their Chinese titles
		$aexp = explode('/', $a[0]);
		$bexp = explode('/', $b[0]);
		return yp_cmp_strings_length_first(trim($aexp[0]), trim($bexp[0]));
	}
	function yp_cmp_videos_maplestage_show($a, $b) {
		return yp_cmp_strings_length_first(trim($a[0]), trim($b[0]));
	}
?>
