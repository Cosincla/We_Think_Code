<?PHP

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');

if (!$_POST["first"] || !$_POST["surname"] || !$_POST["username"] || !$_POST["email"] || !$_POST["pwd"] || !$_POST["pwdc"] || ($_POST["pwd"] != $_POST["pwdc"]))
    echo '<script type=text/javascript>alert("Invalid input"); window.location="http://localhost:8080/Camagru/new_user/new.php";</script>';
else
{
    try
    {
        $sql = $conn->prepare("INSERT INTO `cosincla_camagru`.`users` (`name`, `surname`, `username`, `password`, `email`, `email_on_comment`) 
        VALUES (:p_name, :p_surname, :p_username, :p_password, :p_email, :p_eoc)");
        $name = $_POST["first"];
        $surname = $_POST["surname"];
        $username = $_POST["username"];
        $password = $_POST["pwd"];
        $email = $_POST["email"];
        $hash = hash('whirlpool', $password);
        if (isset($_POST["c_box"]))
            $eoc = 1;
        else
            $eoc = 0;
        $sql->execute(array(
            ':p_name' => $name,
            ':p_surname' => $surname,
            ':p_username' => $username,
            ':p_password' => $hash,
            ':p_email' => $email,
            ':p_eoc' => $eoc));
        $sql = $conn->prepare(
            "INSERT INTO 
                `cosincla_camagru`.`verification` (`user_id`, `unlock`)
            VALUES 
                (:u_i, :u_c);");
        $code = getRandomWord(10);
        $sql->execute(array(
            ':u_i' => $username,
            ':u_c' => $code));
        
        $to      = $email;
        $subject = 'verification';
        $message = 'Greetings ' . $name . "\n" . "\n". 'Here is your verification code:  ' . $code . "\n" . "\n" . 'Kind regards' . "\n" . 'The Camagru Team.';
        $message = wordwrap($message, 70);
        mail($to, $subject, $message);
        
        echo '<script type=text/javascript>alert("A verification email has been sent"); window.location="http://localhost:8080/Camagru/email_v/email_v.php";</script>';
    }
    catch(PDOexception $e)
    {
        echo '<script type=text/javascript>alert("Email/Username is currently in use"); window.location="http://localhost:8080/Camagru/";</script>';
    }
}
?>