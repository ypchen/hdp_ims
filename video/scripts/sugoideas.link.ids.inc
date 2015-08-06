<?php
	// For sugoideas
	$link = str_replace('http://sugoitw.sugoideas.com/', 'http://tw.sugoitw.com/', $link);
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$ts = explode('-', str_between($html, '<title>', '</title>'));
	$title = trim($ts[0]);
	$title = convertUnicodePoints($title);

	$srcPrefix = 'SGID-';
	if ((strpos($html, 'div class="videodiv"') !== false) && (strpos($html, 'table class="videopart"') !== false)) {
		$links_raw = array();
		$html_videodiv = str_between($html, 'div class="videodiv"', '/div');
		$html_videopart = str_between($html, 'table class="videopart"', '/table');
		if (strpos($html_videopart, 'a class="contentlist"') === false) {
			if (strpos($html_videodiv, ' src="') !== false)
				$delim = '"';
			else
				$delim = "'";
			$link = urldecode(trim(str_between($html_videodiv, ' src=' . $delim, $delim)));
			$links_raw[] = $link;
		}
		else {
			$parts = explode('a class="contentlist"', $html_videopart);
			unset($parts[0]);
			$parts = array_values($parts);
			if (strpos($html_videopart, '>Full</') !== false) {
				// If "Full" exists, it would be the last one.
				$link = trim(str_between($parts[count($parts)-1], 'href="', '"'));
				$html = yp_file_get_contents($link);
				include('05_check.file_contents.inc');
				if (strpos($html_videodiv = str_between($html, 'div class="videodiv"', '/div'), ' src="') !== false)
					$delim = '"';
				else
					$delim = "'";
				$link = urldecode(trim(str_between($html_videodiv, ' src=' . $delim, $delim)));
				$links_raw[] = $link;
			}
			else {
				if (strpos($html_videodiv, ' src="') !== false)
					$delim = '"';
				else
					$delim = "'";
				$link = urldecode(trim(str_between($html_videodiv, ' src=' . $delim, $delim)));
				$links_raw[] = $link;
				foreach ($parts as $part) {
					$link = trim(str_between($part, 'href="', '"'));
					$html = yp_file_get_contents($link);
					include('05_check.file_contents.inc');
					if (strpos($html_videodiv = str_between($html, 'div class="videodiv"', '/div'), ' src="') !== false)
						$delim = '"';
					else
						$delim = "'";
					$link = urldecode(trim(str_between($html_videodiv, ' src=' . $delim, $delim)));
					$links_raw[] = $link;
				}
			}
		}

		if (strpos($links_raw[0], 'youtube.com') !== false) {
			$ids = array();
			foreach ($links_raw as $link) {
				$ids[] = trim(str_between($link, '/embed/', '?'));
			}
			include('05_check.link.idcount.inc');
		}
		else {
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
	}
	else {
		// Clear-text youtube url(s) not found
		// Unknown sugoideas format
		$ids = array();
		include('05_check.link.idcount.inc');
	}
?>
