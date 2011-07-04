<channel>

<?php
	switch ($history) {
		case 1:
			echo "<title>最近瀏覽</title>\r\n";
		break;
		case 2:
			echo "<title>最近觀看</title>\r\n";
		break;
		case 3:
			echo "<title>本地收藏</title>\r\n";
		break;
	}
?>

<itemSize>
	<script>
		itemSize;
	</script>
</itemSize>

</channel>
