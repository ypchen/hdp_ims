<?php
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$link = trim(str_between($html, '"config", "', '"'));
	if (strlen($link) > 0) {
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, '<file>', '</file>'));
	}
	else {
		$link = 'http://xxxstash.com/videoConfigJSCode.php' .
			trim(str_between($html, "<script type='text/javascript' src='/videoConfigJSCode.php", "'></script>"));
		$html = yp_file_get_contents($link);
		include('05_check.file_contents.inc');

		$link = trim(str_between($html, 'file: "', '"'));
	}
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
