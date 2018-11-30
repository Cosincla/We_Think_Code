<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (isset($_SESSION['image'])){
    $num = $_SESSION['image'];
    echo $num;
    $user = $_SESSION["username"];
    
    $sql = $conn->prepare(
        "UPDATE
            `cosincla_camagru`.`profile_photos`
        SET
            `selected` = 0
        WHERE
            `user_id` LIKE '$user' AND `selected` = 1;"
    );
    $sql->execute();
    $_SESSION['profile'] = "http://localhost:8080/Camagru/pphoto/profile_photos/".$last_id.".png";
    $sql = $conn->prepare(
        "UPDATE
            `cosincla_camagru`.`profile_photos`
        SET
            `selected` = 1
        WHERE
            `user_id` LIKE '$user' AND `id` LIKE '$num';"
    );
    $sql->execute();
    $_SESSION['profile'] = "http://localhost:8080/Camagru/pphoto/profile_photos/".$_SESSION['image'].".png";
    session_unset($_SESSION['image']);
    echo '<script type=text/javascript>alert("Profile updated"); window.location="http://localhost:8080/Camagru/main_page/mp.php";</script>';
}
else
    echo '<script type=text/javascript>alert("No image selected"); window.location="http://localhost:8080/Camagru/pphoto/pphoto.php";</script>';