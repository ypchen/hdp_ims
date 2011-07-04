<?php
	// Global variables

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
	$imsUseCurl    = false;

	// Need to authenticate users?
	$imsUseAuthentication = false;

	// url on the localhost to handle youtube videos
	// it can be changed by using youtube_video
	$defaultLocalhostYoutubeVideo = 'http://localhost/scripts/youtube.video.php';
?>
