<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (!empty($_POST["login"])){
    $uname = $_POST["login"];
    $sql = $conn->prepare(
        "SELECT
            `email`,
            `username`,
            `name`
        FROM
            `cosincla_camagru`.`users`
        WHERE
            `username` LIKE '$uname';");
    $sql->execute();

    $sql->setFetchMode(PDO::FETCH_ASSOC);
    $stuff = $sql->fetchAll();
    foreach($stuff as $s) {
        if ($s['username'] === $uname){

            $sql = $conn->prepare(
                "INSERT INTO 
                    `cosincla_camagru`.`verification` (`user_id`, `unlock`)
                VALUES 
                    (:u_i, :u_c);");
            $username = $s['username'];
            $code = getRandomWord(10);
            $sql->execute(array(
                ':u_i' => $username,
                ':u_c' => $code));

            
            $to      = $s['email'];
            $subject = 'Password reset';
            $link    = 'http://localhost:8080/Camagru/email_r/prec.php';
            $message = 'Greetings ' . $s['name'] . "\n" . "\n". 'Here is a link to reset your password:  ' . $link . "\n" . 'Here is your verification code:  ' . $code . "\n" . "\n" . 'Kind regards' . "\n" . 'The Camagru Team.';
            $message = wordwrap($message, 70);
            mail($to, $subject, $message);
            echo '<script type=text/javascript>alert("A message has been sent to your email account"); window.location="http://localhost:8080/Camagru";</script>';
        }
        else
            echo '<script type=text/javascript>alert("User does not exist"); window.location="http://localhost:8080/Camagru/email_r/email.php";</script>';
    }
}
else
    echo '<script type=text/javascript>alert("Invalid Input"); window.location="http://localhost:8080/Camagru/email_r/email.php";</script>';

?>