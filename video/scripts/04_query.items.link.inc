<?php
	if (!isset($clickPlay))
		$clickPlay = 'no';

	$linkAll = $scriptsURLprefix . '/' .
		$myBaseName . '.link.php' .
			'?uid=' . $user_id  .
			'&amp;input_method='  . urlencode($inputMethod) .
			'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
			'&amp;query=' . urlencode($link) .
				',' . urlencode($title) .
				',' . urlencode($extra);

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
				"\t\t<image>"                 . $image . "</image>\r\n" .
				"\t\t<media:thumbnail url=\"" . $image . "\" />\r\n" .
				"\t\t<mediaDisplay name=\"threePartsView\" />\r\n" .
			"\t</item>\r\n\r\n";
	}
?>
