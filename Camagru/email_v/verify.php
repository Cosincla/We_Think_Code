<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');

if (!empty($_POST["code"])) {
    $code = $_POST["code"];

    $sql = $conn->prepare(
        "SELECT
            `user_id`,
            `unlock`
        FROM
            `cosincla_camagru`.`verification`;");
    $sql->execute();
    
    $sql->setFetchMode(PDO::FETCH_ASSOC);
    $stuff = $sql->fetchAll();
    foreach($stuff as $s) {
        if ($s['unlock'] === $code){
            $uid = $s['user_id'];
            $sql = $conn->prepare(
                "UPDATE
                    `cosincla_camagru`.`users`
                SET
                    `validated` = 1
                WHERE
                    `username` LIKE '$uid';");
            $sql->execute();

            $sql = $conn->prepare(
                "DELETE FROM
                    `cosincla_camagru`.`verification`
                WHERE
                    `user_id`='$uid';");
            $sql->execute();
            echo '<script type=text/javascript>alert("User is now verified"); window.location="http://localhost:8080/Camagru/";</script>';
        }
        else
        echo '<script type=text/javascript>alert("Incorrect code"); window.location="http://localhost:8080/Camagru/email_v/email_v.php";</script>';
    }
}
else
    echo '<script type=text/javascript>alert("Incorrect code"); window.location="http://localhost:8080/Camagru/user_e/user_e.php";</script>';

?>