<?PHP

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (!empty($_POST["login"]) && !empty($_POST["password"])){
    $uname = $_POST["login"];
    $pword = $_POST["password"];
    $hash = hash('whirlpool', $pword);
    
    $sql = $conn->prepare(
        "SELECT
            `password`,
            `username`,
            `validated`
        FROM
            `cosincla_camagru`.`users`
        WHERE
            `username` LIKE '$uname';");
    $sql->execute();

    $sql->setFetchMode(PDO::FETCH_ASSOC);
    $stuff = $sql->fetchAll();
    if (empty($stuff))
        echo '<script type=text/javascript>alert("User does not exist"); window.location="http://localhost:8080/Camagru/";</script>';
    foreach($stuff as $s) {
        if ($s['password'] === $hash){
            if ($s['validated'] == 1){
                echo '<script type=text/javascript>alert("Login successful"); window.location="/Camagru/gallery/gall.php";</script>';
                $_SESSION['username'] = $s['username'];
                $user = $_SESSION['username'];
                $sql = $conn->prepare(
                    "SELECT
                        `id`
                    FROM
                        `cosincla_camagru`.`profile_photos`
                    WHERE
                        `user_id` LIKE '$user' AND `selected` = 1;"
                );
                $sql->execute();
                $sql->setFetchMode(PDO::FETCH_ASSOC);
                $stuff = $sql->fetchAll();
                if (empty($stuff)){
                    $_SESSION['profile'] = "https://i.imgur.com/3RPJcXd.png";
                }
                else {
                    foreach($stuff as $s)
                        $photo = $s['id'];
                    $_SESSION['profile'] = "/Camagru/pphoto/profile_photos/".$photo.".png";
                }
                exit();
            }
            else
                echo '<script type=text/javascript>alert("User is not verified"); window.location="http://localhost:8080/Camagru/";</script>';
        }
        else {
            if ($s['validated'] == 1)
                echo '<script type=text/javascript>alert("Password is incorrect"); window.location="http://localhost:8080/Camagru/";</script>';
            else
                echo '<script type=text/javascript>alert("User does not exist"); window.location="http://localhost:8080/Camagru/";</script>';
        }
    }
}
else
    echo '<script type=text/javascript>alert("Invalid input"); window.location="http://localhost:8080/Camagru/";</script>';
session_unset();
?>