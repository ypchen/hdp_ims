<?php
	// For maplestage
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$title = trim(str_between($html, '<h3>', '</h3>'));
	$title = str_replace('"', '＂', convertUnicodePoints($title));

	$vidSources = explode(' data-data=', $html);
	if (count($vidSources) >= 2) {

		unset($vidSources[0]);
		$vidSources = array_values($vidSources);

		$srcPrefix = 'MPLSTG-';
		$urlComp = array(
			'Letv'		=> array('http://www.letv.com/ptv/vplay/', '.html', '//', ''),
			'QQ'		=> array('http://v.qq.com/cover/2/2w2kh6q2wd10uue.html?vid=', '', '//', ''),
			'Tv56'		=> array('http://www.56.com/u12/v_', '.html', '//', ''),
			'Tudou2'	=> array('http://www.tudou.com/programs/view/', '/', '//', ''),
			'Youku'		=> array('http://v.youku.com/v_show/id_', '.html', '//', ''),
//			'Sohu'		=> array('http://tv.sohu.com/', '.shtml', '/(.*)-/', ''),
		);
		// Look for supported video sources
		foreach ($vidSources as $vidSource) {

			if (strlen($base64 = trim(str_between($vidSource, '"', '"'))) <= 0) continue;

			// Contributed by absentfriend@HDPFans
			$json = base64_decode(strrev($base64));
			$res = json_decode($json, true);
			$src = $res['source'];

			switch ($src) {

				case 'Youtube':
				case 'YoutubeBypass':
					$ids = $res['ids'];
					include('05_check.link.idcount.inc');
					return;

				case 'Dailymotion':
					$links = array();
					foreach($res['ids'] as $id) {
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

				case 'Letv':
				case 'QQ':
				case 'Tv56':
				case 'Tudou2':
				case 'Youku':
//				case 'Sohu':
					$links = array();
					foreach($res['ids'] as $id) {
						$links[] =
							$localhostYoutubeVideo . '?query=site_flvxz' .
								'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
								'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
								'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
								'&amp;actual_src=' . urlencode($srcPrefix . $src) .
								'&amp;link='       . urlencode(
									strtr(base64_encode(
										preg_replace('/^(https?:)\/\//', '$1##',
											($urlComp[$src][0] .
												preg_replace($urlComp[$src][2], $urlComp[$src][3], $id) .
											$urlComp[$src][1]))), '+/', '-_'));
					}
					$itemTotal = count($links);
					include('05_check.base.inc');
					return;

				case 'BiliBili':
					$links = array();
					$id = $res['ids'][0];
					if (count($res['ids']) == 3) {
						$indexStart = intval($res['ids'][1]);
						$indexNum = intval($res['ids'][2]);
					}
					else {
						$indexStart = 1;
						$indexNum = intval($res['ids'][1]);
					}
					for ($index = $indexStart ; $index < ($indexStart+$indexNum) ; $index ++) {
						$links[] =
							$localhostYoutubeVideo . '?query=site_flvxz' .
								'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
								'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
								'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
								'&amp;actual_src=' . urlencode($srcPrefix . $src) .
								'&amp;link='       . urlencode(
									strtr(base64_encode(
										preg_replace('/^(https?:)\/\//', '$1##',
											('http://www.bilibili.com/video/av' .
												$id .
											'/index_' . strval($index) . '.html'))), '+/', '-_'));
					}
					$itemTotal = count($links);
					include('05_check.base.inc');
					return;

				case 'VideoGroup':
					$links = array();
					foreach($res['elements'] as $element) {
						if(strpos($link = urldecode(str_replace('\/', '/', trim(str_between($element, 'src="', '"')))), 'https') !== false) {
							$link = $localhostYoutubeVideo . '?query=site_https_redir' .
								'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
								'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
								'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
								'&amp;actual_src=' . urlencode($srcPrefix . $src) .
								'&amp;link='       . urlencode($link);
						}
						$links[] = $link;
					}
					$itemTotal = count($links);
					include('05_check.base.inc');
					return;

				case 'Html':
					$html = $res['html'];
					$src = '';
					if (strpos($html, 'static.youku.com') !== false) {
						$src = 'Youku';
						$id = trim(str_between(str_between($html, 'VideoID', '"'), 'S=', '&'));
					}
					else if (strpos($html, 'player.youku.com') !== false) {
						$src = 'Youku';
						$id = trim(str_between($html, '/sid/', '/'));
					}
					else if (strpos($html, 'player.56.com') !== false) {
						$src = 'Tv56';
						$id = trim(str_between($html, 'cpm_', '.'));
					}
					if (!empty($src)) {
						$links = array();
						$links[] =
							$localhostYoutubeVideo . '?query=site_flvxz' .
								'&amp;cc_prefs='   . urlencode($videoCCPrefs) .
								'&amp;fmt_prefs='  . urlencode($videoFmtPrefs) .
								'&amp;yv_rmt_src=' . urlencode($youtubeVideoRemoteSource) .
								'&amp;actual_src=' . urlencode($srcPrefix . $src) .
								'&amp;link='       . urlencode(
									strtr(base64_encode(
										preg_replace('/^(https?:)\/\//', '$1##',
											($urlComp[$src][0] .
												preg_replace($urlComp[$src][2], $urlComp[$src][3], $id) .
											$urlComp[$src][1]))), '+/', '-_'));
						$itemTotal = count($links);
						include('05_check.base.inc');
						return;
					}
					break;

				default:
					// Try next
					break;
			}
		}
	}

	// Unknown format or no 'data-data' section
	$ids = array();
	include('05_check.link.idcount.inc');
?>
