<?php
	if (!isset($clickPlay))
		$clickPlay = 'no';

	if (!isset($linkLevel) || (strlen($linkLevel) == 0))
		$linkLevel = '.link';

	if (!isset($dataSupp))
		$dataSupp = '';

	$linkAll = $scriptsURLprefix . '/' .
		$myBaseName . $linkLevel . '.php' .
			'?uid=' . $user_id  .
			'&amp;input_method='  . urlencode($inputMethod) .
			'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
			'&amp;yv_fmt_prefs='  . urlencode($youtubeVideoFmtPrefs) .
			'&amp;yv_cc_prefs='   . urlencode($youtubeVideoCCPrefs) .
			'&amp;yv_rmt_src='    . urlencode($youtubeVideoRemoteSource) .
			'&amp;query=' . urlencode($link) .
				',' . urlencode(str_replace(',', '%2C', $title)) .
				',' . urlencode($extra) .
			$dataSupp;

	if($title != ''){
		echo
			"\t<item>\r\n" .
				"\t\t<title>"      . $title     . "</title>\r\n" .
				"\t\t<link>"       . $linkAll   . "</link>\r\n" .
				"\t\t<click_play>" . $clickPlay . "</click_play>\r\n" .
				"\t\t<note_one>"   . $note[0]   . "</note_one>\r\n" .
				"\t\t<note_two>"   . $note[1]   . "</note_two>\r\n" .
				"\t\t<note_three>" . $note[2]   . "</note_three>\r\n" .
				"\t\t<note_four>"  . $note[3]   . "</note_four>\r\n" .
				"\t\t<site_link>"  . $link      . "</site_link>\r\n" .
				"\t\t<site_extra>" . $extra     . "</site_extra>\r\n" .
				"\t\t<site_supp>"  . $dataSupp  . "</site_supp>\r\n" .
				"\t\t<image>"                 . $image . "</image>\r\n" .
				"\t\t<media:thumbnail url=\"" . $image . "\" />\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n\r\n";
	}
?>
