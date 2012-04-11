<?php
	function urlFromChangeMenu($funCall, $page) {
		// function changeMenu(count,ParKey,type,page,SubKey,FID,IssueID)
		//                     [0]   [1]    [2]  [3]  [4]    [5] [6]
		// '/animation/getsectionajax/ParKeyword/'+ParKey+'/Type/'+type+'/mPos/'+count+'/Page/'+page+'/SubKeyword/'+SubKey+'/FileID/'+FID+'/IssueID/'+IssueID+'/'+Math.random()
		$args = extractArguments($funCall);

		if ($page == 0) $page = $args[3];
		$url = 'http://www.appledaily.com.tw' .
				'/animation/getsectionajax' .
				'/ParKeyword/' .	$args[1] .
				'/Type/' . 			$args[2] .
				'/mPos/' .			$args[0] .
				'/Page/' .			$page .
				'/SubKeyword/' .	$args[4] .
				'/FileID/' .		$args[5] .
				'/IssueID/' .		$args[6] .
				'/' . + strval(rand(0, 9.9));

		return ($url);
	}

	function urlFromChangeData($funCall, $page) {
		// function changeData(mPos,ParKey,type,SubKey,FileID,page,IssueID)
		//                     [0]  [1]    [2]  [3]    [4]    [5]  [6]
		// "/animation/getsectionajax/ParKeyword/"+ParKey+"/Type/"+type+"/mPos/"+mPos+"/SubKeyword/"+SubKey+"/FileID/"+FileID+"/Page/"+page+"/IssueID/"+IssueID+"/"+Math.random()
		$args = extractArguments($funCall);

		if ($page == 0) $page = $args[5];
		$url = 'http://www.appledaily.com.tw' .
				'/animation/getsectionajax' .
				'/ParKeyword/' .	$args[1] .
				'/Type/' . 			$args[2] .
				'/mPos/' .			$args[0] .
				'/SubKeyword/' .	$args[3] .
				'/FileID/' .		$args[4] .
				'/Page/' .			$page .
				'/IssueID/' .		$args[6] .
				'/' . + strval(rand(0, 9.9));

		return ($url);
	}
?>
