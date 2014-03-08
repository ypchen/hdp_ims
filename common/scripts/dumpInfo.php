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
	if (!isset($_GET['name']))
		exit();

	$json = false;
	if ((isset($_GET['json'])) &&
		(strcmp(strtolower(urldecode($_GET['json'])), 'true') != 0)) {
		$json = true;
	}

	if (($envVar = @getenv($_GET['name'])) !== false) {
		if ($json) {
			$envVar = json_decode($envVar, true);
		}
		echo '"' . $_GET['name'] . '" ======== ' . "\r\n\r\n";
		if (is_array($envVar)) {
			print_r($envVar);
		}
		else {
			echo $envVar;
		}
		echo "\r\n\r\n\"" . $_GET['name'] . '" ======== ' . "\r\n";
	}
	else {
		echo '"' . $_GET['name'] . '" -------- not found' . "\r\n";
	}
?>
<?php
	require('00_suffix.php');
?>
