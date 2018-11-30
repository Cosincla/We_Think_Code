<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

$del = $_SESSION['delete'];
if (isset($_POST['yes'])){
    $sql = $conn->prepare(
        "DELETE FROM
            `cosincla_camagru`.`uploads`
        WHERE
            `image_id` LIKE '$del';");
    $sql->execute();
    echo '<script type=text/javascript>alert("Image deleted"); window.location="http://localhost:8080/Camagru/mygall/mgall.php";</script>';
}
if (isset($_POST['no'])){
    echo '<script type=text/javascript>alert("Image will not be deleted"); window.location="http://localhost:8080/Camagru/mygall/mgall.php";</script>';
}
?>