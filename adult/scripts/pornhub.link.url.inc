<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = '';
	if (strpos($html, 'player_quality_') !== false) {
		$separators = array(
			array("720p", "player_quality_720p = '", "'"),
			array("480p", "player_quality_480p = '", "'"),
			array("240p", "player_quality_240p = '", "'"),
		);
		foreach ($separators as $separator) {
			$link = trim(str_between($html, $separator[1], $separator[2]));
			if (!empty($link)) {
?>
	writeStringToFile("<?php echo $fileLocalExtraInfo; ?>", "<?php echo $separator[0]; ?>");
<?php
				break;
			}
		}
	}
	$link = str_replace('&', '&amp;', $link);
	include('05_check.link.inc');

	$links = array($link);
	$titles = array($title);

	$itemTotal = count($links);
?>
