<?php
	// Global variables

	// Redirect to another host
	$imsUseRedir   = false;
	$imsRedirTo    = '';

	// Time zone
	$imsTimeZone   = "Asia/Taipei";

	// Running on heroku
	$imsOnHeroku   = false;
	// Send mails via MailGun
	$imsOnMailGun  = false;

	// Notification emails will be sent
	$imsUseEmail   = false;
	// From imsBotEmail to imsAdminEmail
	$imsBotEmail   = 'bot.IMS <bot.ims@ims.org>';
	$imsAdminEmail = 'admin.IMS <admin.ims@ims.org>';

	// Database will be used for logging and authentication
	$imsUseDB                      = false;
	$imsDBTimeZone                 = '+08:00';
	// Database configuration
	$imsDBHost                     = 'yourDB_host';
	$imsDBName                     = 'yourDB_name';
	$imsDBUser                     = 'yourDB_username';
	$imsDBPass                     = 'yourDB_password';
	// Remove old records
	$imsDBToRemove                 = '6 MONTH';
	$imsDBToRemoveAPIKey           = 'Key you specified';
	// Track requests (need to use DB and also Tempo DB on Heroku)
	$imsTrackReq                   = false;
	$imsTrackReqAPIKey             = 'Key you specified';
	// Tempo DB key for recording all requests
	$imsTrackReqTempoKeyAll        = 'requests_all';
	// Tempo DB key for recording all requests from distinct ips
	$imsTrackReqTempoKeyDistinctIP = 'requests_distinct_ip';

	// Use curl (or not) to get remote contents
	$imsUseCurl = true;

	// Need to authenticate users?
	$imsUseAuthentication = false;

	// Need to record visited pages?
	// 1. Database is needed
	// 2. If authentication is enabled, visited pages are automatically logged
	$imsLogVisitedPage = true;
	// Send $html / $htmlToExplode when check goes wrong
	$imsCheckSendHTML  = false;
	// Log  $html / $htmlToExplode when check goes wrong
	$imsCheckLogHTML   = false;

	// Turn off the following adult sites (Eg., 'thisav,tjoob')
	$imsTurnOffAdultSites = '';
	// Turn off the following video sites (Eg., 'appledaily,maplestage')
	$imsTurnOffVideoSites = '';

	// Default url on the localhost to handle youtube videos
	// it can be changed by using youtube_video
	// port 8081 is the default port for iMax firmware
	$defaultLocalhostYoutubeVideo = 'http://localhost:8081/scripts/youtube.video.php';

	// Default format preference
	// http://en.wikipedia.org/wiki/YouTube
	$defaultYoutubeVideoFmtPrefs = '22,35,18,34,6,5';
?>
