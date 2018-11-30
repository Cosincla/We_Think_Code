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
    <link rel="stylesheet" type="text/css" href="style57.css" />
</head>
<body style="background-color: #407fe5">
<div class="header">
    <p style="text-align: center"><u>Gallery</u></p>
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
<div class="right">
    <div class="rview">
        <form method="POST">
        <?php
            if (isset($_GET['page'])) {
                $page = $_GET['page'];
            } else {
                $page = 1;
            }
            $img = 5;
            $offset = ($page - 1) * $img;
    
            $sql = $conn->prepare(
                "SELECT
                    COUNT(`image_id`) AS 'images'
                FROM
                    `cosincla_camagru`.`uploads`
                WHERE
                    `image_id` NOT LIKE 'replacement'"
            );
            $sql->execute();
            $sql->setFetchMode(PDO::FETCH_ASSOC);
            $stff = $sql->fetchAll();
            foreach ($stff as $u)
                $num = $u['images'];
            $total = ceil($num / $img);

			$sql = $conn->prepare(
			"SELECT
				`image_id`, `image_creator`
			FROM
				`cosincla_camagru`.`uploads`
			WHERE
				`image_id` NOT LIKE 'replacement'
			ORDER BY
				`date_created` DESC
            LIMIT
                $offset, $img;");
			$sql->execute();

			$sql->setFetchMode(PDO::FETCH_ASSOC);
			$stuff = $sql->fetchAll();
            foreach($stuff as $s){
                $_POST['name'] = $s['image_creator'];
                $lemon = $s['image_id']; ?>
                <?php echo "<a style='font-size: 1vw;
                            position: relative;
                            width: 6vw;
                            height: 3vw;
                            margin-left: 5%;
                            margin-top: 1000%;
                            background-color: #B4B0B0;
                            border-radius: 15px;
                            padding: 4px;';
                            href='com.php?image=$lemon'>Like/comment<a>"; ?>
                <div style="margin-top: -7%;">
                    <div style="width: 100%; border-radius: 15px;">
                        <div class="profile" style="margin-top: 7%; position: relative; marginborder-radius: 250px; width: 5vw; height: 5vw; text-align: center; background-size: cover; background-repeat: no-repeat; background-position: center center;
                            <?php
                                $name = $_POST['name'];
                                $sql = $conn->prepare(
                                    "SELECT
                                        `id`
                                    FROM
                                        `cosincla_camagru`.`profile_photos`
                                    WHERE
                                        `user_id` LIKE '$name' AND `selected` = 1
                                    ;");
                                $sql->execute();
                
                                $sql->setFetchMode(PDO::FETCH_ASSOC);
                                $stuff = $sql->fetchAll();
                                foreach($stuff as $t){ 
                                    $image = "/Camagru/pphoto/profile_photos/".$t['id'].".png";
                                    $_SESSION['hidden'] = $t['id'];
                                }
                                echo "background-image: url('".$image."');";
                            ?>">
                        </div>
                        <img style="margin-top: -7%; width: 100%; border-radius: 15px; position absolute" src="/Camagru/main_page/uploads/<?php echo $s['image_id'].".png"; ?>">
                    </div>
                </div>
            <?php } ?>
        </form>
    </div>
</div>
<ul class="pagination">
            <li><a href="?pageno=1">First</a></li>
            <li class="<?php if($page <= 1){ echo 'disabled'; } ?>">
                <a href="<?php if($page <= 1){ echo '#'; } else { echo "?page=".($page - 1); } ?>">Prev</a>
            </li>
            <li class="<?php if($page >= $total){ echo 'disabled'; } ?>">
                <a href="<?php if($page >= $total){ echo '#'; } else { echo "?page=".($page + 1); } ?>">Next</a>
            </li>
            <li><a href="?page=<?php echo $total; ?>">Last</a></li>
        </ul>
<div>
    <div class="back">
        <a href="http://localhost:8080/Camagru/main_page/mp.php"><p style="text-align: center">Create</p></A>
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