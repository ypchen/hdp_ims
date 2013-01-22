<?php
	$noNeedToLogRequest = true;
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');

	require('../tempodb-php/tempodb.php');
?>
<?php
	// Check the api key first
	if ((!isset($_GET['apikey'])) ||
		(strcmp($apikey = urldecode($_GET['apikey']), $imsTrackReqAPIKey) != 0))
		exit();
	// Track request enabled?
	if (empty($imsTrackReq)) exit();
	// DB enabled?
	if (empty($imsUseDB))    exit();
	if (empty($imsDBConn))   exit();
	if ((($tempodbKey = @getenv('TEMPODB_API_KEY')) !== false) &&
		(($tempodbSecret = @getenv('TEMPODB_API_SECRET')) !== false)) {

		$tdb = new TempoDB($tempodbKey, $tempodbSecret);

		$now = time();
		$Y = date("Y", $now);
		$m = date("m", $now);
		$d = date("d", $now);
		$H = date("H", $now);
		$i = date("i", $now);

		// The minute just passed by, 18 hours later, 5 days later
		foreach(array(0, 60*18, 60*24*5) as $minute_count) {
			$currMin = date("Y-m-d H:i:s", mktime($H, ($i-$minute_count)-1, 0, $m, $d, $Y));
			$nextMin = date("Y-m-d H:i:s", mktime($H, ($i-$minute_count),   0, $m, $d, $Y));

			$dbResult =
				mysql_query(
					"SELECT COUNT(ip) as value FROM log_request " .
						" WHERE datetime >= '$currMin'" .
						" AND datetime < '$nextMin';",
					$imsDBConn);
			if ($row = mysql_fetch_array($dbResult)) {
				$value = $row['value'];
				$data = array(new DataPoint(new DateTime($currMin), intval($value)));
				$tdb->write_key($imsTrackReqTempoKeyAll, $data);
			}

			$dbResult =
				mysql_query(
					"SELECT COUNT(distinct ip) as value FROM log_request " .
						" WHERE datetime >= '$currMin'" .
						" AND datetime < '$nextMin';",
					$imsDBConn);
			if ($row = mysql_fetch_array($dbResult)) {
				$value = $row['value'];
				$data = array(new DataPoint(new DateTime($currMin), intval($value)));
				$tdb->write_key($imsTrackReqTempoKeyDistinctIP, $data);
			}			
		}
	}
?>
<?php
	require('00_suffix.php');
?>
