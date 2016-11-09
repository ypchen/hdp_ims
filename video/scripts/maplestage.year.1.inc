<?php
	$json_query_pH = '{"queries":[{"name":"shows","query":{"sort":"top","take":99999,';
	$json_query_pT = '}}]}';
	$json_query = $json_query_pH . base64_decode($search) . $json_query_pT;
	$json_query_len = strlen($json_query);

	$link = 'http://maplestage.com/v1/query';

	$headers = array(
		'Referer: http://maplestage.com/',
		'Content-type: application/json',
		'Accept: application/json'
//		'Content-Length: ' . $json_query_len
	);

	$html = yp_file_get_contents($link, $json_query, $headers);
	include('05_check.file_contents.inc');

	$results = json_decode($html, TRUE);
	$shows   = $results['shows'];
	$years   = array();
	$showTotal = 0;
	foreach ($shows as $show) {
		$years[intval($show['year'])] ++;
		$showTotal ++;
	}
	krsort($years);
	$years = array('不限年份'=>$showTotal) + $years;
	$videos = $years;

	$itemTotal = count($videos);
	include('05_check.base.inc');
?>
