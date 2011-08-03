<?php
	error_reporting(E_ALL ^ (E_NOTICE | E_WARNING));

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

	$myScriptName     = $_SERVER['SCRIPT_NAME'];
	$remoteIP         = $_SERVER['REMOTE_ADDR'];

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
	$defaultInputMethod =
		strrleft($wholeURL, $imsDirectory . '/scripts') .
			'ypInput/getFile.php?file=keyboard.rss';

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
				(strlen($uidStr = urldecode($_GET['uid'])) == 0)
				) {
				$condition = '((!isset($_GET[\'uid\'])) || (strlen($uid = urldecode($_GET[\'uid\'])) == 0))';

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
