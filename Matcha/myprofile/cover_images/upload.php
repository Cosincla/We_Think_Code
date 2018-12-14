<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/init.php');

$target_dir = "upload/";
if(!is_dir($target_dir))
    mkdir($target_dir, 0755, true);
$user = $_SESSION['username'];
$name = getRandomWord(10);
if (isset($_POST["sub_image"]) && !empty($_POST["sub_image"])) {
    $check = substr($_POST["sub_image"], 0, 5);
    if (strcmp($check, "data:")){
        $temp = $_POST["sub_image"];
    }
    else {
        $data = explode(',', $_POST['sub_image']);
        $image = base64_decode($data[1]);
        $temp = $target_dir.$name.".png";
        file_put_contents($temp, $image);
    }
    $src = imagecreatefrompng($temp);
    imagepng($src, $target_dir.$name.".png");
    imagedestroy($src);

    $user = $_SESSION["username"];
    $sql = $conn->prepare(
        "UPDATE
            `cosincla_matcha`.`profiles`
        SET
            `cover_image` = '$name',
            `cover_check` = 1
        WHERE
            `username` LIKE '$user';");
    $sql->execute();
    echo '<script type=text/javascript>alert("Image successfully uploaded"); window.location="http://localhost:8080/Matcha/myprofile/my.php";</script>';
}
else
    echo '<script type=text/javascript>alert("You must either take a photo or upload an image"); window.location="http://localhost:8080/Matcha/myprofile/cover_images/cover.php";</script>';
?>