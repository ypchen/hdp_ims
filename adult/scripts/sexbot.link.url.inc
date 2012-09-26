<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$varPlayerOnly = trim(urldecode(str_between($html, 'playerOnly:', ',')));
	$varPath       = trim(urldecode(str_between($html, "path:'", "'")));
	$varFile       = trim(urldecode(str_between($html, "file:'", "'")));
	$varWidth      = trim(urldecode(str_between($html, "width:'", "'")));
	$varHeight     = trim(urldecode(str_between($html, "height:'", "'")));
	$varAppdataurl = trim(urldecode(str_between($html, "appdataurl:'", "'")));
	$varCb         = trim(urldecode(str_between($html, ".swf?cb=", "'")));

	$htmlBody = explode('embedSWF(', $html);
	$varLoaderUrl  = trim(urldecode(str_between($htmlBody[1], "'", "'")));

	$json_data = '{"returnType":"json",' .
		'"file":"' . $varFile . '",' .
		'"appdataurl":"' . $varAppdataurl . '",' .
		'"request":"getAllData",' .
		'"playerOnly":"' . $varPlayerOnly . '",' .
		'"width":"' . $varWidth . '",' .
		'"height":"' . $varHeight . '",' .
		'"path":"' . $varPath . '",' .
		'"cb":"' . $varCb . '",' .
		'"loaderUrl":"' . $varLoaderUrl . '",' .
		'"htmlHostDomain":"www.sexbot.com"}';

	// Fetch the response (json object)
	$html = yp_file_get_contents($varAppdataurl, array('jsonRequest' => $json_data));

	$link = trim(urldecode(str_between($html, '"file": "', '"')));
	$link = str_replace(' ', '%20', $link);
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
