<?php
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$db = new db;

	if(isset($_GET['bid'])) {
		$bid = makeSQLSafe($mysqli,$_GET['bid']);		
	} else {
		header("Location: /quote/");
		exit();
	}

?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events | Your Storyboard</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet"/>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<style type="text/css">
body {background:white;}
</style>
</head>
<body>
	<div align="center">
		<div class="container">
			
			<?php echo $db->viewStoryBoard($mysqli,$bid); ?>
			
		</div>
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>