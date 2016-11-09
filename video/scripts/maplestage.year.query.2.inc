<?php
	$sortedVideos = array();

	foreach($videos as $video) {
		$title = convertUnicodePoints($video['name']);
		$data  = '';
		$link  = base64_encode(base64_decode($search) . ',"slug":"' . $video['slug'] . '"');
		$image = $video['cover'];
		$note  = array($video['lastUpdatedAt']);
		$extra = base64_encode($video['slug']);

		$sortedVideos[] = array(
			$title,
			$data,
			$link,
			$image,
			$note,
			$extra,
		);
	}

	usort($sortedVideos, "yp_cmp_videos_maplestage");

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
	function yp_cmp_videos_maplestage($a, $b) {
		return yp_cmp_strings_length_first(trim($a[5]), trim($b[5]));
	}
?>
