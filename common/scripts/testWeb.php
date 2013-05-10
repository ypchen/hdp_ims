<?php
	$noNeedToLogRequest = true;
	require('00_prefix.php');

	// Change the content-type
	header("Content-Type:text/html; charset=utf-8");

	$myName = basename($myScriptName, '.php');
?>
<?php
	// Check the api key first
	if ((!isset($_GET['apikey'])) ||
		(strcmp($apikey = urldecode($_GET['apikey']), $imsAPIKey) != 0))
		exit();
?>
<HTML>
<HEAD>
	<TITLE>IMS web test</TITLE>
</HEAD>
<BODY>
		<H2>IMS web test</H2>
		<UL>
			<LI><?php echo '$_SERVER["HTTP_HOST"] = ' . $_SERVER["HTTP_HOST"]; ?></LI>
			<LI><?php echo '$myScriptName = ' . $myScriptName; ?></LI>
			<LI><?php echo '$ip = ' . $remoteIP; ?></LI>
		</UL>
</BODY>
</HTML>
<?php
	require('00_suffix.php');
?>
