<?php
//	error_reporting(E_ALL ^ (E_NOTICE | E_WARNING));

	require('00_prefix.php');
	$myBaseName = basename($myScriptName, '.php');
	$myName = basename($myScriptName, '.php');

	$userAgent        = $userAgentFF3;
	ini_set('user_agent', $userAgent);

	include('06_get.link.inc');

	$pass_check = true;
	try {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = 'http://tw.nextmedia.com' . trim(str_between($html, '<iframe src="', '"'));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, "'file','", "'"));
		$link = str_replace('&','&amp;',$link);
		include('05_check.link.inc');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check)
		header('Location: ' . $link);

	require('00_suffix.php');
?>
