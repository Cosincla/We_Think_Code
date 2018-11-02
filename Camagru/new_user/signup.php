<?PHP
if (!$_POST["first"] || !$_POST["surname"] || !$_POST["username"] || !$_POST["email"] || !$_POST["pwd"] || !$_POST["pwdc"] || ($_POST["pwd"] != $_POST["pwdc"])) {
    echo "ERROR\n";
    return (0);
}
else
{
    try
    {
        $conn = new PDO("mysql:host=localhost;dbname=cosincla_camagru", "root", "root");
        $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
        $sql = $conn->prepare("INSERT INTO users ('name', 'surname', 'username', 'password', 'email') 
        VALUES (:p_name, :p_surname, :p_username, :p_password, :p_email)");
        $name = $_POST["first"];
        $surname = $_POST["surname"];
        $username = $_POST["username"];
        $password = $_POST["pwd"];
        $email = $_POST["email"];
        /*$sql->bindParam(':p_name', $name);
        $sql->bindParam(':p_surname', $surname);
        $sql->bindParam(':p_username', $username);
        $sql->bindParam(':p_password', $password);
        $sql->bindParam(':p_email', $email);*/
        $sql->execute(array(':p_name' => $name, ':p_surname' => $surname, ':p_username' => $username, ':p_password' => $password, ':p_email' => $email));
    }
    catch(PDOexception $e)
    {
        echo $e;
    }
}
$conn = null;
?>