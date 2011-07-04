<?php
	$link = 'http://www.tjoob.com/emb.php?id=' . $link;
	$html = yp_file_get_contents($link);
	include('05_check.file_contents.inc');

	$h1 = str_between($html, "config.stream{", "}");
	$url = trim(str_between($h1, "URL:", ";"));
	$filekey = trim(str_between($h1, "fileKey:", ";"));
	$h2 = str_between($html, "config.content{", "}");
	$video = trim(str_between($h2, "video:", ";"));
	$link = $url . $filekey . $video;
	include('05_check.link.inc');

	include('07_make.link.inc');
?>
