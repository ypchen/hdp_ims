<?php
	echo "<?xml version=\"1.0\" encoding=\"UTF8\" ?>\r\n";
	echo "<rss version=\"2.0\" xmlns:dc=\"http://purl.org/dc/elements/1.1/\">\r\n";
?>
<?php
	require('00_prefix.php');
	$myName = basename($myScriptName, '.php');
	$myBaseName = basename($myName, '.link');
?>
<?php
	include('06_get.link.inc');

	ini_set('user_agent', $userAgent);

	if (isset($extra)) {
		// $extra may be changed by included scripts
		$extra_03_link = $extra;
	}
	else {
		unset($extra_03_link);
	}

	$titleComponents = explode('.', $myBaseName);
	$pageTitleBase = $titleComponents[0];
	$pageTitle = $pageTitleBase;
	if (isset($title)) {
		$pageTitle = $pageTitle . ': ' . $title;
	}

	// Create my own link
	$params  = str_replace('&', '&amp;', $_SERVER['QUERY_STRING']);
	$currUrl = $scriptsURLprefix . '/' . $myName . '.php?' . $params;
?>

<onEnter>
	dataBrowse   = "<?php echo $fileBrowse; ?>";
	dataWatch    = "<?php echo $fileWatch; ?>";
	dataFavorite = "<?php echo $fileFavorite; ?>";

	dataBrowseMax   = <?php echo $maxBrowse; ?>;
	dataWatchMax    = <?php echo $maxWatch; ?>;
	dataFavoriteMax = <?php echo $maxFavorite; ?>;

	history = <?php echo $history; ?>;
	if (history == 0) {
		/* Parameters */
		dataFile   = dataWatch;
		dataMax    = dataWatchMax;
		dataType   = "1";
		dataTitle  = "<?php echo $pageTitle; ?>";
		dataLink   = "<?php echo $currUrl; ?>";
		<?php include('08_history.record.inc'); ?>
	}
</onEnter>

<mediaDisplay name="threePartsView"
	showHeader="no"
	itemBackgroundColor="0:0:0"
	backgroundColor="0:0:0"
	sideLeftWidthPC="0"
	itemImageXPC="5"
	itemXPC="20"
	itemYPC="20"
	itemWidthPC="80"
	capWidthPC="70"
	unFocusFontColor="101:101:101"
	focusFontColor="255:255:255"
	popupXPC = "40"
	popupYPC = "55"
	popupWidthPC = "22.3"
	popupHeightPC = "5.5"
	popupFontSize = "13"
	popupBorderColor="28:35:51"
	popupForegroundColor="255:255:255"
	popupBackgroundColor="28:35:51"
	idleImageWidthPC="10"
	idleImageHeightPC="10"
>

	<idleImage>image/<?php echo $idleImagePrefix; ?>1.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>2.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>3.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>4.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>5.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>6.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>7.png</idleImage>
	<idleImage>image/<?php echo $idleImagePrefix; ?>8.png</idleImage>

	<backgroundDisplay>
		<image offsetXPC="0" offsetYPC="0" widthPC="100" heightPC="100">
			image/mele/backgd.jpg
		</image>
	</backgroundDisplay>

	<image offsetXPC="0" offsetYPC="2.8" widthPC="100" heightPC="15.6">
		image/mele/rss_title.jpg
	</image>

	<text offsetXPC="40" offsetYPC="8"
		widthPC="35" heightPC="10"
		fontSize="20"
		backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
		[確定]: 播放
	</text>

</mediaDisplay>

<channel>

	<title><?php echo $title; ?></title>
	<?php
		$pass_check = true;
		try {
			include($myName . '.inc');
		}
		catch (Exception $e) {
			$pass_check = false;
		}
	?>

</channel>
</rss>

<?php
	require('00_suffix.php');
?>
