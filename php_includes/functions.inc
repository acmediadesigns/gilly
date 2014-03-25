<?php

class base {

	public function header() { ?>
		<div class="header">
			<?php 
				$adminBtn = new admin; 
				echo $adminBtn->adminBtns();
			?>
			<div class="brand">
  			<a href="/"><img src="/media/images/brand.png" alt="Gilly Flowers" /></a>
			</div>
			<ul>
				<li style="padding-left: 20px;"><a href="/about/">about</a></li>
				<li><a href="/delivery/">delivery info</a></li>
				<li><a id="portfolioNav" href="">portfolio</a></li>
				<li><a href="/quote/">get a quote</a></li>
				<li><a href="/contact/">contact</a></li>
			</ul>
		</div>
<?php	
	}
	
	public function header_org() { ?>
		<div class="header">
			<?php 
				$adminBtn = new admin; 
				echo $adminBtn->adminBtns();
			?>
			<div class="brand"></div>
			<ul>
				<li><a href="/">HOME</a></li>
				<li><a href="/about/">ABOUT</a></li>
				<li><a href="/delivery/">DELIVERY INFO</a></li>
				<li><a id="portfolioNav" href="">PORTFOLIO</a></li>
				<li><a href="/quote/">GET A QUOTE</a></li>
				<?php if(isset($_SESSION['adminID'])) { ?><li><a href="/storyboard">STORYBOARD</a></li><?php } ?>
				<li><a href="/contact/">CONTACT</a></li>
			</ul>
		</div>
<?php	
	}
	
	public function footer() { ?>
		<div class="footer">
			<div class="copyright"><?php echo date("Y"); ?> &copy; Copyright Gilly Flowers - All Rights Reserved</div>
			<div class="acmedia">Powered By: <a href="http://www.acmediadesigns.com" target="_blank">AC Media Designs</a></div>
		</div>
		
<?php
	if(isset($_SESSION['adminID'])) { ?>
		
		<div class="addPortfolioOverlay"></div>
		<div class="addPortfolioWindow">
			<form action="/" method="post" enctype="multipart/form-data">
				<table border="0">
					<tr>
						<td>Category Name:</td>
					</tr>
					<tr>
						<td><input type="text" name="addPortName" id="addPortName" /></td>
					</tr>
					<tr>
						<td>Category Thumbnail:</td>
					</tr>
					<tr>
						<td><input type="file" name="addPortThumb" id="addPortThumb" /></td>
					</tr>
					<tr>
						<td>Category Description:</td>
					</tr>
					<tr>
						<td><textarea name="addPortDesc" id="addPortDesc"></textarea></td>
					</tr>
					<tr>
						<td align="right"><button type="submit">Add</button></td>
					</tr>
				</table>
			</form>
		</div>
		
	<?php 
	} ?>
	
<?php
	}
	
	
	public function slideshow($mysqli) {
		$slideQuery = $mysqli->query("SELECT * FROM `home_slideshow` ORDER BY `order` ASC"); ?>
			<div class="slideshow" align="left">
				<div class="coda-slider-wrapper">
					<div class="coda-slider preload" id="coda-slider-1">
	<?php while($slide = $slideQuery->fetch_assoc()) { ?>
	
						<div class="panel">
							<div class="panel-wrapper">
								<img src="<?php echo $slide['image_path']; ?>" alt="" />
							</div>
						</div>
			
<?php } ?>
					</div><!-- .coda-slider -->
				</div><!-- .coda-slider-wrapper -->
				
			</div>
<?php
	}

	
	public function pageSlide($mysqli) {
		$pageImgQuery = $mysqli->query("SELECT * FROM `page_images` ORDER BY RAND() LIMIT 1");
		$pageImg = $pageImgQuery->fetch_assoc(); ?>
		<div class="pageSlide">
			<img src="<?php echo $pageImg['image_path']; ?>" alt="" />
		</div>
<?php
	}
	
	public function pageHeader($pageName,$pageSubLine=null) { ?>
		<div class="pageHeader">
			<div class="pageHeaderBG"></div>
			<h1><?php echo $pageName; ?></h1>
			<span><?php echo $pageSubLine; ?></span>
		</div>
<?php
	}
	
	private function subNavContent($mysqli,$content) { ?>
		<div align="center">
			<div class="subNavContainer">
				<div class="subNavHeader">
					<?php if($content == "portfolio") echo "<h3>Portfolio:</h3>"; else echo "<h3>Latest Events</h3>"; ?>
					<?php if($content == "portfolio") echo "<span>CHOOSE A CATEGORY TO VIEW MORE</span>"; else echo "<span>CHOOSE A EVENT TO VIEW MORE</span>"; ?>
				</div>
				
				<?php if(isset($_SESSION['adminID'])) echo '<div class="addPortfolio"><a href="">+ New Portfolio</a></div>'; ?>
				
				<div class="containSubNavThumbs">
	<?php $subNavQuery = $mysqli->query("SELECT * FROM `".$content."_categories` ORDER BY `category_name` ASC");
			if($subNavQuery->num_rows > 0) {
				while($subNav = $subNavQuery->fetch_assoc()) { ?>
					<div class="subNavThumbContainer">
						<div class="subNavThumb">
							<a href="<?php if($subNav['event'] == 0) echo "/portfolio/".$subNav['category_url']; else echo "/events/overview.php"; ?>"><img src="<?php echo $subNav['thumbnail_path']; ?>" alt="" /></a>
						</div>
						<div class="subNavThumbTitle"><?php echo $subNav['category_name']; ?></div>
					</div>
	<?php } } else echo '<div style="position:relative; float:left; width:100%; color:white; font-size:40px; text-align:center; margin:100px 0px;">No Current Categories</div>';
	$subNavQuery->close(); ?>

				</div>
				<div class="closeSubNav"></div>
				
			</div>
		</div>
	
<?php
	}
	
	public function portfolioSubNav($mysqli) { ?>
		<div class="portfolioSubContainer">
		<?php
			$base = new base;
			$base->subNavContent($mysqli,"portfolio");
		?>
		</div>
<?php
	}
	
	public function eventsSubNav($mysqli) { ?>
		<div class="eventsSubContainer">
		<?php
			$base = new base;
			$base->subNavContent($mysqli,"events");
		?>
		</div>
<?php
	}
	
	public function contactInfo() { ?>
		<div class="contactInfo">
			<table border="0" cellspacing="0">
				<tr>
					<td><div class="addressIcon"></div></td>
					<td>1631 GLENDALE BLVD<br />LOS ANGELES, CA 90026</td>
				</tr>
				<tr>
					<td><div class="phoneIcon"></div></td>
					<td>323.953.2910</td>
				</tr>
				<tr>
					<td><div class="emailIcon"></div></td>
					<td>info@gillyflowers.com</td>
				</tr>
				<tr>
					<td><div class="facebookIcon"></div></td>
					<td><a href="http://www.facebook.com/GillyFlowersAndEvents" target="_blank">GillyFlowersAndEvents</a></td>
				</tr>
				<tr>
					<td><div class="yelpIcon"></div></td>
					<td>yelp.com/gillyflowers</td>
				</tr>
				<tr>
					<td><div class="instagramIcon"></div></td>
					<td>instagram.com/gilly_flowers</td>
				</tr>
			</table>
		</div>	
<?php
	}
	
	public function contactForm() { ?>
		<div class="contactForm">
	<?php if(!isset($_POST['contactForm'])) { ?>
			<form action="" method="post">
				<table>
					<tr>
						<td>First Name:</td>
						<td>Last Name:</td>
					</tr>
					<tr>
						<td><input type="text" name="firstName" id="firstName" /></td>
						<td><input type="text" name="lastName" id="lastName" /></td>
					</tr>
					<tr>
						<td>Email Address:</td>
						<td>Phone:</td>
					</tr>
					<tr>
						<td><input type="text" name="email" id="email" /></td>
						<td><input type="text" name="phone" id="phone" /></td>
					</tr>
					<tr>
						<td colspan="2">Subject</td>
					</tr>
					<tr>
						<td colspan="2">
							<select name="subject" id="subject">
								<optgroup label="Choose Your Subject">
									<option value="">Select:</option>
									<option value="General Questions">General Questions</option>
								</optgroup>
							</select>
						</td>
					</tr>
					<tr>
						<td colspan="2">Message/Comments:</td>
					</tr>
					<tr>
						<td colspan="2"><textarea name="message" id="message"></textarea></td>
					</tr>
					<tr>
						<td align="right" colspan="2"><button type="submit" id="contactBtn">Submit</button></td>
					</tr>
				</table>
				<input type="hidden" name="contactForm" />
			</form>
	<?php } else echo '<div style="position:relative; float:left; width:100%; color:white; text-align:center; font-size:20px; margin:100px 0px;"><span style="font-size:30px;">Thank You!</span><br />We will get back to you as soon as possible.</div>'; ?>
		</div>
<?php
	}
	
	public function quoteInfo() { ?>
		<div class="quoteInfo">
			<table border="0" cellspacing="0">
				<tr>
					<td><div class="quoteStep1Icon"></div></td>
					<td>QUOTE FORM:</td>
				</tr>
				<tr>
					<td colspan="2" style="border:none; padding-top:10px;">
						Fill out our quote form to give us some basic information on your upcoming needs.
					</td>
				</tr>
				<tr>
					<td><div class="quoteStep2Icon"></div></td>
					<td>STORYBOARD:</td>
				</tr>
				<tr>
					<td colspan="2" style="border:none; padding-top:10px;">
						You will have the ability to upload your own related image or select some of our related images to give us a visual of your desired looks.
					</td>
				</tr>
			</table>
		</div>	
<?php
	}
	
	public function quoteForm() { ?>
		<div class="quoteForm">
			<form action="/storyboard/" method="post">
				<table>
					<tr>
						<td>First Name:</td>
						<td>Last Name:</td>
					</tr>
					<tr>
						<td><input type="text" name="quoteFirstName" id="quoteFirstName" /></td>
						<td><input type="text" name="quoteLastName" id="quoteLastName" /></td>
					</tr>
					<tr>
						<td>Email Address:</td>
						<td>Event Type:</td>
					</tr>
					<tr>
						<td><input type="text" name="quoteEmail" id="quoteEmail" /></td>
						<td><input type="text" name="quoteEventType" id="quoteEventType" /></td>
					</tr>
					<tr>
						<td>Event Date:</td>
						<td>Desired Location(s):</td>
					</tr>
					<tr>
						<td><input type="text" name="quoteEventDate" id="quoteEventDate" /></td>
						<td><input type="text" name="quoteDesiredLocation" id="quoteDesiredLocation" /></td>
					</tr>
					<tr>
						<td colspan="2">Phone:</td>
					</tr>
					<tr>
						<td colspan="2"><input type="text" name="quotePhone" id="quotePhone" /></td>
					</tr>
					<tr>
						<td colspan="2">Message/Comments:</td>
					</tr>
					<tr>
						<td colspan="2"><textarea name="quoteMessage" id="quoteMessage"></textarea></td>
					</tr>
					<tr>
						<td align="right" colspan="2"><button type="submit">Submit</button></td>
					</tr>
				</table>
			</form>
		</div>
<?php
	}
	

}
	
class db {

	public function aboutUs($mysqli) { ?>
		<div class="aboutUsContainer">
			<div class="aboutDivLine"></div>
		<?php
		if(!isset($_SESSION['adminID'])) {
			$aboutQuery = $mysqli->query("SELECT * FROM `about_gilly` LIMIT 1");
			if($aboutQuery->num_rows == 1) {
				$breaks = array("\r","\n","\r\n");
				$aboutGilly = $aboutQuery->fetch_assoc();
				echo str_replace($breaks,"<br />",htmlentities($aboutGilly['biography']));
			} else echo 'About Us Coming Soon.';
			$aboutQuery->close();
		} else {
			$aboutQuery = $mysqli->query("SELECT * FROM `about_gilly` LIMIT 1");
			$breaks = array("\r","\n","\r\n");
			$aboutGilly = $aboutQuery->fetch_assoc();
			echo '<form action="" method="post"><table border="0">';
			echo '<tr><td><textarea name="updateAbout" style="width:866px; height:400px; resize:vertical;">'.$aboutGilly['biography'].'</textarea><td><tr>';
			echo '<tr><td align="right"><button type="submit">Update</button></td></tr>';
			echo '</table></form>';
			$aboutQuery->close();
		}
		?>
		</div>
<?php
	}
	
	public function deliveryInfo($mysqli) { ?>
		<div class="aboutUsContainer">
			<div class="aboutDivLine"></div>
		<?php
		if(!isset($_SESSION['adminID'])) {
			$devlieryQuery = $mysqli->query("SELECT * FROM `delivery_info` LIMIT 1");
			if($devlieryQuery->num_rows == 1) {
				$breaks = array("\r","\n","\r\n");
				$deliveryInfo = $devlieryQuery->fetch_assoc();
				echo str_replace($breaks,"<br />",htmlentities($deliveryInfo['description']));
			} else echo 'Delivery Information Coming Soon.';
			$devlieryQuery->close();
		} else {
			$devlieryQuery = $mysqli->query("SELECT * FROM `delivery_info` LIMIT 1");
			$breaks = array("\r","\n","\r\n");
			$deliveryInfo = $devlieryQuery->fetch_assoc();
			echo '<form action="" method="post"><table border="0">';
			echo '<tr><td><textarea name="updateDelivery" style="width:866px; height:400px; resize:vertical;">'.$deliveryInfo['description'].'</textarea><td><tr>';
			echo '<tr><td align="right"><button type="submit">Update</button></td></tr>';
			echo '</table></form>';
			$devlieryQuery->close();
		}
		?>
		</div>
<?php
	}
	
	public function workDesc($mysqli,$type,$query,$eventID) {
		if($type == "events") {
			$catQuery = $mysqli->query("SELECT * FROM `".$type."` WHERE `category_url` = '".$query['category_url']."'");
		} else {
			$catQuery = $mysqli->query("SELECT * FROM `".$type."_categories` WHERE `category_url` = '".$query['category_url']."'");
		}
		$cat = $catQuery->fetch_assoc();
		$breaks = array("\r","\n","\r\n");
	if(!isset($_SESSION['adminID'])) { ?>
		<div class="workDesc">
			<h2><?php echo $cat['category_name']; ?></h2>
			<?php if($cat['category_description'] != "") echo str_replace($breaks,"<br />",htmlentities($cat['category_description'])); else echo 'Description Coming Soon.'; ?>
		</div>
<?php
	} else { ?>
		<div class="workDesc">
			<h2>Upload Image:</h2>
			<form action="" method="post" enctype="multipart/form-data">
				<table border="0">
					<tr>
						<td><input type="file" name="addEventImg" id="addEventImg" /></td>
					</tr>
					<tr>
						<td>
							Thumbnail Image:
							<select name="default" id="default">
								<option value="0">No</option>
								<option value="1">Yes</option>
							</select>
						</td>
					</tr>
					<tr>
						<td><button type="submit">Upload Image</td>
					</tr>
				</table>
				<input type="hidden" name="eventImgCatID" value="<?php echo $eventID; ?>" />
			</form>
			<h2><?php echo $cat['category_name']; ?></h2>
			<form action="" method="post">
				<table border="0">
					<tr>
						<td><textarea name="updateWorkDesc" style="width:230px; height:300px; resize:vertical;"><?php echo $cat['category_description']; ?></textarea></td>
					</tr>
					<tr>
						<td align="right"><button type="submit">Update</button></td>
					</tr>
				</table>
			</form>
			<a href="/?deletePort=<?php echo $cat['id']; ?>" class="deletePortfolio">Delete This Portfolio</a>
		</div>
<?php
	}
$catQuery->close();
	}
	
	public function uploadEventImg($mysqli,$eventID) {
		if(isset($_POST['eventImgCatID'])) {
			$fileName = $_FILES['addEventImg']['name'];
			$fileTmp = $_FILES['addEventImg']['tmp_name'];
			$fileSize = $_FILES['addEventImg']['size'];
			$fileExt = strtolower(substr(strrchr($fileName, '.'), 1));
			$fileHash = SHA1($fileTmp.date("mdy").RAND(1111,9999));
			$FileBase = getFilenameWithoutExt($fileName);
			$rename = rand(0000,9999).date("mdy").rand(0000,9999).".".$fileExt;
			$getEventID = makeSQLSafe($mysqli,$_POST['eventImgCatID']);
			$makeDefault = makeSQLSafe($mysqli,$_POST['default']);
			
			$acceptTypes = array("jpg","jpeg","JPG","JPEG","png","PNG","gif");
			
			if($fileSize > 0) {
				if(in_array($fileExt,$acceptTypes)) {
					move_uploaded_file($_FILES['addEventImg']['tmp_name'],$_SERVER['DOCUMENT_ROOT']."/media/images/events/".$rename);
					if($makeDefault == 1) {
						$mysqli->query("UPDATE `events` SET `thumbnail_path` = '/media/images/events/$rename' WHERE `id` = '$eventID' LIMIT 1");
					} else {
						$mysqli->query("INSERT INTO `events_images` (`event_id`,`image_path`,`order`,`timestamp`) VALUES ('$getEventID','/media/images/events/$rename',0,NOW())");
					}
					header("Location: ".$_SERVER['REQUEST_URI']);
					exit();
				}
			} else {
				header("Location: /events/".substr($_SERVER['REQUEST_URI'],8)."/?size-limit");
				exit();
			}
		}
	}
	
	public function uploadPortfolioImg($mysqli,$eventID) {

		if(isset($_POST['eventImgCatID'])) {
			$fileName = $_FILES['addEventImg']['name'];
			$fileTmp = $_FILES['addEventImg']['tmp_name'];
			$fileSize = $_FILES['addEventImg']['size'];
			$fileExt = strtolower(substr(strrchr($fileName, '.'), 1));
			$fileHash = SHA1($fileTmp.date("mdy").RAND(1111,9999));
			$FileBase = getFilenameWithoutExt($fileName);
			$rename = rand(0000,9999).date("mdy").rand(0000,9999).".".$fileExt;
			$getEventID = makeSQLSafe($mysqli,$_POST['eventImgCatID']);
			$makeDefault = makeSQLSafe($mysqli,$_POST['default']);
			
			$acceptTypes = array("jpg","jpeg","JPG","JPEG","png","PNG","gif");
			
			if($fileSize > 0) {
				if(in_array($fileExt,$acceptTypes)) {
					move_uploaded_file($_FILES['addEventImg']['tmp_name'], $_SERVER['DOCUMENT_ROOT']."/media/images/portfolio/".$rename);
					if($makeDefault == 1) {
						$mysqli->query("UPDATE `portfolio_categories` SET `thumbnail_path` = '/media/images/portfolio/$rename' WHERE `id` = '$eventID' LIMIT 1");
					} else {
						$mysqli->query("INSERT INTO `portfolio_images` (`category_id`,`image_path`,`order`,`timestamp`) VALUES ($getEventID, '/media/images/portfolio/$rename', 0, NOW())");
					}
					header("Location: ".$_SERVER['REQUEST_URI']);
					exit();
				}
			} else {
				header("Location: /portfolio/".substr($_SERVER['REQUEST_URI'],8)."/?size-limit");
				exit();
			}
		}
	}
		
	public function chooseEvent($mysqli,$cid) { ?>
		
		<div class="chooseWorkCol">
<?php $eventCatQuery = $mysqli->query("SELECT * FROM `events` WHERE `category_id` = '$cid' ORDER BY `order` ASC");
		if($eventCatQuery->num_rows > 0) {
			while($cat = $eventCatQuery->fetch_assoc()) { ?>
			<div class="chooseEventContainer">
				<div class="workThumb">
					<img src="<?php echo $cat['thumbnail_path']; ?>" alt="" />
					<a href="<?php echo '/events/'.$cat['category_url'].'/'; ?>" class="enlargePhoto"></a>
				</div>
				<a href="<?php echo '/events/'.$cat['category_url'].'/'; ?>" class="workTitle"><?php echo $cat['category_name']; ?></a>
			</div>
<?php } } else echo '<div style="position:relative; float:left; width:100%; text-align:center; color:white; font-size:26px; margin:80px 0px;">Images Coming Soon</div>'; ?>
		</div>
<?php
$eventCatQuery->close();
	}
	
	public function displayChooseEvent($mysqli) { ?>
		<div class="chooseWorkCol" style="margin-left:50px;">
<?php $eventOverview = $mysqli->query("SELECT * FROM `events` ORDER BY `order` ASC");
		if($eventOverview->num_rows > 0) { 
			while($cat = $eventOverview->fetch_assoc()) { ?>
			<div class="chooseEventContainer" style="height:180px; margin:0px 36px 30px 0px;">
				<div class="workThumb">
					<img src="<?php echo $cat['thumbnail_path']; ?>" alt="" />
					<a href="<?php echo '/events/'.$cat['category_url'].'/'; ?>" class="enlargePhoto"></a>
				</div>
				<a href="<?php echo '/events/'.$cat['category_url'].'/'; ?>" class="workTitle"><?php echo substr($cat['category_name'],0,20); ?></a>
			</div>
<?php } } else echo '<div style="position:relative; float:left; width:100%; text-align:center; color:white; font-size:26px; margin:80px 0px;">Images Coming Soon</div>'; ?>
		</div>
<?php
$eventOverview->close();
		
	}
	
	
	public function displayWorkColumn($mysqli,$type,$query) { ?>
		
		<div class="displayWorkCol">
<?php $imgQuery = $mysqli->query("SELECT * FROM `".$type."_images` WHERE `category_id` = '".$query['id']."'");
		if($imgQuery->num_rows > 0) {
			while($img = $imgQuery->fetch_assoc()) { ?>
			<div class="workThumb" id="portImg<?php echo $img["id"]; ?>">
				<img src="<?php echo $img['image_path']; ?>" alt="" />
				<?php if(!isset($_SESSION['adminID'])) { ?>
				<a href="<?php echo $img['image_path']; ?>" rel="shadowbox[event]" class="enlargePhoto"></a>
				<?php } ?>
				
				<?php if(isset($_SESSION['adminID'])) { ?>
  		    <div onclick="return removePortfolioImage(<?php echo $img['id']; ?>); return false;" style="position: absolute; top: 0px; right: 6px; color: #FFF; text-decoration: none; cursor: pointer; text-transform: uppercase;">Delete</div>
        <?php } ?>
			</div>
<?php } $imgQuery->close(); } else echo '<div style="position:relative; float:left; width:100%; text-align:center; color:white; font-size:26px; margin:80px 0px;">Images Coming Soon</div>'; ?>
		</div>
<?php
	}
	
	public function displayEventColumn($mysqli,$eventID) { ?>
		
		<div class="displayWorkCol">
<?php $eventImgQuery = $mysqli->query("SELECT * FROM `events_images` WHERE `event_id` = '$eventID' ORDER BY `order` ASC");
		if($eventImgQuery->num_rows > 0) {
			while($eventImg = $eventImgQuery->fetch_assoc()) { ?>
			<div class="workThumb"  id="eventImg<?php echo $eventImg["id"]; ?>">
				<img src="<?php echo $eventImg['image_path']; ?>" alt="" />
				<?php if(!isset($_SESSION['adminID'])) { ?>
				<a href="<?php echo $eventImg['image_path']; ?>" rel="shadowbox[event]" class="enlargePhoto"></a>
				<?php } ?>
				
				<?php if(isset($_SESSION['adminID'])) { ?>
  		    <a href="" onclick="removeEventImage(<?php echo $eventImg['id']; ?>); return false;" style="position: absolute; top: 0px; right: 6px; color: #FFF; text-decoration: none; text-transform: uppercase;">Delete</a>
        <?php } ?>
			</div>
<?php } $eventImgQuery->close(); } else echo '<div style="position:relative; float:left; width:100%; text-align:center; color:white; font-size:26px; margin:80px 0px;">Images Coming Soon</div>'; ?>
		</div>
<?php
	}
	
	
	public function storyImageCol($mysqli) { ?>
		<div class="storyImageCol">
			<h1>Upload Your Images:</h1>
			<form id="imageform" method="post" enctype="multipart/form-data" action="uploadImg.php">
				<table border="0" cellspacing="0">
					<tr>
						<td>Image File:</td>
					</tr>
					<tr>
						<td><input type="file" name="userImg" id="userImg" /></td>
					</tr>
					<tr>
						<td align="right"><button type="submit" id="uploadImg">Upload</button></td>
					</tr>
				</table>
				<input type="hidden" name="quoteData" value="<?php echo implode(",",$_POST); ?>" />
			</form>
			
			<div class="clearBoard">Clear Storyboard</div>
			
			<?php if(isset($_SESSION['adminID'])) { ?>
			  <a href="/storyboard/photos">Edit Storyboard Images</a>
			<?php } ?>
		</div>
<?php
	}
	
	public function storyBoardCol($postArray) { ?>
		<div class="storyBoardCol">
			<form id="storyBoardData" action="" method="post">
				<div class="learnBoardBtn"></div>
				<div class="storyChangeBG">
					<div class="currentBoardBG">
						<input class="color" name="boardBGColor" value="FFFFFF" />
					</div>
					<div class="currentBoardBGText">Change Storyboard BG Color:</div>
				</div>
				<div class="storyBoardContainer" id="storyBoardContainer">
					<ul></ul>
					<div class="storyBoardLearnPopUp">
						<div class="storyBoardLearnBG"></div>
						<div class="storyBoardLearnDesc"></div>
					</div>
				</div>
				<div class="storyBoardButtons">
					<input type="hidden" name="quoteData" value="<?php echo $postArray; ?>" />
					<input type="hidden" name="boardData" id="boardData" />
					<button type="submit">Skip Storyboard</button>
					<button type="submit" id="submitStoryBoard">Submit Storyboard</button>
				</div>
			</form>
		</div>
<?php
	}
	
	
	public function viewStoryBoard($mysqli,$boardHash) {
		$clientBoardQuery = $mysqli->query("SELECT * FROM `client_storyboards` WHERE `board_hash` = '$boardHash'");
		if($clientBoardQuery->num_rows == 1) {
			$clientBoard = $clientBoardQuery->fetch_assoc();
		} ?>
		<div class="storyBoardContainer" id="storyBoardContainer" style="background:#<?php echo $clientBoard['bg_color']; ?>; width:646px; margin:40px 0px 0px 150px;">
			<ul>
				<?php echo $clientBoard['storyboard_data']; ?>
			</ul>
		</div>
<?php
	}
	
	
	public function sendQuoteEmail($mysqli, $to, $quoteData) {
		if(isset($_POST['quoteData'])) {
			$quoteArray = explode("|",addslashes($quoteData));
			$boardData = makeSQLSafe($mysqli,$_POST['boardData']);
			$boardBGColor = makeSQLSafe($mysqli,$_POST['boardBGColor']);
			
			$firstName = $quoteArray[1];
			$lastName = $quoteArray[2];
			$emailAddress = $quoteArray[3];
			$eventType = $quoteArray[4];
			$eventDate = $quoteArray[5];
			$eventLocation = $quoteArray[6];
			$phone = $quoteArray[7];
			$comments = $quoteArray[8];
			$subject = "Online Quote";
			
			$message = "First Name: $firstName<br>";
			$message .= "Last Name: $lastName<br>";
			$message .= "Email Address: $emailAddress<br>";
			$message .= "Event Type: $eventType<br>";
			$message .= "Event Date: $eventDate<br>";
			$message .= "Event Location: $eventLocation<br>";
			$message .= "Phone: $phone<br>";
			$message .= "Message/Comments:\n$comments<br>";
			
			//ADD BOARD TO DATABASE
			if(!empty($boardData)) {
				$hash = SHA1(date("mdy").$_SERVER['REMOTE_ADDR'].rand(0000,9999).rand(0000,9999));
				$mysqli->query("INSERT INTO `client_storyboards` (`storyboard_data`,`bg_color`,`cip`,`board_hash`,`timestamp`) VALUES ('$boardData','$boardBGColor','".$_SERVER['REMOTE_ADDR']."','$hash',NOW())");
				
				$getLatestBoardQuery = $mysqli->query("SELECT * FROM `client_storyboards` ORDER BY `id` DESC");
				$latestboard = $getLatestBoardQuery->fetch_assoc();
				
				$message .= "<br><br><a href=\"http://gilly.acmediadesigns.net/storyboard/board.php?bid=".$latestboard['board_hash']."\" target=\"_blank\">Click Here To See The StoryBoard</a><br>";	
			}
			
			$headers = 'From: Gilly Flowers'."\r\n";
			$headers .= "Reply-To: sales@gillyflowers.com\r\n";
			$headers .= "Content-Type: text/html; charset=ISO-8859-1\r\n";
			
			mail($to,$subject,$message,$headers);
			
			header("Location: /thankyou/");
			exit();
		}
	}
	
	
	public function sendContactEmail($mysqli,$to) {
		if(!empty($_POST)) {
			$firstName = makeSQLSafe($mysqli,$_POST['firstName']);
			$lastName = makeSQLSafe($mysqli,$_POST['lastName']);
			$emailAddress = makeSQLSafe($mysqli,$_POST['email']);
			$phone = makeSQLSafe($mysqli,$_POST['phone']);
			$subject = makeSQLSafe($mysqli,$_POST['subject']);
			$comments = makeSQLSafe($mysqli,$_POST['message']);
			
			$message = "First Name: $firstName\n";
			$message .= "Last Name: $lastName\n";
			$message .= "Email Address: $emailAddress\n";
			$message .= "Phone: $phone\n";
			$message .= "Message/Comments:\n$comments\n";
			
			$headers = 'From: Gilly Flowers'."\r\n";
			
			mail($to,$subject,$message,$headers);
		}
	}
	
	
	
}

class admin {
	
	public function login($mysqli) {
		if(isset($_POST['login'])) {
			$username = makeSQLSafe($mysqli,$_POST['username']);
			$password = makeSQLSafe($mysqli,SHA1($_POST['password']));
			$adminQuery = $mysqli->query("SELECT * FROM `admin` WHERE `username` = '$username' AND `password` = '$password'");
			if($adminQuery->num_rows == 1) {
				$admin = $adminQuery->fetch_assoc();
				$_SESSION['adminID'] = $admin['id'];
				header("Location: /");
				exit;
			}
			$adminQuery->close();
		}
	}
	
	public function logout($mysqli) {
		if(isset($_GET['logout'])) {
			session_destroy();
			$mysqli->close();
			header("Location: /");
			exit;
		}
	}
	
	public function adminBtns() {
		if(isset($_SESSION['adminID'])) {
			echo '<div style="position:absolute; top:6px; right:6px; z-index:9;">';
			echo '<a href="/slideshow/" style="color:color; text-decoration:none; padding-right: 10px;">Slideshow</a>';
			echo '<a href="/admin/slideshow.php" style="color:color; text-decoration:none; padding-right: 10px;">Edit Slideshow</a>';
			echo '<a href="/admin/page-images.php" style="color:color; text-decoration:none; padding-right: 10px;">Edit Page Images</a>';
			echo '<a href="/?logout" style="color:color; text-decoration:none;">Logout</a>';
			echo '</div>';
		}
	}
	
	public function updateAboutUs($mysqli) {
		if(isset($_POST['updateAbout']) && !empty($_POST['updateAbout'])) {
			$updateAbout = makeSQLSafe($mysqli,$_POST['updateAbout']);
			$mysqli->query("UPDATE `about_gilly` SET `biography` = '$updateAbout' LIMIT 1");
			header("Location: /about/");
			exit;
		}
	}
	
	public function updateDelivery($mysqli) {
		if(isset($_POST['updateDelivery']) && !empty($_POST['updateDelivery'])) {
			$updateDelivery = makeSQLSafe($mysqli,$_POST['updateDelivery']);
			$mysqli->query("UPDATE `delivery_info` SET `description` = '$updateDelivery' LIMIT 1");
			header("Location: /delivery/");
			exit;
		}
	}
	
	public function updateWorkDesc($mysqli,$url) {
		if(isset($_POST['updateWorkDesc']) && !empty($_POST['updateWorkDesc'])) {
			$updateWorkDesc = makeSQLSafe($mysqli,$_POST['updateWorkDesc']);
			$mysqli->query("UPDATE `portfolio_categories` SET `category_description` = '$updateWorkDesc' WHERE `category_url` = '$url' LIMIT 1");
			header("Location: /portfolio/".$url."/");
			exit;
		}
	}
	
	public function addPortfolio($mysqli) {
		if(isset($_POST['addPortName'])) {
			
			$addPortName = makeSQLSafe($mysqli,$_POST['addPortName']);
			$addPortDesc = makeSQLSafe($mysqli,$_POST['addPortDesc']);
			$addPortFileName = $_FILES['addPortThumb']['name'];
			$addPortTmp = $_FILES['addPortThumb']['tmp_name'];
			$addPortSize = $_FILES['addPortThumb']['size'];
			$fileExt = str_replace(".","",strrchr($addPortFileName,"."));
			$hashName = SHA1(RAND(0000,9999).date("Ymd").RAND(0000,9999).$addPortFileName).".".$fileExt;
			
			$urlReplace = array(" ","  ");
			$addPortURL = str_replace($urlReplace,"-",strtolower($addPortName));

			move_uploaded_file($_FILES['addPortThumb']['tmp_name'], $_SERVER['DOCUMENT_ROOT']."/media/images/portfolio/".$hashName);
			
			$mysqli->query("INSERT INTO `portfolio_categories` (`category_name`,`thumbnail_path`,`category_url`,`category_description`,`datetime`) VALUES ('$addPortName','/media/images/portfolio/$hashName','$addPortURL','$addPortDesc',NOW())");
			header("Location: /portfolio/".$addPortURL);
			exit();
		}
	
	}
	
	public function deletePortfolio($mysqli) {
		if(isset($_GET['deletePort']) && is_numeric($_GET['deletePort'])) {
			$deleteID = makeSQLSafe($mysqli,$_GET['deletePort']);
			$mysqli->query("DELETE FROM `portfolio_categories` WHERE `id` = '$deleteID' LIMIT 1");
			header("Location: /");
			exit();
		}
	}
	
	public function uploadSlideImg($mysqli) {

		if(isset($_POST['uploadSlide'])) {
			$fileName = $_FILES['newSlideImg']['name'];
			$fileTmp = $_FILES['newSlideImg']['tmp_name'];
			$fileSize = $_FILES['newSlideImg']['size'];
			$fileExt = strtolower(substr(strrchr($fileName, '.'), 1));
			$fileHash = SHA1($fileTmp.date("mdy").RAND(1111,9999));
			$FileBase = getFilenameWithoutExt($fileName);
			$rename = rand(0000,9999).date("mdy").rand(0000,9999).".".$fileExt;
			
			$acceptTypes = array("jpg","jpeg","JPG","JPEG","png","PNG","gif");
			
			if($fileSize > 0) {
				if(in_array($fileExt, $acceptTypes)) {
					move_uploaded_file($_FILES['newSlideImg']['tmp_name'], $_SERVER['DOCUMENT_ROOT']."/media/images/slideshow/".$rename);
					$mysqli->query("INSERT INTO `home_slideshow` (`image_path`,`order`,`timestamp`) VALUES ('/media/images/slideshow/$rename', 0, NOW())");
					header("Location: /admin/slideshow.php");
					exit();
				}
			} else {
				header("Location: /admin/slideshow.php?invalid_size");
				exit();
			}			
		}
	}
	
	public function uploadPageImg($mysqli) {

		if(isset($_POST['uploadPageImg'])) {
			$fileName = $_FILES['newPageImg']['name'];
			$fileTmp = $_FILES['newPageImg']['tmp_name'];
			$fileSize = $_FILES['newPageImg']['size'];
			$fileExt = strtolower(substr(strrchr($fileName, '.'), 1));
			$fileHash = SHA1($fileTmp.date("mdy").RAND(1111,9999));
			$FileBase = getFilenameWithoutExt($fileName);
			$rename = rand(0000,9999).date("mdy").rand(0000,9999).".".$fileExt;
			
			$acceptTypes = array("jpg","jpeg","JPG","JPEG","png","PNG","gif");
			
			if($fileSize > 0) {
				if(in_array($fileExt, $acceptTypes)) {
					move_uploaded_file($_FILES['newPageImg']['tmp_name'], $_SERVER['DOCUMENT_ROOT']."/media/images/page_images/".$rename);
					$mysqli->query("INSERT INTO `page_images` (`image_path`,`timestamp`) VALUES ('/media/images/page_images/$rename', NOW())");
					header("Location: /admin/page-images.php");
					exit();
				}
			} else {
				header("Location: /admin/page-images.php?invalid_size");
				exit();
			}			
		}
	}
}

	function makeSQLSafe($mysqli,$string) {
		$string = trim($string);
		while(strpos($string,"  ") !== false) {
			$string = str_replace("  "," ",$string);
		}
		if (get_magic_quotes_gpc()) $string = stripslashes($string);
		return $mysqli->real_escape_string($string);
	}
	
	function getFilenameWithoutExt($filename) {
		$pos = strripos($filename, '.');
		if($pos === false){
			return $filename;
		} else {
			return substr($filename, 0, $pos);
		}
	}

?>