<?php
	
	if(session_id() == "") session_start();
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$db = new db;

	if(isset($_SESSION['adminID'])) {
	  $id = $_GET['id'];
  	$result = $mysqli->query("SELECT * FROM `storyboard_system_images` WHERE `id` = $id LIMIT 1");
  	$image = $result->fetch_assoc();
  	$mysqli->query("DELETE FROM `storyboard_system_images` WHERE `id` = $id LIMIT 1");
    // Delete image file
  	unlink($_SERVER['DOCUMENT_ROOT'] . $image['image_path']);
  }
  
  header('Location: /storyboard/photos');
  exit;
	
	$mysqli->close();
?>