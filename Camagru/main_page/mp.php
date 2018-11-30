<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (isset($_SESSION["username"])){?>
<!doctype <!DOCTYPE html>
<html>
<head>
    <title>Camagru</title>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style5.css" />
</head>
<body style="background-color: #407fe5">
<div class="header">
    <p style="text-align: center"><u>Editing</u></p>
    <div class="profile" style="position: absolute; border-radius: 250px; width: 5vw; height: 5vw; text-align: center; background-size: cover; background-repeat: no-repeat; background-position: center center;
        <?php 
            echo "background-image: url('".$_SESSION['profile']."');";
        ?>">
        <form name="User Settings">
            <select class="select" style="width: 200px" onchange="location = this.value">
                <option>Settings</option>
                <option value="http://localhost:8080/Camagru/mygall/mgall.php">My Gallery</option>
                <option value="http://localhost:8080/Camagru/pswd/pswd.php">Edit Password</option>
                <option value="http://localhost:8080/Camagru/pphoto/pphoto.php">Edit Profile Photo</option>
                <option value="http://localhost:8080/Camagru/user_e/user_e.php">Edit Username</option>
                <option value="http://localhost:8080/Camagru/email_e/email_e.php">Edit Email</option>
                <option value="http://localhost:8080/Camagru/email_c/email_c.php">Email Settings</option>
                <option value="http://localhost:8080/Camagru/main_page/logout.php">Logout</option>
            </select>
        </form>
    </div>
</div>
<div style="display: flex">
    <div class="left">
        <p style="text-align: center"><u>Preview</u></p>
        <div class="view">
            <div id="uphoto" style="margin-left: 1.3%; width: 40vw; height: 30vw; position: absolute; background-size: 40vw 30vw;
            <?php   if (isset($_GET['image']))
                        echo "background-image: url('uploads/".$_GET['image'].".png');";
                    if (isset($_POST["clear"]))
                        echo "background-image: none";
            ?>"></div>
            <div id="sticker2" style="margin-left: 1.3%; width: 40vw; height: 30vw; position: absolute; background-size: 40vw 30vw;"></div>
            <div id="sticker1" style="margin-left: 1.3%; width: 40vw; height: 30vw; position: absolute; background-size: 40vw 30vw;"></div>
            <video id="video" width="100%" height="100%" autoplay></video>
        </div>
        <form method="POST" action="edit.php" enctype="multipart/form-data" target="uphoto">
            <input type="file" name="fileToUpload" id="button"/>
            <input type="submit" name="submit" value="Upload file" id="button"/>
            <button type="button" id="capture" style="left-margin: 50%">Take Photo</button>
        </form>
        <div class="view">
            <canvas id="canvas" style="width: 94%; margin-left: 3%; border: 1px solid black;"></canvas>
            <form method="POST" action="upload.php" enctype="multipart/form-data">
                <input type="hidden" name="sub_sticker" id="sub_sticker" value="">
                <input type="hidden" name="sub_sticker_2" id="sub_sticker_2" value="">
                <input type="hidden" name="sub_image" id="sub_image" value="">
                <button type="submit" id="save">Save photo</button>
            </form>
            <canvas id="canvas_2" style="width: 320px; height: 220px; display: none"></canvas>
        </div>
        <div class="space"></div>
    </div>
    <div class="right">
    <p style="text-align: center"><u>Stickers</u></p>
    <hr>
    <div class="rview">
        <IMG SRC="https://i.imgur.com/LZ69tPO.png" onclick="loadPicture1(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/QqOSYyw.png" onclick="loadPicture1(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/S2dRq30.png" onclick="loadPicture1(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/oNWfkgF.png" onclick="loadPicture1(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/4W0FCVB.png" onclick="loadPicture1(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
    </div>
    <p style="text-align: center"><u>Background</u></p>
    <hr>
    <div class="rview">
        <IMG SRC="https://i.imgur.com/Q9XeYpc.png" onclick="loadPicture2(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/aXW4czG.png" onclick="loadPicture2(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/5ehSLRe.png" onclick="loadPicture2(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/frxyGsG.png" onclick="loadPicture2(event)" style="max-width: 100%; max-height: 100%; min-width: 100%; min-height:50%; border-radius: 15px">
    </div>
</div>
<div class="tnail">
    <p style="text-align: center"><u>Thumbnails</u></p>
    <hr>
    <div class="tview">
    <?php
			$sql = $conn->prepare(
			"SELECT
				`image_id`, `image_creator`
			FROM
				`cosincla_camagru`.`uploads`
			WHERE
				`image_id` NOT LIKE 'replacement'
			ORDER BY
				`date_created` DESC;");
			$sql->execute();

			$sql->setFetchMode(PDO::FETCH_ASSOC);
			$stuff = $sql->fetchAll();
            foreach($stuff as $s){
                $_POST['name'] = $s['image_creator'];
                $lemon = $s['image_id']; ?>
                <img style="width: 50%; height: 100%; border-radius: 15px" src="/Camagru/main_page/uploads/<?php echo $s['image_id'].".png"; ?>"><?php } ?>     
    </div>
</div>
<div class="back">
    <a href="http://localhost:8080/Camagru/gallery/gall.php"><p style="text-align: center">Back</p></A>
</div>
<script src="video.js"></script>
</body>
<footer id="footer">
	<p>&copy; Terms and conditions apply.<br>cosincla2018.</p>
</footer>
</html>
<?php }
else
    echo '<script type=text/javascript>alert("Please log in"); window.location="http://localhost:8080/Camagru/";</script>';
?>