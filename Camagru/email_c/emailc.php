<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

$name = $_SESSION['username'];
if (isset($_POST["yes"])){
    $sql = $conn->prepare(
        "UPDATE
            `cosincla_camagru`.`users`
        SET
            `email_on_comment` = 1
        WHERE
            `username` LIKE '$name';");
        $sql->execute();
        echo '<script type=text/javascript>alert("You will now recieve emails on comments"); window.location="http://localhost:8080/Camagru/main_page/mp.php";</script>';
}
else if (isset($_POST["no"])){
    $sql = $conn->prepare(
        "UPDATE
            `cosincla_camagru`.`users`
        SET
            `email_on_comment` = 0
        WHERE
            `username` LIKE '$name';");
        $sql->execute();
        echo '<script type=text/javascript>alert("You will no longer recieve emails on comments"); window.location="http://localhost:8080/Camagru/main_page/mp.php";</script>';
}
?>