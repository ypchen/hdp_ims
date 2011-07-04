<?php
	if (($html === false) || (strlen($html) == 0)) {

		if ($html === false)
			$condition = '($html === false)' .
				' on line ' . __LINE__;
		else
			$condition = '(strlen($html) == 0)' .
				' on line ' . __LINE__;

		$emailSent =
			notification_email_text(
				'IMS problem: ' . $imsDirectory . ' / ' . $myName,
				'$myScriptName = ' . $myScriptName .
					"\r\n" . '$condition = ' . $condition .
					"\r\n" . '$link = ' . $link
			);

		log_page($imsDBConn, $remoteIP, $myScriptName,
			'$emailSent = ' . $emailSent .
				'; $condition = ' . $condition .
				'; $link = ' . $link
		);

		throw new Exception($condition);
	}
?>
