<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (!empty($_POST["code"])) {
    $code = $_POST["code"];
    $new = $_SESSION['email'];

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
        $name = $s['user_id'];
        if ($s['unlock'] === $code){
            $sql = $conn->prepare(
                "UPDATE
                    `cosincla_camagru`.`users`
                SET
                    `email` = '$new'
                WHERE
                    `username` LIKE '$name';");
            $sql->execute();
            session_unset($_SESSION['email']);

            $sql = $conn->prepare(
                "DELETE FROM
                    `cosincla_camagru`.`verification`
                WHERE
                    `user_id`='$uid';");
            $sql->execute();
            echo '<script type=text/javascript>alert("Email Successfully changed"); window.close();";</script>';
        }
        else
            echo '<script type=text/javascript>alert("Incorrect code"); window.location="http://localhost:8080/Camagru/email_v/email_v.php";</script>';
    }
}
else
    echo '<script type=text/javascript>alert("Invalid input"); window.location="http://localhost:8080/Camagru/user_e/user_e.php";</script>';

?>