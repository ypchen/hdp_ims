<channel>

<?php
	echo "<title>$myBaseName: 偶像戲劇</title>\r\n\r\n";

	if ($pass_check) {
		foreach($videos as $video) {
			$title = trim(str_between($video, '">', '</h2>'));
			$title = convertUnicodePoints($title);
			$data  = '';
			$link  = $title;
			$image = '';
			$note  = '';
			$extra = '';

			$pageStart = 0;
			$queryLevel = '.year';
			include('04_query.inc');
		}
	}
?>

</channel>
