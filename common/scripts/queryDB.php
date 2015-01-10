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
	if (!isset($_GET['query']))
		exit();

	if (empty($imsDBConn)) {
		echo "\$imsDBConn -------- empty\r\n";
		exit();
	}

	echo 'query DB with \'' . ($strQuery = $_GET['query']) . '\'' . "\r\n\r\n";

	// Perform the query
	($dbResult = mysql_query($strQuery, $imsDBConn)) or print('Error performing query \'' . $strQuery . '\': ' . mysql_error() . "\r\n\r\n");

	$numRow = mysql_num_rows($dbResult);
	echo "Result: $numRow records\r\n";
	if ($numRow > 0) {
		$i = 0;
		echo '======== DUMP BEGIN ======== ' . "\r\n";
		while ($row = mysql_fetch_assoc($dbResult)) {
			echo "[$i] ======== \r\n";
			var_dump($row);
			$i ++;
		}
		echo '======== DUMP END ======== ' . "\r\n";
		echo "Result: $numRow records\r\n\r\n";
	}
?>
<?php
	require('00_suffix.php');
?>
