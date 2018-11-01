<!doctype <!DOCTYPE html>
<html>
<head>
    <title>Camagru</title>
    <meta charset="UTF-8" />
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="stylesheet" type="text/css" href="style5.css" />
</head>
<body style="background-color: #407fe5">
<div class="header">
    <div class="profile">
        <IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="height:100%; width:100%; border-radius: 100px">
        <form name="User Settings">
            <select class="select" style="width: 200px" onchange="location = this.value">
                <option value="http://localhost:8080/Camagru/email_r/email.php">My Gallery</option>
                <option value="http://localhost:8080/Camagru/pswd/pswd.php">Edit Password</option>
                <option value="http://localhost:8080/Camagru/email_r/email.php">Edit Profile Photo</option>
                <option value="http://localhost:8080/Camagru/user_e/user_e.php">Edit Username</option>
                <option value="http://localhost:8080/Camagru/email_e/email_e.php">Edit Email</option>
                <option value="http://localhost:8080/Camagru/email_e/email_e.php">Email Settings</option>
                <option value="http://localhost:8080/Camagru">Logout</option>
            </select>
        </form>
    </div>
    <p style="text-align: center"><u>Editing</u></p>
</div>
<div style="display: flex">
    <div class="left">
        <div class="view">
            <div id="sticker" style="margin-left: 1.3%; width: 40vw; height: 30vw; position: absolute; background-size: 40vw 30vw;"></div>
            <div name="uphoto" id="uphoto" style="margin-left: 1.3%; width: 40vw; height: 30vw; position: absolute; background-size: 40vw 30vw;"></div>
            <video id="video" width="100%" height="100%" autoplay></video>
        </div>
        <form action="edit.php"  method="post" enctype="multipart/form-data" target="uphoto">
            <input type="file" name="fileToUpload" id="button"/>
            <input type="submit" name="submit" value="Upload file" id="button"/>
        </form>
        <button type="button" id="button" onclick="clear();">Use Video</button>
        <button type="button" id="capture" style="left-margin: 50%">Take Photo</button>
        <div class="view">
            <canvas id="canvas" style="width: 94%; margin-left: 3%; border: 1px solid black;"></canvas>
            <button type="button">Save photo</button>
        </div>
        <div class="space"></div>
    </div>
    <div class="right">
    <p style="text-align: center"><u>Filters</u></p>
    <hr>
    <div class="rview">
        <IMG SRC="https://i.imgur.com/LZ69tPO.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/Q9XeYpc.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/QqOSYyw.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/S2dRq30.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/oNWfkgF.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/4W0FCVB.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/aXW4czG.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/5ehSLRe.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/frxyGsG.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
        <IMG SRC="https://i.imgur.com/5ehSLRe.png" onclick="loadPicture(event)" style="max-width: 100%; max-height: 100%; min-width: 50%; min-height:50%; border-radius: 15px">
    </div>
</div>
<div class="footer">
    <div class="back">
        <a href="http://localhost:8080/Camagru/"><p style="text-align: center">Back</p></A>
    </div>
</div>
<script src="video.js"></script>
</body>
</html>