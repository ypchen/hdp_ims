<?php
	if (!isset($pageStart) || ($pageStart < 0))
		$pageStart = 1;

	if (!isset($queryLevel) || (strlen($queryLevel) == 0))
		$queryLevel = '.query';

	if (!isset($data))
		$data = '';

	if (!isset($dataSupp))
		$dataSupp = '';

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
					"\t<title>"       . $title    . $data . "</title>\r\n" .
					"\t<link>"        . $linkAll  . "</link>\r\n";
		if (!isset($note))
			echo	"\t<note></note>\r\n";
		else if (is_array($note))
			echo	"\t<note_one>"   . $note[0]   . "</note_one>\r\n" .
					"\t<note_two>"   . $note[1]   . "</note_two>\r\n" .
					"\t<note_three>" . $note[2]   . "</note_three>\r\n" .
					"\t<note_four>"  . $note[3]   . "</note_four>\r\n";
		else
			echo	"\t<note>"        . $note     . "</note>\r\n";
		echo		"\t<site_link>"   . $link     . "</site_link>\r\n" .
					"\t<site_extra>"  . $extra    . "</site_extra>\r\n" .
					"\t<site_supp>"   . $dataSupp . "</site_supp>\r\n" .
					"\t<image>"       . $image    . "</image>\r\n" .
			"</item>\r\n\r\n";
	}
?>
