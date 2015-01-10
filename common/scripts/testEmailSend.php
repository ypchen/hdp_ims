<?php
	$noNeedToLogRequest = true;
	require('00_prefix.php');

	// Change the content-type
	header("Content-Type:text/plain; charset=utf-8");

	$myName = basename($myScriptName, '.php');
?>
<?php
	// Check the api key first
	if ((!isset($_GET['apikey'])) ||
		(strcmp($apikey = urldecode($_GET['apikey']), $imsAPIKey) != 0))
		exit();
?>
<?php
	echo "Check if IMS_USE_EMAIL\r\n";
	// Email enabled?
	if (empty($imsUseEmail)) exit();

	echo "Send out the email -- from \"$imsBotEmail\" to \"$imsAdminEmail\"\r\n";
	$result = notification_email_text(
		'IMS email test',
		'$_SERVER["HTTP_HOST"] = ' . $_SERVER["HTTP_HOST"] .
			"\r\n" . '$myScriptName = ' . $myScriptName .
			"\r\n" . '$ip = ' . $remoteIP
	);
	echo "\$result = " . ($result ? $result : 'false') . "\r\n";
?>
<?php
	require('00_suffix.php');
?>
