<?php
	$noNeedToLogRequest = true;
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');
?>
<?php
	// Check the api key first
	if ((!isset($_GET['apikey'])) ||
		(strcmp($apikey = urldecode($_GET['apikey']), $imsDBToRemoveAPIKey) != 0))
		exit();

	// DB enabled?
	if (empty($imsUseDB))  exit();
	if (empty($imsDBConn)) exit();

	remove_old_records($imsDBConn, $remoteIP, $imsDBToRemove);
?>
<?php
	require('00_suffix.php');
?>
