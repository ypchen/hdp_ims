<?php
	if (count($ids) == 0) {
		$condition = '(count($ids) == 0)' .
			' on line ' . __LINE__;

		$emailSent =
			notification_email_text(
				'IMS problem: ' . $imsDirectory . ' / ' . $myName,
				'$myScriptName = ' . $myScriptName .
					"\r\n" . '$condition = ' . $condition .
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
		history_ims($imsDBConn, $remoteIP, $user_id,
			strval(count($ids)) . ' youtube ids: ' . implode(',', $ids),
			$query);
	}
?>
