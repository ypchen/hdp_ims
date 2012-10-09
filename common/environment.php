<?php
	// Environment variables

	// Running on heroku
	if (($envVar = @getenv('IMS_ON_HEROKU')) !== false) {
		$imsOnHeroku   = booleanValuefromString($envVar);
	}
	// Send mails via MailGun
	if (($envVar = @getenv('IMS_ON_MAILGUN')) !== false) {
		$imsOnMailGun  = booleanValuefromString($envVar);
	}

	// Notification emails will be sent
	if (($envVar = @getenv('IMS_USE_EMAIL')) !== false) {
		$imsUseEmail   = booleanValuefromString($envVar);
	}
	// From imsBotEmail to imsAdminEmail
	if (($envVar = @getenv('IMS_BOT_EMAIL')) !== false) {
		$imsBotEmail   = $envVar;
	}
	if (($envVar = @getenv('IMS_ADMIN_EMAIL')) !== false) {
		$imsAdminEmail = $envVar;
	}

	// Database will be used for logging and authentication
	if (($envVar = @getenv('IMS_USE_DB')) !== false) {
		$imsUseDB      = booleanValuefromString($envVar);
	}
	// Database configuration
	if (($envVar = @getenv('IMS_DB_HOST')) !== false) {
		$imsDBHost     = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_NAME')) !== false) {
		$imsDBName     = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_USER')) !== false) {
		$imsDBUser     = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_PASS')) !== false) {
		$imsDBPass     = $envVar;
	}

	// Use curl (or not) to get remote contents
	if (($envVar = @getenv('IMS_USE_CURL')) !== false) {
		$imsUseCurl    = booleanValuefromString($envVar);
	}

	// Need to authenticate users?
	if (($envVar = @getenv('IMS_USE_AUTHENTICATION')) !== false) {
		$imsUseAuthentication = booleanValuefromString($envVar);
	}

	// Default url on the localhost to handle youtube videos
	// it can be changed by using youtube_video
	// port 8081 is the default port for iMax firmware
	if (($envVar = @getenv('DEFAULT_LOCALHOST_YOUTUBE_VIDEO')) !== false) {
		$defaultLocalhostYoutubeVideo = $envVar;
	}
	
	// Default format preference
	// http://en.wikipedia.org/wiki/YouTube
	if (($envVar = @getenv('DEFAULT_YOUTUBE_VIDEO_FMT_PREFS')) !== false) {
		$defaultYoutubeVideoFmtPrefs = $envVar;
	}
?>
