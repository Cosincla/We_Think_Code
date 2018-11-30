<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

$temp = $_GET['image'];
$_SESSION['woop'] = $temp; 
if (isset($_SESSION["username"])){?>
<!doctype <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style360.css">
</head>
<body>
<div style="display: flex">
    <div class="box">
        <?php
            $uname = $_SESSION["username"];
            $sql = $conn->prepare(
                "SELECT COUNT(`like`) AS `likes`
                FROM
                    `cosincla_camagru`.`likes`
                WHERE
                    `image_creator` LIKE '$uname' AND `like` = 1;"
            );
            $sql->execute();

            $sql->setFetchMode(PDO::FETCH_ASSOC);
            $stuff = $sql->fetchAll();
            if (empty($stuff))
                $likes = 0;
            else {
			    foreach($stuff as $s)
                    $likes = $s['likes'];
            }
            echo $likes;
            if ($likes == 1)
                echo " person likes ";
            else
                echo " people like ";
            echo "your photo";
            ?></p>
        <div class="view">
            <img style="width: 100%; border-radius: 15px;" src="/Camagru/main_page/uploads/<?php echo $_GET['image'].".png"; ?>">
        </div>
        <p style="text-decoration: underline;"> Comments</p>
        <div class="cview">
            <?php
                $uname = $_SESSION["username"];
                $sql = $conn->prepare(
                    "SELECT
                        `comment`, `commenter`
                    FROM
                        `cosincla_camagru`.`comments`
                    WHERE
                        `image_id` LIKE '$temp'"
                );
                $sql->execute();
                $sql->setFetchMode(PDO::FETCH_ASSOC);
                $stiff = $sql->fetchAll();
                if (empty($stiff))
                    echo "There are no comments";
                else {
                    foreach($stiff as $s) {
                        ?><hr><?php
                        echo $s['comment'];
                        ?><p style="text-align: right"><?php
                        echo "by " . $s['commenter'];
                        ?></p><hr><?php
                    }
                }
            ?>
        </div>
    </div>
</div>
<div class="footer">
    <div class="back">
        <a href="http://localhost:8080/Camagru/gallery/gall.php"><p style="text-align: center">Back</p></A>
    </div>
</div>
</body>
</html>
<?php }
else
    echo '<script type=text/javascript>alert("Please log in"); window.location="http://localhost:8080/Camagru/";</script>';
?>
