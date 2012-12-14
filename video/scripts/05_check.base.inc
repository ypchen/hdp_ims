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
					($imsCheckSendHTML
						?
							"\r\n" . '$html = ' . $html .
							"\r\n" . '$htmlToExplode = ' . $htmlToExplode
						:
							'')
			);

		log_page($imsDBConn, $remoteIP, $myScriptName,
			'$emailSent = ' . $emailSent .
				'; $condition = ' . $condition .
				'; $link = ' . $link .
				($imsCheckLogHTML
					?
						"\r\n" . '$html = ' . $html .
						"\r\n" . '$htmlToExplode = ' . $htmlToExplode
					:
						'')
		);

		throw new Exception($condition);
	}
?>
