<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/init.php');

if (isset($_SESSION["username"])){?><!doctype <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Camagru</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style6.css">
</head>
<body>
<div style="display: flex">
    <div class="box">
        <form method="POST" action="pswdc.php">
        <h3 style="text-align: center; font-family: Courier New, Courier, monospace">New Password:<br><input type="password" name="new"></h3>
        <input style="width: 70%; margin-left: 15%" type="submit" value="Finished?">
        </form>
    </div>
</div>
<div class="footer">
    <div class="back" onclick="goBack()">
        <script>function goBack() {window.history.back();}</script><p style="text-align: center">Back</p></A>
    </div>
</div>
</body>
</html>
<?php }
else
    echo '<script type=text/javascript>alert("Please log in"); window.location="http://localhost:8080/Camagru/";</script>';
?>