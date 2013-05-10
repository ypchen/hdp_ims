<?php
	$noNeedToLogRequest = true;
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');
?>
<?php
	// Check the api key first
	if ((!isset($_GET['apikey'])) ||
		(strcmp($apikey = urldecode($_GET['apikey']), $imsAPIKey) != 0))
		exit();

	// Email enabled?
	if (empty($imsUseEmail)) exit();

	notification_email_text(
		'IMS email test',
		'$_SERVER["HTTP_HOST"] = ' . $_SERVER["HTTP_HOST"] .
		'$myScriptName = ' . $myScriptName .
			"\r\n" . '$ip = ' . $remoteIP
	);
?>
<?php
	require('00_suffix.php');
?>
