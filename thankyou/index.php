<?php
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$db = new db;
	
	$getBoardQuery = $mysqli->query("SELECT * FROM `client_storyboards` ORDER BY `id` DESC");
	$board = $getBoardQuery->fetch_assoc();
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events | Thank You</title>
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
				<?php echo $base->pageHeader("Thank You","we have received your quote"); ?>
				
				<div style="position:relative; float:left; width:100%; text-align:center; color:white; font-size:36px; margin:60px 0px;">
					Thank You!<br />
					<span style="font-size:24px;">We will get back to you as soon as possible!</span>
		
			<?php if($board['cip'] == $_SERVER['REMOTE_ADDR']) { ?>
					<br /><br /><span style="font-size:24px;"><a href="http://gilly.acmediadesigns.net/storyboard/board.php?bid=<?php echo $board['board_hash']; ?>" target="_blank" style="font-size:18px; color:black; text-decoration:none;">View Your Storyboard Now!</a></span>
			<?php } ?>
		
				</div>
				
			</div>
				
			<?php echo $base->footer(); ?>

		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>