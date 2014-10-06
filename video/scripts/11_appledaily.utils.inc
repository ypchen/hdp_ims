<?php
	function urlFromChangeMenu($funCall, $page, $strApp) {
		// function changeMenu(count,ParKey,type,page,SubKey,FID,IssueID)
		//                     [0]   [1]    [2]  [3]  [4]    [5] [6]
		// '/animation/getsectionajax/ParKeyword/'+ParKey+'/Type/'+type+'/mPos/'+count+'/Page/'+page+'/SubKeyword/'+SubKey+'/FileID/'+FID+'/IssueID/'+IssueID+'/201410061030',
		$args = extractArguments($funCall);

		if ($page == 0) $page = intval($args[3]);
		$url = 'http://www.appledaily.com.tw' .
				'/animation/getsectionajax' .
				'/ParKeyword/' .	$args[1] .
				'/Type/' . 			$args[2] .
				'/mPos/' .			$args[0] .
				'/Page/' .			$page .
				'/SubKeyword/' .	$args[4] .
				'/FileID/' .		$args[5] .
				'/IssueID/' .		$args[6] .
				'/' . $strApp;

		return ($url);
	}

	function urlFromChangeRnews($funCall, $page, $strApp) {
		// function changeRnews(count,file,page)
		//                      [0]   [1]  [2]
		// '/animation/getrnewsajax/mPos/'+count+'/File/'+file+'/Page/'+page+'/201410061030',
		$args = extractArguments($funCall);

		if ($page == 0) $page = intval($args[2]);
		$url = 'http://www.appledaily.com.tw' .
				'/animation/getrnewsajax' .
				'/mPos/' .			$args[0] .
				'/File/' .			$args[1] .
				'/Page/' .			$page .
				'/' . $strApp;

		return ($url);
	}
?>
