<?php
	if ($itemTotal == 0) {
		$condition = '($itemTotal == 0)' .
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
