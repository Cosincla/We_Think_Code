<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (isset($_SESSION["username"])){?><!doctype <!DOCTYPE html>
<html>
<head>
    <title>Camagru</title>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style570.css" />
</head>
<body style="background-color: #407fe5">
<div class="header">
    <p style="text-align: center"><u> My Gallery</u></p>
    <div class="profile" style="position: absolute; border-radius: 250px; width: 5vw; height: 5vw; text-align: center; background-size: cover; background-repeat: no-repeat; background-position: center center;
        <?php 
            echo "background-image: url('".$_SESSION['profile']."');";
        ?>">
        <form name="User Settings">
            <select class="select" style="width: 200px" onchange="location = this.value">
                <option>Settings</option>
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
<div class="right">
    <div class="rview">
        <form method="POST">
        <?php
        $user = $_SESSION['username'];
        $sql = $conn->prepare(
			    "SELECT
				    `image_id`, `image_creator`
			    FROM
				    `cosincla_camagru`.`uploads`
			    WHERE
				    `image_id` NOT LIKE 'replacement' AND `image_creator` LIKE '$user'
			    ORDER BY
				    `date_created` DESC;");
			    $sql->execute();

			    $sql->setFetchMode(PDO::FETCH_ASSOC);
			    $stuff = $sql->fetchAll();
			    foreach($stuff as $s){
                    $lemon = $s['image_id'];
                    echo "<a style='font-size: 1vw;
                            position: relative;
                            width: 6vw;
                            height: 3vw;
                            margin-left: 0%;
                            margin-top: 1000%;
                            background-color: #B4B0B0;
                            border-radius: 15px;
                            padding: 4px;';
                            href='http://localhost:8080/Camagru/mygall/mine.php?image=$lemon'>View likes/comments<a>";
                    echo "<a style='font-size: 1vw;
                            position: relative;
                            width: 6vw;
                            height: 3vw;
                            margin-left: 1%;
                            margin-top: 1000%;
                            background-color: #B4B0B0;
                            border-radius: 15px;
                            padding: 4px;';
                            href='http://localhost:8080/Camagru/mygall/del.php?image=$lemon'>Delete<a>"; ?>
                    <img style="width: 100%; border-radius: 15px" src="/Camagru/main_page/uploads/<?php echo $s['image_id'].".png"; ?>">
                    <?php } ?>
    </div>
</div>
<div class="footer">
    <div class="back" onclick="goBack()">
        <script>function goBack() {window.history.back();}</script><p style="text-align: center">Back</p></A>
    </div>
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