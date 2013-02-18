<?php
	error_reporting(E_ALL ^ (E_NOTICE | E_WARNING));

	// Load helpers first
	require('../../common/constants.php');
	require('../../common/utilities.php');
	require('../../common/database.php');

	// I do this because I would like to combine my own running site with the released code
	if (file_exists('../../common/ypSettings.php')) {
		require('../../common/ypSettings.php');
	}
	else {
		require('../../common/settings.php');
	}
	// local_settings.php overrides other settings.php
	if (file_exists('../../common/local_settings.php')) {
		require('../../common/local_settings.php');
	}
	// Environment variables, if exist, will override the settings written in PHP files.
	// Heroku deployment can be done via setting the corresponding variables.
	require('../../common/environment.php');

	// If redir is used, redir to the destination
	if (!empty($imsUseRedir)) {
		$protocol = (((!isset($_SERVER['HTTPS'])) || ($_SERVER['HTTPS'] != 'on')) ? 'http://' : 'https://');
		header('Location: ' . $protocol . $imsRedirTo . $_SERVER['REQUEST_URI']);
		exit();
	}

	date_default_timezone_set($imsTimeZone);

	// Get the version info
	if (!isset($imsVersion)) {
		if (!isset($imsFullVersion)) {
			if (file_exists($fileVersion = '../../imsVersion')) {
				$imsFullVersion = trim(file_get_contents($fileVersion));
			}
			else {
				$imsFullVersion = ': : ';
			}
		}

		$imsFullVersionComp = explode(': ', $imsFullVersion);
		if (strlen($imsVersion = trim($imsFullVersionComp[0])) <= 0) {
			$imsVersion = trim($imsFullVersionComp[2]);
		}
	}

	$myScriptName     = $_SERVER['SCRIPT_NAME'];

	$serverName       = $_SERVER['SERVER_NAME'];
	$serverPort       = $_SERVER['SERVER_PORT'];
	if (!empty($imsOnHeroku))
		$remoteIPStr  = getRealIPAddress();
	else
		$remoteIPStr  = getRemoteIPAddress();
	$remoteIPs = explode(',', $remoteIPStr);
	$remoteIP  = trim($remoteIPs[0]);

	$userAgent        = $userAgentFF3;

	$wholeURL         = wholeURLforTheExecutedFile();
	$rawPrefixURL     = strrleft($wholeURL, '/scripts');
	$imsDirectory     = strrright($rawPrefixURL, '/');
	$scriptsURLprefix = $rawPrefixURL . '/scripts';
	$imagePrefix      = $rawPrefixURL . '/image/';
	$filesPrefix      = $rawPrefixURL . '/files/';

	$idleImagePrefix  = 'busy';

	// Default main image width and height
	$myImgWidth       = 35;
	$myImgHeight      = 35;

	// Default values
	$itemXPC          = 5;
	$itemYPC          = 21.5;
	$itemWidthPC      = 50;
	$itemHeightPC     = 5.7;
	$itemPerPage      = 11;
	$rowCount         = 11;
	$columnCount      = 4;

	// History and favorites
	$filePath         = '/usr/local/etc/dvdplayer/';
	$fileBrowse       = $filePath . 'ims_' . $imsDirectory . '_browse.dat';
	$fileWatch        = $filePath . 'ims_' . $imsDirectory . '_watch.dat';
	$fileFavorite     = $filePath . 'ims_' . $imsDirectory . '_favorites.dat';
	$maxBrowse        = 110;
	$maxWatch         = 55;
	$maxFavorite      = 55;
	$historyCheckMax  = 5;

	// Default url for input methods
	// it can be changed by using input_method
	if ((strcmp($serverName, 'localhost') == 0) ||
		(strcmp($serverName, '127.0.0.1') == 0)) {
		$defaultInputMethod =
			strrleft($wholeURL, $imsDirectory . '/scripts') .
				'common/ypInput/getFile.php?file=keyboard.rss';
	}
	else {
		$defaultInputMethod =
			strrleft($wholeURL, $imsDirectory . '/scripts') .
				'ypInput/getFile.php?file=keyboard.rss';
	}

	// Default url for updating youtube.video.php
	// it can be changed by using yv_rmt_src
	$defaultYoutubeVideoRemoteSource =
		strrleft($wholeURL, $imsDirectory . '/scripts') .
			'scripts/youtube.video.php';

	// Default local youtube format prefs file
	$fileLocalYoutubeVideoFmtPrefs = $filePath . 'ims_yv_fmt_prefs.dat';

	// Default local youtube cc prefs file
	$fileLocalYoutubeVideoCCPrefs  = $filePath . 'ims_yv_cc_prefs.dat';

	// Local cc fsize file
	$fileLocalCCFSize   = $filePath . 'ims_cc_fsize.dat';

	// Local cc fcolor file
	$fileLocalCCFColor  = $filePath . 'ims_cc_fcolor.dat';

	// Local files for handling closed captioning
	$fileLocalCCCount   = $filePath . 'ims_cc_count.dat';
	$fileLocalCCStart   = $filePath . 'ims_cc_start.dat';
	$fileLocalCCEnd     = $filePath . 'ims_cc_end.dat';
	$fileLocalCCText    = $filePath . 'ims_cc_text.dat';
	$fileLocalCCStatus  = $filePath . 'ims_cc_status.dat';

	// Local file for extra information
	$fileLocalExtraInfo = $filePath . 'ims_extra_info.dat';

	$imsDBConn = null;
	if (!empty($imsUseDB)) {
		$imsDBConn = mysql_connect($imsDBHost, $imsDBUser, $imsDBPass);
		if (!$imsDBConn) {
			$condition = '(!$imsDBConn)';

			$emailSent =
				notification_email_text(
					'IMS problem: ' . $imsDirectory . ' / database connection',
					'$myScriptName = ' . $myScriptName . "\r\n" .
						'$condition = ' . $condition . "\r\n" .
						'mysql_error() = ' . mysql_error()
				);

			exit();
		}
		mysql_select_db($imsDBName, $imsDBConn);
		mysql_query("SET time_zone = '" . $imsDBTimeZone . "';", $imsDBConn);
	}

	if (empty($noNeedToLogRequest)) {
		log_request($imsDBConn, $remoteIP);
		if (!empty($imsLogVisitedPage))
			log_page($imsDBConn, $remoteIP, $myScriptName, $remoteIP);
	}

	$user_id = 0;

	if ((strcmp($imsDirectory, 'hotfix') != 0) && (strcmp($imsDirectory, 'common') != 0)) {
		if (!empty($imsUseAuthentication)) {
			// uid from the HTTP GET request
			if ((!isset($_GET['uid'])) ||
				(strlen($uidStr = $_GET['uid']) == 0)
				) {
				$condition = '((!isset($_GET[\'uid\'])) || (strlen($uid = $_GET[\'uid\']) == 0))';

				$emailSent =
					notification_email_text(
						'IMS alert: ' . $imsDirectory . ' / empty uid',
						'$myScriptName = ' . $myScriptName .
							"\r\n" . '$ip = ' . $remoteIP .
							"\r\n" . '$condition = ' . $condition
					);

				log_page($imsDBConn, $remoteIP, $myScriptName,
					'$emailSent = ' . $emailSent .
						'; $condition = ' . $condition
				);

				exit();
			}
			$uid = intval($uidStr);

			// Get the user_id
			$user_id = check_user_id_ims($imsDBConn, $remoteIP, $allowedSeconds, $myScriptName, $uid);
			if ($user_id == 0) {
				$condition = '($user_id == 0)';

				$emailSent =
					notification_email_text(
						'IMS alert: ' . $imsDirectory . ' / unknown user',
						'$myScriptName = ' . $myScriptName .
							"\r\n" . '$ip = ' . $remoteIP .
							"\r\n" . '$condition = ' . $condition
					);

				log_page($imsDBConn, $remoteIP, $myScriptName,
					'$emailSent = ' . $emailSent .
						'; $condition = ' . $condition
				);

				exit();
			}
		}
	}

	header("Content-Type:text/xml; charset=utf-8");
?>
