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
	if (isset($_GET['query'])) {
		$query = $_GET['query'];
		$queryArr = explode(',', $query);
		$id = urldecode($queryArr[0]);
	}

	$userAgentFF3     = 'Mozilla/5.0 (Windows; U; Windows NT 6.1; zh-TW; rv:1.9.2.16) Gecko/20110319 Firefox/3.6.16';
	$userAgent        = $userAgentFF3;

	ini_set('user_agent', $userAgent);

	$link = 'http://www.youtube.com/get_video_info?video_id=' . $id;

	$html = file_get_contents($link);
	$vids = explode(',', urldecode(trim(str_between($html, 'fmt_url_map=', '&'))));
	$vid  = explode('|', $vids[0]);

	header('Location: ' . $vid[1]);
?>
