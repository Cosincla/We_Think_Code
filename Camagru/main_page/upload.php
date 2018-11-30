<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

$target_dir = "uploads/";
if(!is_dir($target_dir))
    mkdir($target_dir, 0755, true);
$user = $_SESSION['username'];
$name = getRandomWord(10);
if (isset($_POST["sub_image"]) && !empty($_POST["sub_image"])
&& ((isset($_POST["sub_sticker"])) && !empty($_POST["sub_sticker"]) && ($_POST["sub_sticker"] !== ' ') && substr($_POST["sub_sticker"], 0, 5) !== "http:"
|| (isset($_POST["sub_sticker_2"])) && !empty($_POST["sub_sticker_2"]) && ($_POST["sub_sticker_2"] !== ' ') && substr($_POST["sub_sticker_2"], 0, 5) !== "http:")) {
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
    if ($_POST["sub_sticker_2"] != ' ' && substr($_POST["sub_sticker_2"], 0, 5) !== "http:"){
        $bg = $_POST["sub_sticker_2"];
        $src3 = imagecreatefrompng($bg);
        $src3 = imagescale($src3, imagesx($src), imagesy($src));
        imagecopy($src, $src3, 0, 0, 0, 0, imagesx($src3), imagesy($src3));
    }
    if ($_POST["sub_sticker"] != ' ' && substr($_POST["sub_sticker"], 0, 5) !== "http:"){
        $sticker = $_POST["sub_sticker"];
        $src2 = imagecreatefrompng($sticker);
        $src2 = imagescale($src2, imagesx($src), imagesy($src));
        imagecopy($src, $src2, 0, 0, 0, 0, imagesx($src2), imagesy($src2));
    }
    imagepng($src, $target_dir.$name.".png");
    imagedestroy($src);

    $user = $_SESSION["username"];
    $sql = $conn->prepare(
        "INSERT INTO
            `cosincla_camagru`.`uploads` (`image_creator`, `image_id`)
        VALUES
            (:p_ic, :p_iid)"
        );
    $sql->execute(array(
        ':p_ic' => $user,
        ':p_iid' => $name
    ));
    echo '<script type=text/javascript>alert("Image successfully updated"); window.location="http://localhost:8080/Camagru/gallery/gall.php";</script>';
}
else
    echo '<script type=text/javascript>alert("You must either take a photo or upload an image AND choose either a sticker or a background"); window.location="http://localhost:8080/Camagru/main_page/mp.php";</script>';
?>