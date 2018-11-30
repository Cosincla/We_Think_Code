<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

session_destroy();
echo '<script type=text/javascript>alert("Logout successful"); window.location="http://localhost:8080/Camagru";</script>';

?>