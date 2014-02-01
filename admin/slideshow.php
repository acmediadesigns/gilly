<?php
	
	if(session_id() == "") session_start();
	
	if(!isset($_SESSION['adminID'])) {
		header("Location: /");
		exit;
	}
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$admin = new admin;

	echo $admin->logout($mysqli);
	
	// Delete slide
	if(isset($_GET['delete']) && is_numeric($_GET['delete'])) {
		$id = $_GET['delete'];
		$mysqli->query("DELETE FROM `home_slideshow` WHERE `id` = '$id' LIMIT 1");
		header('Location: /admin/slideshow.php');
		exit;
	}
	
	// Upload new slide images
	$admin->uploadSlideImg($mysqli);
	
	$slideQuery = $mysqli->query("SELECT * FROM `home_slideshow` ORDER BY `order` ASC");
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet" />
<link href="/media/style/slideshow.css" type="text/css" rel="stylesheet" />
<link href="/media/style/admin.css" type="text/css" rel="stylesheet" />
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"></script>
<script type="text/javascript" src="/media/js/slideshow.js"></script>
<script type="text/javascript" src="/media/js/slideEasing.js"></script>
<script type="text/javascript" src="/media/js/base.js"></script>
<script type="text/javascript" src="/media/js/admin.js"></script>
</head>
<body onload="return sortSlideImages();">
<?php echo $base->portfolioSubNav($mysqli); ?>
<?php echo $base->eventsSubNav($mysqli); ?>
	<div align="center">
		<div class="container">

			<?php echo $base->header(); ?>
			
			<div style="float: right; width: 600px;">
			
				<div class="uploadNewSlide">
					<h3>Upload New Slide</h3>
					<form action="" method="post" enctype="multipart/form-data">
						<input type="file" name="newSlideImg" />
						<input type="hidden" name="uploadSlide" />
						<button type="submit">Upload</button>
					</form>
				</div>
				
				<ul class="adminSlides">
		<?php while($slide = $slideQuery->fetch_array()) { ?>
					<li id="recordsArray_<?php echo $slide['id']; ?>">
						<div>
							<img src="<?php echo $slide['image_path']; ?>" alt="" />
						</div>
						<a href="?delete=<?php echo $slide['id']; ?>" class="deleteSlide">Delete Slide</a>
					</li>
		<?php } ?>					
				</ul>
			</div>
			
		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>