<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	// Unable to get the video url
	// Temporarily removed

	$htmlToExplode = trim(str_between($html, "<param name='flashvars'", '</object>'));

	$varPlayerOnly = trim(urldecode(str_between($htmlToExplode, 'playerOnly=', '&')));
	$varPath       = trim(urldecode(str_between($htmlToExplode, 'path=', '&')));
	$varFile       = trim(urldecode(str_between($htmlToExplode, 'file=', '&')));
	$varWidth      = trim(urldecode(str_between($htmlToExplode, 'width=', '&')));
	$varHeight     = trim(urldecode(str_between($htmlToExplode, 'height=', '&')));
	$varAppdataurl = trim(urldecode(str_between($htmlToExplode, 'appdataurl=', '&')));
	$varCb         = trim(urldecode(str_between($htmlToExplode, ".swf?cb=", "'")));
	// Not sure if it works
	$varLoaderUrl  = trim(urldecode(str_between($htmlToExplode, "src='", "'")));

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
