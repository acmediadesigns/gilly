<?php
	
	if(session_id() == "") session_start();
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");
	
  if(isset($_SESSION['adminID']) && isset($_POST['id']) && is_numeric($_POST['id'])) {
    $id = $_POST['id'];
    //Get image
    $query = $mysqli->query("SELECT * FROM `events_images` WHERE `id` = '$id' LIMIT 1");
    if($query->num_rows == 1) {
      $result = $query->fetch_array();
      // Remove
      $remove = $mysqli->query("DELETE FROM `events_images` WHERE `id` = '$id' LIMIT 1");
      if($remove) {
        // Delete image
        unlink($_SERVER["DOCUMENT_ROOT"].$result["image_path"]);
      }  
    }
    
    $mysqli->close();
  }