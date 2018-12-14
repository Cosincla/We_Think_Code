<?PHP

require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/config/database.php');

if (!$_POST["first"] || !$_POST["surname"] || !$_POST["username"] || (!$_POST["age"] || !is_numeric($_POST["age"])) || !$_POST["gender"] || !$_POST["sex"] || !$_POST["email"] || !$_POST["pwd"] || !$_POST["pwdc"] || ($_POST["pwd"] != $_POST["pwdc"]))
    echo '<script type=text/javascript>alert("Invalid input"); window.location="http://localhost:8080/Matcha/new_user/new.php";</script>';
else
{
    try
    {
        $sql = $conn->prepare("INSERT INTO `cosincla_matcha`.`users` (`name`, `surname`, `username`, `age`, `gender`, `preference`, `password`, `email`) 
        VALUES (:p_name, :p_surname, :p_username, :p_age, :p_gender, :p_preference, :p_password, :p_email)");
        $name = $_POST["first"];
        $surname = $_POST["surname"];
        $username = $_POST["username"];
        $age = $_POST["age"];
        $gender = $_POST["gender"];
        $sex = $_POST["sex"];
        $password = $_POST["pwd"];
        $email = $_POST["email"];
        $hash = hash('whirlpool', $password);
        $sql->execute(array(
            ':p_name' => $name,
            ':p_surname' => $surname,
            ':p_username' => $username,
            ':p_age' => $age,
            ':p_gender' => $gender,
            ':p_preference' => $sex,
            ':p_password' => $hash,
            ':p_email' => $email));
        $sql = $conn->prepare(
            "INSERT INTO 
                `cosincla_matcha`.`verification` (`user_id`, `unlock`)
            VALUES 
                (:u_i, :u_c);");
        $code = getRandomWord(10);
        $sql->execute(array(
            ':u_i' => $username,
            ':u_c' => $code));
        
        $to      = $email;
        $subject = 'verification';
        $message = 'Greetings ' . $name . "\n" . "\n". 'Here is your verification code:  ' . $code . "\n" . "\n" . 'Kind regards' . "\n" . 'The Matcha Team.';
        $message = wordwrap($message, 70);
        mail($to, $subject, $message);
        
        echo '<script type=text/javascript>alert("A verification email has been sent"); window.location="http://localhost:8080/Matcha/email_v/email_v.php";</script>';
    }
    catch(PDOexception $e)
    {
        echo '<script type=text/javascript>alert("Email/Username is currently in use"); window.location="http://localhost:8080/Matcha/";</script>';
    }
}
?>