<?php
	function str_between($string, $start, $end){
		$string = ' ' . $string;
		$ini = strpos($string, $start);
		if ($ini == 0)
			return '';
		$ini += strlen($start);
		$len = strpos($string, $end, $ini) - $ini;
		return substr($string, $ini, $len);
	}

	// Default id: FBI warning
	$id = 'ILGA5UFmfRM';
	if (!empty($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		$id = urldecode($queryArr[0]);
	}

	// Supported formats
	// http://en.wikipedia.org/wiki/YouTube
	$formats          = array(
							0 => '38',
							1 => '37',
							2 => '22',
							3 => '35',
							4 => '34',
							5 => '18',
							6 => '5'
						);

	$userAgentFF3     = 'Mozilla/5.0 (Windows; U; Windows NT 6.1; zh-TW; rv:1.9.2.16) Gecko/20110319 Firefox/3.6.16';
	$userAgent        = $userAgentFF3;

	ini_set('user_agent', $userAgent);

	// $link = 'http://www.youtube.com/get_video_info?video_id=' . $id;
	$link = 'http://www.youtube.com/watch?v=' . $id;

	$html = file_get_contents($link);
	$vids = explode(',', urldecode(trim(str_between($html, 'fmt_url_map=', '&'))));
	$supportedVids = array();
	foreach ($vids as $vidData) {
		$vid = explode('|', $vidData);
		$key = array_search($vid[0], $formats);
		if ($key !== false) {
			$supportedVids[$key] = $vid[1];
		}
	}
	ksort($supportedVids);
	$v = array_values($supportedVids);

	// Return the video with the highest resolution
	header('Location: ' . $v[0]);
?>
