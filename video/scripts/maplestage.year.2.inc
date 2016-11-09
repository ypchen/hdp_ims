<channel>

<?php
	echo "<title>$myBaseName: 項目選單</title>\r\n\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach ($videos as $year=>$count) {
			$title  = convertUnicodePoints($year);
			$data   = '';
			if (is_int($year))
				$link   = base64_encode(base64_decode($search) . ',"year":' . intval($year));
			else
				$link   = $search;
			$image  = '';
			$note   = $count . ' 個項目';
			$extra  = '';

			$pageStart = 0;
			include('04_query.inc');
		}
	}
?>

</channel>
