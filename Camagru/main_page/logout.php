<?php

require_once('../config/setup.php');
require_once('../init.php');

session_destroy();
echo '<script type=text/javascript>alert("Logout successful"); window.location="http://localhost:8080/Camagru";</script>';

?>