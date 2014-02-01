<?php 
require($_SERVER['DOCUMENT_ROOT']."/php_includes/connect.inc");

$action = $mysqli->real_escape_string($_POST['action']); 
$updateRecordsArray = $_POST['recordsArray'];

if ($action == "updateRecordsListings"){
	
	$listingCounter = 1;
	foreach ($updateRecordsArray as $recordIDValue) {
		
		$mysqli->query("UPDATE `home_slideshow` SET `order` = '$listingCounter' WHERE `id` = '$recordIDValue'") or die('Error, insert query failed');
		$listingCounter = $listingCounter + 1;
	}
	
	echo '<pre>';
	print_r($updateRecordsArray);
	echo '</pre>';
	echo 'If you refresh the page, you will see that records will stay just as you modified.';
}
?>