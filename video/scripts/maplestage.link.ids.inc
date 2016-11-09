<?php
	// For maplestage
	$html = yp_file_get_contents(
		$link,
		FALSE,
		$r = 'Referer: http://maplestage.com/show/' . urlencode(base64_decode($extra))
	);
	include('05_check.file_contents.inc');
	
	$results = json_decode('{' . trim(str_between($html, 'var pageData = {', '};')) . '}', TRUE);

	$title = str_replace('"', '＂', convertUnicodePoints($results['title'][0]));
	
	$srcPrefix = 'MPLSTG-';
	foreach ($results['props'][2]['value']['videoSources'] as $v) {

		switch ($src = $v['name']) {

			case 'youtube':
				$ids = array();
				foreach ($v['videos'] as $item) {
					$ids[] = $item['id'];
				}
				include('05_check.link.idcount.inc');
				return;

			case 'dailymotion':
				$links = array();
				foreach ($v['videos'] as $item) {
					$id =  $item['id'];
					$links[] =
						$localhostYoutubeVideo . '?query=site_dailymotion' .
							'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
							'&amp;fmt_prefs='  . urlencode($vdeoFmtPrefs) .
							'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
							'&amp;actual_src=' . urlencode($srcPrefix . $src) .
							'&amp;link='       . urlencode('http://www.dailymotion.com/embed/video/' . $id);
				}
				$itemTotal = count($links);
				include('05_check.base.inc');
				return;

			default:
				// Try next
				break;
		}
	}
	
	// Unknown format or no 'data-data' section
	$ids = array();
	include('05_check.link.idcount.inc');
?>
