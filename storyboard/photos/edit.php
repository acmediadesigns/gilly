<?php
	
	if(session_id() == "") session_start();
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$db = new db;

	if(!isset($_SESSION['adminID'])) {
		header("Location: /");
		exit;
	} else {
	  $id = $_GET['id'];
  	$result = $mysqli->query("SELECT * FROM `storyboard_system_images` WHERE `id` = $id LIMIT 1");
  	$image = $result->fetch_assoc();
  	
  	if(isset($_POST['edit'])) {
    	$category = $_POST['category'];
    	$upload = $_POST['system_image'];
    	
    	$mysqli->query("UPDATE `storyboard_system_images` SET `category_id` = '$category', `user_upload` = '$upload' WHERE `id` = $id LIMIT 1");
    	header('Location: /storyboard/photos');
    	exit;
  	}
	}
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events | Edit Storyboard Photo</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet"/>
<link href="/media/style/admin.css" type="text/css" rel="stylesheet"/>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"></script>
<script type="text/javascript" src="/media/js/jscolor.js"></script>
<script type="text/javascript" src="/media/js/ajaxImg.js"></script>
<script type="text/javascript" src="/media/js/base.js"></script>
<style type="text/css">
  form {
    margin: 30px;
    padding-top: 30px;  
  }
  
  select {
    width: 400px;
  }
</style>
</head>
<body>
<?php echo $base->portfolioSubNav($mysqli); ?>
<?php echo $base->eventsSubNav($mysqli); ?>
	<div align="center">
		<div class="container">

			<?php echo $base->header(); ?>
			
			<div class="frame">
				
				<?php echo $base->pageSlide($mysqli); ?>
				<?php echo $base->pageHeader("Edit Storyboard Photo","Modify/Delete photo"); ?>
				
				<form action="" method="post">
				  <table>
				    <tr>
				      <td>Category:</td>
				      <td>System image: (If not, it is a user uploaded image)</td>
				    </tr>
				    <tr>
  				    <td>
  				      <select name="category">
  				        <option value="">Select:</option>
    				      <option value="1" <?php if($image['category_id'] == 1) echo 'selected="selected"'; ?>>Arrangements</option>
    				      <option value="2" <?php if($image['category_id'] == 2) echo 'selected="selected"'; ?>>Bridal</option>
    				      <option value="3" <?php if($image['category_id'] == 3) echo 'selected="selected"'; ?>>Events</option>
    				      <option value="4" <?php if($image['category_id'] == 4) echo 'selected="selected"'; ?>>Living</option>
  				      </select>
  				    </td>
  				    <td>
    				    <select name="system_image">
    				      <option value="1" <?php if($image['user_upload'] == 1) echo 'selected="selected"'; ?>>Yes</option>
    				      <option value="0">No</option>
  				      </select>
  				    </td>
				    </tr>
				    <tr>
				      <td align="left"><a href="delete.php?id=<?php echo $id; ?>">Delete this image?</a></td>
  				    <td align="right"><button type="submit">Update Photo</button></td>
				    </tr>
				  </table>
				  <input type="hidden" name="edit" />
				</form>
				
			</div>
				
			<?php echo $base->footer(); ?>
			
		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>