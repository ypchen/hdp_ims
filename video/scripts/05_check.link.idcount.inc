<?php
	if (count($ids) == 0) {
		$condition = '(count($ids) == 0)' .
			' on line ' . __LINE__;

		$emailSent =
			notification_email_text(
				'IMS problem: ' . $imsDirectory . ' / ' . $myName,
				'$myScriptName = ' . $myScriptName .
					"\r\n" . '$condition = ' . $condition
			);

		log_page($imsDBConn, $remoteIP, $myScriptName,
			'$emailSent = ' . $emailSent .
			'; $condition = ' . $condition
		);

		throw new Exception($condition);
	}
	else {
		history_ims($imsDBConn, $remoteIP, $user_id,
			strval(count($ids)) . ' youtube ids: ' . implode(',', $ids),
			$query);
	}
?>
