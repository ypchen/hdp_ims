<?php
	require('00_prefix.php');
	$myBaseName = basename($myScriptName, '.php');
	$myName = basename($myScriptName, '.php');

	$userAgent = $userAgentFF3;
	ini_set('user_agent', $userAgent);

	include('06_get.link.inc');

	$pass_check = true;
	try {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$htmlRemoteSrc = str_between($html, 'var remote_src =', 'encodeURIComponent');
		$IssueID = trim(str_between($htmlRemoteSrc, '/IssueID/', '/Photo/'));
		$fileMP4 = trim(str_between($htmlRemoteSrc, '/Video/', '/NextURL/'));
		$link = 'http://video.appledaily.com.tw/video/' . $IssueID . '/' . $fileMP4;
		include('05_check.link.inc');
	}
	catch (Exception $e) {
		$pass_check = false;
	}

	if ($pass_check)
		header('Location: ' . $link);

	require('00_suffix.php');
?>
