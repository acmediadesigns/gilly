<?php
	
	if(session_id() == "") session_start();
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$db = new db;
	$admin = new admin;
	
	if(isset($_GET['e']) && $_GET['e'] != "") {
		$e = makeSQLSafe($mysqli,$_GET['e']);
		$eventQuery = $mysqli->query("SELECT * FROM `portfolio_categories` WHERE `category_url` = '$e'");
		if($eventQuery->num_rows == 1) {
			$event = $eventQuery->fetch_assoc();
			$eventTitle = $event['category_name'];
		} else {
			header("Location: /");
			exit();
		}
	} else {
		header("Location: /");
		exit();
	}
	
	echo $db->uploadPortfolioImg($mysqli, $event['id']);	
	
	echo $admin->updateWorkDesc($mysqli,$e);
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events | Portfolio</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet"/>
<link href="/media/style/shadowbox.css" type="text/css" rel="stylesheet"/>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"></script>
<script type="text/javascript" src="/media/js/base.js"></script>
<?php if(isset($_SESSION['adminID'])) { ?>
<script type="text/javascript" src="/media/js/admin.js"></script>
<?php } ?>
<script type="text/javascript" src="/media/js/shadowbox.js"></script>
<script type="text/javascript">Shadowbox.init();</script>
</head>
<body>
<?php echo $base->portfolioSubNav($mysqli); ?>
<?php echo $base->eventsSubNav($mysqli); ?>
	<div align="center">
		<div class="container">

			<?php echo $base->header(); ?>
				
			<div class="frame">
				
				<?php echo $base->pageSlide($mysqli); ?>
				<?php echo $base->pageHeader($eventTitle,"View Our Current Portfolio"); ?>
				<?php echo $db->workDesc($mysqli,"portfolio",$event,$event['id']); ?>
				<?php echo $db->displayWorkColumn($mysqli,"portfolio",$event); ?>
				
			</div>
				
			<?php echo $base->footer(); ?>
			
		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>