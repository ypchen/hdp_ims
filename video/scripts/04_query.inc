<?php
	if (!isset($pageStart) || ($pageStart < 0))
		$pageStart = 1;

	if (!isset($queryLevel) || (strlen($queryLevel) == 0))
		$queryLevel = '.query';

	if (!isset($data))
		$data = '';

	if (!isset($note))
		$note = '';

	$linkAll = $scriptsURLprefix . '/' .
		$myBaseName . $queryLevel . '.php' .
			'?uid=' . $user_id  .
			'&amp;input_method='  . urlencode($inputMethod) .
			'&amp;youtube_video=' . urlencode($localhostYoutubeVideo) .
			'&amp;query=' . $pageStart .
				',' . urlencode($link) .
				',' . urlencode($title) .
				',' . urlencode($extra);

	if($title != ''){
		echo
			"<item>\r\n" .
				"\t<title>"      . $title   . $data . "</title>\r\n" .
				"\t<link>"       . $linkAll . "</link>\r\n" .
				"\t<note>"       . $note    . "</note>\r\n" .
				"\t<site_link>"  . $link    . "</site_link>\r\n" .
				"\t<site_extra>" . $extra   . "</site_extra>\r\n" .
				"\t<image>"      . $image   . "</image>\r\n" .
			"</item>\r\n\r\n";
	}
?>
