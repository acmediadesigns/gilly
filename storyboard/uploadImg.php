<?php

	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	$path = $_SERVER['DOCUMENT_ROOT']."/media/images/storyboard_user_images/";

	$valid_formats = array("jpg", "png", "gif", "bmp");
	if(isset($_POST) and $_SERVER['REQUEST_METHOD'] == "POST") {
		$name = $_FILES['userImg']['name'];
		$size = $_FILES['userImg']['size'];
			
		if(strlen($name)) {
			list($txt, $ext) = explode(".", $name);
			if(in_array($ext,$valid_formats)) {
				if($size<(1024*1024)) {
					$actual_image_name = time().substr(str_replace(" ", "_", $txt), 5).".".$ext;
					$tmp = $_FILES['userImg']['tmp_name'];
					if(move_uploaded_file($tmp, $path.$actual_image_name)) {
						$mysqli->query("INSERT INTO `storyboard_system_images` (`image_path`,`user_upload`,`remote_addr`,`timestamp`) VALUES ('/media/images/storyboard_user_images/".$actual_image_name."',1,'".$_SERVER['REMOTE_ADDR']."',NOW())");
						$lastID = $mysqli->insert_id;
						echo '<li id="boardorder_'.$lastID.'"><img src="/media/images/storyboard_user_images/'.$actual_image_name.'" alt="" /></li>';
					} //else echo "failed";
				} //else echo "Image file size max 1 MB";		
			} //else echo "Invalid file format..";
		} //else echo "Please select image..!"; exit;
	}
	
?>