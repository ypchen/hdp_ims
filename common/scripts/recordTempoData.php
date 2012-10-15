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

	$tdb = new TempoDB(@getenv('TEMPODB_API_KEY'), @getenv('TEMPODB_API_SECRET'));

	$now = time();
	$Y = date("Y", $now);
	$m = date("m", $now);
	$d = date("d", $now);
	$H = date("H", $now);
	$i = date("i", $now);

	$currMin = date("Y-m-d H:i:s", mktime($H, $i-1, 0, $m, $d, $Y));
	$nextMin = date("Y-m-d H:i:s", mktime($H, $i,   0, $m, $d, $Y));

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

	// Do it again for the data for two weeks ago (fail-safe)
	$currMinLast = date("Y-m-d H:i:s", mktime($H, $i-1, 0, $m, $d-14, $Y));
	$nextMinLast = date("Y-m-d H:i:s", mktime($H, $i,   0, $m, $d-14, $Y));

	$dbResult =
		mysql_query(
			"SELECT COUNT(ip) as value FROM log_request " .
				" WHERE datetime >= '$currMinLast'" .
				" AND datetime < '$nextMinLast';",
			$imsDBConn);
	if ($row = mysql_fetch_array($dbResult)) {
		$value = $row['value'];
		$data = array(new DataPoint(new DateTime($currMinLast), intval($value)));
		$tdb->write_key($imsTrackReqTempoKeyAll, $data);
	}

	$dbResult =
		mysql_query(
			"SELECT COUNT(distinct ip) as value FROM log_request " .
				" WHERE datetime >= '$currMinLast'" .
				" AND datetime < '$nextMinLast';",
			$imsDBConn);
	if ($row = mysql_fetch_array($dbResult)) {
		$value = $row['value'];
		$data = array(new DataPoint(new DateTime($currMinLast), intval($value)));
		$tdb->write_key($imsTrackReqTempoKeyDistinctIP, $data);
	}
?>
<?php
	require('00_suffix.php');
?>
