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

	if (empty($imsDBConn)) {
		echo "\$imsDBConn -------- empty\r\n";
		exit();
	}

	$action = false;
	if ((isset($_GET['action'])) &&
		(strcmp(strtolower(urldecode($_GET['action'])), 'true') == 0)) {
		$action = true;
	}

	echo 'Initialize DB with "' . ($filename = $_GET['name']) . '"' . "\r\n\r\n";
	if (!file_exists($filename)) {
		echo "\"$filename\" -------- not exists\r\n";
	}

	$lines = file($filename);
	echo '"' . $filename . '" ======== ' . "\r\n\r\n";
	print_r($lines);
	echo "\r\n\r\n\"" . $filename . '" ======== ' . "\r\n";

	//
	// http://stackoverflow.com/questions/19751354/how-to-import-sql-file-in-mysql-database-using-php
	//
	// Temporary variable, used to store current query
	$templine = '';
	// Read in entire file
	$lines = file($filename);
	// Loop through each line
	foreach ($lines as $line) {

		$line = trim($line);

		// Skip it if it's a comment
		if ((substr($line, 0, 2) == '--') || (strlen($line) == 0))
			continue;

		// Add this line to the current segment
		$templine .= $line;
		// If it has a semicolon at the end, it's the end of the query
		if (substr(trim($line), -1, 1) == ';') {
			echo '"' . $filename . '": [-[' . $templine . "]-]\r\n";
			if ($action) {
				// Perform the query
				mysql_query($templine, $imsDBConn) or print('Error performing query \'' . $templine . '\': ' . mysql_error() . "\r\n\r\n");
			}
			// Reset temp variable to empty
			$templine = '';
		}
	}
	echo "DB initialized (action = " . (($action === true) ? "true" : "false") . ")\r\n";
?>
<?php
	require('00_suffix.php');
?>
