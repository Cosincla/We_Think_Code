<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/init.php');

if (!empty($_POST["text"]))
{
    $text = $_POST["text"];
    $user = $_SESSION["username"];
    $sql =$conn->prepare(
        "SELECT
            `bio_check`
        FROM
            `cosincla_matcha`.`profiles`
        WHERE
            `username` LIKE '$user';");
    $sql->execute();
    $sql->setFetchMode(PDO::FETCH_ASSOC);
    $stuff = $sql->fetchAll();
    foreach($stuff as $s){
        if ($s['bio_check'] === '0'){
            $sql = $conn->prepare(
                "UPDATE
                    `cosincla_matcha`.`profiles`
                SET
                    `bio` = '$text',
                    `bio_check` = 1
                WHERE
                    `username` LIKE '$user';");
            $sql->execute();
        }
        else {
            $sql = $conn->prepare(
                "UPDATE
                    `cosincla_matcha`.`profiles`
                SET
                    `bio` = '$text'
                WHERE
                    `username` LIKE '$user';");
                $sql->execute();
        }
    }
    echo '<script type=text/javascript>alert("Biography updated"); window.location="http://localhost:8080/Matcha/myprofile/my.php";</script>';
}
else
    echo '<script type=text/javascript>alert("Incomplete input"); window.location="http://localhost:8080/Matcha/myprofile/biography/biography.php";</script>';
?>