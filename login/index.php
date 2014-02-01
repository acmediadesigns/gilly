<?php
	
	if(session_id() == "") session_start();
	
	if(isset($_SESSION['adminID'])) {
		header("Location: /");
		exit;
	}
	
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");
	require($_SERVER['DOCUMENT_ROOT']."/php_includes/functions.inc");

	$base = new base;
	$admin = new admin;
	
	echo $admin->login($mysqli);
	
	//$pass = SHA1("gilly2012");
	//$mysqli->query("INSERT INTO `admin` (`username`,`password`,`timestamp`) VALUES ('admin','$pass',NOW())");
	
?>
<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html>
<head>
<title>Gilly Flowers &amp Events | Administration</title>
<link href="/media/style/default.css" type="text/css" rel="stylesheet" />
<link href="/media/style/slideshow.css" type="text/css" rel="stylesheet" />
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/1.7.2/jquery.min.js"></script>
<script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jqueryui/1.8.18/jquery-ui.min.js"></script>
<script type="text/javascript" src="/media/js/slideshow.js"></script>
<script type="text/javascript" src="/media/js/slideEasing.js"></script>
<script type="text/javascript" src="/media/js/base.js"></script>
</head>
<body>

	<div align="center">
		<div class="container">

			<div class="adminLoginContainer">
				<form action="" method="post">
					<table border="0">
						<tr>
							<td>Username:</td>
						</tr>
						<tr>
							<td><input type="text" name="username" id="username" /></td>
						</tr>
						<tr>
							<td>Password:</td>
						</tr>
						<tr>
							<td><input type="password" name="password" id="password" /></td>
						</tr>
						<tr>
							<td align="right"><button type="submit">Login</button></td>
						</tr>
					</table>
					<input type="hidden" name="login" />
				</form>
			</div>	
			
		</div>	
	</div>
	
</body>
</html>
<?php $mysqli->close(); ?>