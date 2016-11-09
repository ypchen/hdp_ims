<?php
	// For sugoideas
	$link = str_replace('http://sugoitw.sugoideas.com/', 'http://tw.sugoitw.com/', $link);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$ts = explode('-', str_between($html, '<title>', '</title>'));
	$title = trim($ts[0]);
	$title = convertUnicodePoints($title);

	$srcPrefix = 'SGID-';
	$links_raw = array();
	$links_raw[] = base64_decode(trim(str_between($html, '.atob("', '"')));
	if (strpos($html, 'table class="videopart"') !== false) {
		$parts = explode('>Part ', str_between($html, 'table class="videopart"', '/table'));
		unset($parts[count($parts)-1]);
		unset($parts[0]);
		$parts = array_values($parts);

		foreach ($parts as $part) {
			$link = trim(str_between($part, ' href="', '"'));
			$html = yp_file_get_contents($link);
			include('05_check.file_contents.inc');
			$links_raw[] = base64_decode(trim(str_between($html, '.atob("', '"')));
		}

		$links = array();
		foreach ($links_raw as $link) {
			if (strpos($link, 'dailymotion.com') !== false) {
				$query = 'site_dailymotion';
				$src = 'Dailymotion';
			}
			else {
				$query = 'site_https_redir';
				if (strpos($link, 'sugoiid') !== false) {
					$src = 'sugoiid';
				}
				else if (strpos($link, 'https') !== false) {
					$src = 'https';
				}
			}
			$link = $localhostYoutubeVideo . '?query=' . $query .
				'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
				'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
				'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
				'&amp;actual_src=' . urlencode($srcPrefix . $src) .
				'&amp;link='       . urlencode($link);
			$links[] = $link;
		}

		$itemTotal = count($links);
		include('05_check.base.inc');
	}
	else {
		// Clear-text youtube url(s) not found
		// Unknown sugoideas format
		$ids = array();
		include('05_check.link.idcount.inc');
	}
?>
