<?php
	error_reporting(E_ALL ^ (E_NOTICE | E_WARNING));

	$myScriptName     = $_SERVER['SCRIPT_NAME'];

	$serverName       = $_SERVER['SERVER_NAME'];
	$serverPort       = $_SERVER['SERVER_PORT'];
	$remoteIP         = $_SERVER['REMOTE_ADDR'];

	// I do this because I would like to combine my own running site with the released code
	if (file_exists('../../common/ypSettings.php')) {
		require('../../common/ypSettings.php');
	}
	else {
		require('../../common/settings.php');
	}

	require('../../common/constants.php');
	require('../../common/utilities.php');
	require('../../common/database.php');

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
	$maxBrowse        = 100;
	$maxWatch         = 50;
	$maxFavorite      = 50;
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
	$fileLocalYoutubeVideoCCPrefs = $filePath . 'ims_yv_cc_prefs.dat';

	// Local file for extra information
	$fileLocalExtraInfo = $filePath . 'ims_extra_info.dat';

	// Local files for handling closed captioning
	$fileLocalCCStart = $filePath . 'ims_cc_start.dat';
	$fileLocalCCEnd   = $filePath . 'ims_cc_end.dat';
	$fileLocalCCText  = $filePath . 'ims_cc_text.dat';

	$imsDBConn = null;
	if (!empty($imsUseDB)) {
		$imsDBConn = mysql_connect($imsDBHost, $imsDBUser, $imsDBPass);
		if (!$imsDBConn) {
			$condition = '(!$imsDBConn)';

			$emailSent =
				notification_email_text(
					'IMS problem: ' . $imsDirectory . ' / database connection',
					'$myScriptName = ' . $myScriptName . "\r\n" .
						'$condition = ' . $condition
				);

			exit();
		}
		mysql_select_db($imsDBName, $imsDBConn);
	}

	//log_page($imsDBConn, $remoteIP, $myScriptName, '00-prefix');

	$user_id = 0;

	if (strcmp($imsDirectory, 'hotfix') != 0) {
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
?>
