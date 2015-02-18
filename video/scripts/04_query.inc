<?php
	if (!isset($pageStart) || ($pageStart < 0))
		$pageStart = 1;

	if (!isset($queryLevel) || (strlen($queryLevel) == 0))
		$queryLevel = '.query';

	if (!isset($data))
		$data = '';

	if (!isset($dataSupp))
		$dataSupp = '';

	if (!isset($note))
		$note = '';

	$linkAll = $scriptsURLprefix . '/' .
		$myBaseName . $queryLevel . '.php' .
			'?uid=' . $user_id  .
			'&amp;cc_prefs='        . urlencode($videoCCPrefs) .
			'&amp;fmt_prefs='       . urlencode($videoFmtPrefs) .
			'&amp;yv_rmt_src='      . urlencode($youtubeVideoRemoteSource) .
			'&amp;youtube_video='   . urlencode($localhostYoutubeVideo) .
			'&amp;query=' . $pageStart .
				',' . urlencode($link) .
				',' . urlencode(str_replace(',', '%2C', $title)) .
				',' . urlencode($extra) .
			$dataSupp;

	if($title != ''){
		echo
			"<item>\r\n" .
				"\t<title>"       . $title   . $data . "</title>\r\n" .
				"\t<link>"        . $linkAll . "</link>\r\n" .
				"\t<note>"        . $note    . "</note>\r\n" .
				"\t<site_link>"   . $link    . "</site_link>\r\n" .
				"\t<site_extra>"  . $extra   . "</site_extra>\r\n" .
				"\t\t<site_supp>" . $dataSupp  . "</site_supp>\r\n" .
				"\t<image>"       . $image   . "</image>\r\n" .
			"</item>\r\n\r\n";
	}
?>
