<?php
	if ($itemTotal == 0) {
		$condition = '($itemTotal == 0)' .
			' on line ' . __LINE__;

		$emailSent =
			notification_email_text(
				'IMS problem: ' . $imsDirectory . ' / ' . $myName,
				'$myScriptName = ' . $myScriptName .
					"\r\n" . '$condition = ' . $condition .
					"\r\n" . '$link = ' . $link .
					($imsCheckBaseSendHtml ? "\r\n" . '$html = ' . $html : '')
			);

		log_page($imsDBConn, $remoteIP, $myScriptName,
			'$emailSent = ' . $emailSent .
				'; $condition = ' . $condition .
				'; $link = ' . $link .
				($imsCheckBaseSendHtml ? "\r\n" . '; $html = ' . $html : '')
		);

		throw new Exception($condition);
	}
?>
