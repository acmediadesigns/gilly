<?php
	
	if(session_id() == "") session_start();
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$admin = new admin;
	
	echo $admin->addPortfolio($mysqli);
  echo $admin->addEvent($mysqli);
	echo $admin->deletePortfolio($mysqli);
	echo $admin->logout($mysqli);	
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet" />
<link href="/media/style/slideshow.css" type="text/css" rel="stylesheet" />
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"></script>
<script type="text/javascript" src="/media/js/slideshow.js"></script>
<script type="text/javascript" src="/media/js/slideEasing.js"></script>
<script type="text/javascript" src="/media/js/base.js"></script>
<script type="text/javascript">$().ready(function() {$('#coda-slider-1').codaSlider();});</script>
</head>
<body>
<?php echo $base->portfolioSubNav($mysqli); ?>
<?php echo $base->eventsSubNav($mysqli); ?>
	<div align="center">
		<div class="container">

			<?php echo $base->header(); ?>
			
			<?php echo $base->slideshow($mysqli); ?>
				
			<?php echo $base->footer(); ?>
			
		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>