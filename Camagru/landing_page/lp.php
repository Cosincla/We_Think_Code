<!DOCTYPE html>
<html>
<head>
	<title>Camagru</title>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="landing_page/style1.css" />
</head>
<body style="background-color: maroon">
	<div class="header">
		<h2 style="text-align: center"><u>Welcome to Camagru</u></h2>
	</div>
	<div class="image">
		<a href="http://localhost:8080/Camagru/gallery/gall.php"><p style="text-align: center"><u>Gallery</u><p></a>
	</div>
	<div style="display: flex">
		<DIV class="left">
			<IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="width:100%; border-radius: 15px"><br>
			<IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="width:100%; border-radius: 15px"><br>
			<IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="width:100%; border-radius: 15px"><br>
			<IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="width:100%; border-radius: 15px"><br>
			<IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="width:100%; border-radius: 15px"><br>
			<IMG SRC="https://i.imgur.com/Vh5eoDc.jpg" style="width:100%; border-radius: 15px"><br>
		</DIV>
		<DIV style="width: 90%;" class="right">
			<p style="text-align: center"><u>Login</u></p>
			<hr>
			<form method="POST" action="main_page/mp.php">
				<p style="font-family: Courier New, Courier, monospace">Username:<br><input type="text" name="login" style="width: 80%"></p>
				<p style="font-family: Courier New, Courier, monospace">Password:<br><input type="password" namJe="password" style="width: 80%"></p>
				<input type="submit" id="submit" value="OK">
				<p style="text-align: center"><u>Forget your Passwrod?</u></p>
				<A href="http://localhost:8080/Camagru/email_r/email.php"><p><u>Click here</u></p></A>
			</form>
			<hr>
			<p style="text-align: center"><u>New User?</u></p>
			<A href="http://localhost:8080/Camagru/new_user/new.php"><p><u>Click here</u></p></A>
		</DIV>
	</div>
	<div class="footer">
		<hr>
	</div>
</body>
</html>