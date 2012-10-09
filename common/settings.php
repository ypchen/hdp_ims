<?php
	// Global variables

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
	$imsUseDB      = false;
	// Database configuration
	$imsDBHost     = 'yourDB_host';
	$imsDBName     = 'yourDB_name';
	$imsDBUser     = 'yourDB_username';
	$imsDBPass     = 'yourDB_password';

	// Use curl (or not) to get remote contents
	$imsUseCurl    = true;

	// Need to authenticate users?
	$imsUseAuthentication = false;

	// Default url on the localhost to handle youtube videos
	// it can be changed by using youtube_video
	// port 8081 is the default port for iMax firmware
	$defaultLocalhostYoutubeVideo = 'http://localhost:8081/scripts/youtube.video.php';

	// Default format preference
	// http://en.wikipedia.org/wiki/YouTube
	$defaultYoutubeVideoFmtPrefs = '22,35,34,18,6,5';
?>
