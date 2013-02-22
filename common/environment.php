<?php
	// Environment variables

	// Redirect to another host
	if (($envVar = @getenv('IMS_USE_REDIR')) !== false) {
		$imsUseRedir = booleanValuefromString($envVar);
	}
	if (($envVar = @getenv('IMS_REDIR_TO')) !== false) {
		$imsRedirTo = $envVar;
	}

	// Time zone
	if (($envVar = @getenv('IMS_TIME_ZONE')) !== false) {
		$imsTimeZone = $envVar;
	}

	// Running on heroku
	if (($envVar = @getenv('IMS_ON_HEROKU')) !== false) {
		$imsOnHeroku = booleanValuefromString($envVar);
	}
	// Send mails via MailGun
	if (($envVar = @getenv('IMS_ON_MAILGUN')) !== false) {
		$imsOnMailGun = booleanValuefromString($envVar);
	}

	// Notification emails will be sent
	if (($envVar = @getenv('IMS_USE_EMAIL')) !== false) {
		$imsUseEmail = booleanValuefromString($envVar);
	}
	// From imsBotEmail to imsAdminEmail
	if (($envVar = @getenv('IMS_BOT_EMAIL')) !== false) {
		$imsBotEmail = $envVar;
	}
	if (($envVar = @getenv('IMS_ADMIN_EMAIL')) !== false) {
		$imsAdminEmail = $envVar;
	}

	// Database will be used for logging and authentication
	if (($envVar = @getenv('IMS_USE_DB')) !== false) {
		$imsUseDB = booleanValuefromString($envVar);
	}
	if (($envVar = @getenv('IMS_DB_TIME_ZONE')) !== false) {
		$imsDBTimeZone = $envVar;
	}
	// Database configuration
	if (($envVar = @getenv('IMS_DB_HOST')) !== false) {
		$imsDBHost = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_NAME')) !== false) {
		$imsDBName = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_USER')) !== false) {
		$imsDBUser = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_PASS')) !== false) {
		$imsDBPass = $envVar;
	}
	// Remove old records
	if (($envVar = @getenv('IMS_DB_TO_REMOVE')) !== false) {
		$imsDBToRemove = $envVar;
	}
	if (($envVar = @getenv('IMS_DB_TO_REMOVE_API_KEY')) !== false) {
		$imsDBToRemoveAPIKey = $envVar;
	}
	// Track requests (need to use DB and also Tempo DB on Heroku)
	if (($envVar = @getenv('IMS_TRACK_REQ')) !== false) {
		$imsTrackReq = booleanValuefromString($envVar);
	}
	if (($envVar = @getenv('IMS_TRACK_REQ_API_KEY')) !== false) {
		$imsTrackReqAPIKey = $envVar;
	}
	// Tempo DB key for recording all requests
	if (($envVar = @getenv('IMS_TRACK_REQ_TEMPO_KEY_ALL')) !== false) {
		$imsTrackReqTempoKeyAll = $envVar;
	}
	// Tempo DB key for recording all requests from distinct ips
	if (($envVar = @getenv('IMS_TRACK_REQ_TEMPO_KEY_DISTINCT_IP')) !== false) {
		$imsTrackReqTempoKeyDistinctIP = $envVar;
	}

	// Use curl (or not) to get remote contents
	if (($envVar = @getenv('IMS_USE_CURL')) !== false) {
		$imsUseCurl = booleanValuefromString($envVar);
	}

	// Need to authenticate users?
	if (($envVar = @getenv('IMS_USE_AUTHENTICATION')) !== false) {
		$imsUseAuthentication = booleanValuefromString($envVar);
	}

	// Need to record visited pages?
	// 1. Database is needed
	// 2. If authentication is enabled, visited pages are automatically logged
	if (($envVar = @getenv('IMS_LOG_VISITED_PAGE')) !== false) {
		$imsLogVisitedPage = booleanValuefromString($envVar);
	}
	// Send $html / $htmlToExplode when check goes wrong
	if (($envVar = @getenv('IMS_CHECK_SEND_HTML')) !== false) {
		$imsCheckSendHTML = booleanValuefromString($envVar);
	}
	// Log  $html / $htmlToExplode when check goes wrong
	if (($envVar = @getenv('IMS_CHECK_LOG_HTML')) !== false) {
		$imsCheckLogHTML = booleanValuefromString($envVar);
	}

	// Turn off the following adult sites (Eg., 'thisav,tjoob')
	if (($envVar = @getenv('IMS_TURN_OFF_ADULT_SITES')) !== false) {
		$imsTurnOffAdultSites = $envVar;
	}
	// Turn off the following video sites (Eg., 'appledaily,maplestage')
	if (($envVar = @getenv('IMS_TURN_OFF_VIDEO_SITES')) !== false) {
		$imsTurnOffVideoSites = $envVar;
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

	// Default CC language preference
	if (($envVar = @getenv('DEFAULT_YOUTUBE_VIDEO_CC_PREFS')) !== false) {
		$defaultYoutubeVideoCCPrefs = $envVar;
	}

	// --------------------

	// For multi-hosts deployment
	if (($envVar = @getenv('IMS_HOSTNAME_IMS_HOST')) !== false) {
		$hostnameImsHost = $envVar;
	}
	if (($envVar = @getenv('IMS_HOSTNAME_IMS_HOST_THIS')) !== false) {
		$hostnameImsHostThis = $envVar;
	}
	if (($envVar = @getenv('IMS_HOSTNAME_IMS_HOST_FALLBACK')) !== false) {
		$hostnameImsHostFallback = $envVar;
	}

	// IMS full version
	// tag: commit: shortCommit
	if (($envVar = @getenv('IMS_FULL_VERSION')) !== false) {
		$imsFullVersion = $envVar;
	}
?>
