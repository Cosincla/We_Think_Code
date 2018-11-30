<?php
$DB_DSN = 'mysql:unix_socket=/goinfre/cosincla/MAMP/mysql/tmp/mysql.sock;';
$DB_USER = "root";
$DB_PASSWORD = "root";

function getRandomWord($len) {
    $word = array_merge(range('a', 'z'), range('A', 'Z'), range(1, 20));
    shuffle($word);
    return substr(implode($word), 0, $len);
}

try {
    $conn = new PDO($DB_DSN, $DB_USER, $DB_PASSWORD);
    $conn->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
}
catch(PDOexception $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>