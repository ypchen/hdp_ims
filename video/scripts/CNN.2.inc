<item_template>
	<mediaDisplay name="threePartsView"
		showHeader="no"
		showDefaultInfo="yes"
		itemBackgroundColor="0:0:0"
		backgroundColor="0:0:0"
		sideLeftWidthPC="0"
		itemImageXPC="5"
		itemXPC="20"
		itemYPC="20"
		itemWidthPC="75"
		capWidthPC="75"
		unFocusFontColor="101:101:101"
		focusFontColor="255:255:255"
		popupXPC = "40"
		popupYPC = "55"
		popupWidthPC = "22.3"
		popupHeightPC = "5.5"
		popupFontSize = "13"
		popupBorderColor="28:35:51"
		popupForegroundColor="255:255:255"
		popupBackgroundColor="28:35:51"
		idleImageWidthPC="10"
		idleImageHeightPC="10"
	>

		<idleImage>image/<?php echo $idleImagePrefix; ?>1.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>2.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>3.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>4.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>5.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>6.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>7.png</idleImage>
		<idleImage>image/<?php echo $idleImagePrefix; ?>8.png</idleImage>

		<backgroundDisplay>
			<image offsetXPC="0" offsetYPC="0" widthPC="100" heightPC="100">
				image/mele/backgd.jpg
			</image>
		</backgroundDisplay>

		<image offsetXPC="0" offsetYPC="2.8" widthPC="100" heightPC="15.6">
			image/mele/rss_title.jpg
		</image>

		<text offsetXPC="40" offsetYPC="8"
			widthPC="35" heightPC="10"
			fontSize="20"
			backgroundColor="-1:-1:-1" foregroundColor="255:255:255">
			[確定]: 播放
		</text>

	</mediaDisplay>
</item_template>

<channel>

<?php
	echo "<title>$myBaseName: 播放項目選單</title>\r\n";

	if ($pass_check) {
		$siteURLprefix = '';
		foreach($videos as $video) {

			$link  = $siteURLprefix . trim(str_between($video, '<a href="', '"'));
			$title = trim(str_between($video, '<span class="cnnPODcasttitle">', '</span>'));
			$title = convertUnicodePoints($title);
			$extra = '';

			$image = trim(str_between($video, '<img src="', '"'));
			$data  = ' ' . trim(str_between($video, '<span class="cnnPODcastfact">', '</span>'));
			$note  = trim(str_between($video, '<br>', '</div>'));

			if($title != ''){
				echo
					"<item>\r\n" .
						"\t<title>"      . $title   . $data . "</title>\r\n" .
						"\t<link>"       . $link    . "</link>\r\n" .
						"\t<note>"       . $note    . "</note>\r\n" .
						"\t<site_link>"  . $link    . "</site_link>\r\n" .
						"\t<site_extra>" . $extra   . "</site_extra>\r\n" .
						"\t<image>"      . $image   . "</image>\r\n" .
					"</item>\r\n\r\n";
			}
		}
	}
?>

</channel>
