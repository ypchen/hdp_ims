<?php
	if (strlen($link) == 0) {
		$condition = '(strlen($link) == 0)' .
			' on line ' . __LINE__;

		$emailSent =
			notification_email_text(
				'IMS problem: ' . $imsDirectory . ' / ' . $myName,
				'$myScriptName = ' . $myScriptName .
					"\r\n" . '$condition = ' . $condition .
					"\r\n" . '$query = ' . $query .
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
				'; $query = ' . $query .
				($imsCheckLogHTML
					?
						"\r\n" . '$html = ' . $html .
						"\r\n" . '$htmlToExplode = ' . $htmlToExplode
					:
						'')
		);

		throw new Exception($condition);
	}
	else {
		history_ims($imsDBConn, $remoteIP, $user_id, $link, $query);
	}
?>
