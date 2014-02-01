<?php
	
	if(session_id() == "") session_start();
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$db = new db;

	if(!empty($_POST) || isset($_SESSION['adminID'])) {
		$quoteArray = implode("|",$_POST);
	} else {
		header("Location: /quote/");
		exit();
	}
	
	echo $db->sendQuoteEmail($mysqli,"allan@acmediadesigns.com",$quoteArray);
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events | Create Your Storyboard</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet"/>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"></script>
<script type="text/javascript" src="/media/js/jscolor.js"></script>
<script type="text/javascript" src="/media/js/ajaxImg.js"></script>
<script type="text/javascript" src="/media/js/base.js"></script>
<script type="text/javascript">
	var quoteData = '<?php echo addslashes($quoteArray); ?>';
	
	$('#uploadImg').live('click', function() { 
		//$("#preview").html('<img src="loader.gif" alt="Uploading...."/>');
		$("#imageform").ajaxForm({
			target: 'div.storyBoardContainer ul'
			//$('div.storyBoardContainer ul').prepend(target);
		}).submit();
			
	});
	
</script>
</head>
<body>
<?php echo $base->portfolioSubNav($mysqli); ?>
<?php echo $base->eventsSubNav($mysqli); ?>
	<div align="center">
		<div class="container">

			<?php echo $base->header(); ?>
			
			<div class="frame">
				
				<?php echo $base->pageSlide($mysqli); ?>
				<?php echo $base->pageHeader("Create a Storyboard","Show Us What You Desire Visually"); ?>
				<?php echo $db->storyImageCol($mysqli); ?>
				<?php echo $db->storyBoardCol($quoteArray); ?>
				
			</div>
				
			<?php echo $base->footer(); ?>
			
		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>