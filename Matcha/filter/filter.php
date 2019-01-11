<?php

require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/config/database.php');
require_once($_SERVER['DOCUMENT_ROOT'].'/Matcha/init.php');

if (isset($_SESSION["username"])){?><!doctype <!DOCTYPE html>
<html>
<head>
    <meta charset="utf-8" />
    <title>Matcha</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style76.css">
</head>
<body>
<div style="display: flex">
    <div class="box">
        <form method="POST" action="usere.php">
        <h3 style="text-align: center; font-family: Courier New, Courier, monospace">Age:<br><input type="text" name="age" list="age"></h3>
        <datalist id="age">
                <option value="20-24">
                <option value="25-29">
                <option value="30-34">
                <option value="35-39">
                <option value="40-44">
                <option value="45-50">
        </datalist>
        <h3 style="text-align: center; font-family: Courier New, Courier, monospace">Fame:<br><input type="text" name="fame" list="fame"></h3>
        <datalist id="fame">
                <option value="1">
                <option value="2">
                <option value="3">
                <option value="4">
                <option value="5">
                <option value="6">
                <option value="7">
                <option value="8">
                <option value="9">
                <option value="10">
        </datalist>
        <h3 style="text-align: center; font-family: Courier New, Courier, monospace">Distance from you:<br><input type="text" name="distance" list="dist"></h3>
        <datalist id="dist">
                <option value="0km-4km">
                <option value="5km-9km">
                <option value="10km-14km">
                <option value="15km-20km">
        </datalist>
        <h3 style="text-align: center; font-family: Courier New, Courier, monospace">Simular interests:<br><input type="text" name="interests" list="ints"></h3>
        <datalist id="ints">
                <option value="4">
                <option value="3">
                <option value="2">
                <option value="1">
        </datalist>
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
    echo '<script type=text/javascript>alert("Please log in"); window.location="http://localhost:8080/Matcha/";</script>';
?>