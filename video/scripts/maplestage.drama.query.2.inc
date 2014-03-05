<channel>

<?php
	echo "<title>$myBaseName: $cat</title>\r\n\r\n";

	if ($pass_check) {
		foreach($videos as $video) {
			$title = trim(str_between($video, '<h4 class="year">', '</h4>'));
			if (strlen($title) <= 0)
				break;
			$title = convertUnicodePoints($title);
			$data  = '';
			// Leave the link unchanged
			//$link  = $title;
			$image = '';
			$note  = '';
			$extra = $title;

			$pageStart = 0;
			$queryLevel = '.year';
			include('04_query.inc');
		}
	}
?>

</channel>
