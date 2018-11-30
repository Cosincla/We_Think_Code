<?php
require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');
?><!DOCTYPE html>
<html>
<head>
	<title>Camagru</title>
	<meta charset="utf-8" />
	<meta name="viewport" content="width=device-width, initial-scale=1">
	<link rel="stylesheet" type="text/css" href="/Camagru/landing_page/style1.css" />
</head>
<body style="background-color: #407fe5">
	<div class="header">
		<h2 style="text-align: center"><u>Welcome to Camagru</u></h2>
	</div>
	<div class="image">
		<p style="text-align: center"><u>Gallery</u></p>
	</div>
	<div style="display: flex">
		<DIV class="left">
		<?php
		if (isset($_GET['page'])) {
			$page = $_GET['page'];
		} else {
			$page = 1;
		}
		$img = 5;
		$offset = ($page - 1) * $img;

		$sql = $conn->prepare(
			"SELECT
				COUNT(`image_id`) AS 'images'
			FROM
				`cosincla_camagru`.`uploads`
			WHERE
				`image_id` NOT LIKE 'replacement'"
		);
		$sql->execute();
		$sql->setFetchMode(PDO::FETCH_ASSOC);
		$stff = $sql->fetchAll();
		foreach ($stff as $u)
			$num = $u['images'];
		$total = ceil($num / $img);

		$sql = $conn->prepare(
			"SELECT
				`image_id`
			FROM
				`cosincla_camagru`.`uploads`
			WHERE
				`image_id` NOT LIKE 'replacement'
			ORDER BY
				`date_created` DESC
			LIMIT
				$offset, $img;");
			$sql->execute();

			$sql->setFetchMode(PDO::FETCH_ASSOC);
			$stuff = $sql->fetchAll();
			foreach($stuff as $s){
				?><img style="width: 100%; border-radius: 15px" src="/Camagru/main_page/uploads/<?php echo $s['image_id'].".png"; ?>"><?php } ?>
	</DIV>
	<ul class="pagination">
        <li><a href="?pageno=1">First</a></li>
        <li class="<?php if($page <= 1){ echo 'disabled'; } ?>">
            <a href="<?php if($page <= 1){ echo '#'; } else { echo "?page=".($page - 1); } ?>">Prev</a>
        </li>
        <li class="<?php if($page >= $total){ echo 'disabled'; } ?>">
            <a href="<?php if($page >= $total){ echo '#'; } else { echo "?page=".($page + 1); } ?>">Next</a>
        </li>
        <li><a href="?page=<?php echo $total; ?>">Last</a></li>
    </ul>
		<DIV style="width: 90%;" class="right">
			<p style="text-align: center"><u>Login</u></p>
			<hr>
			<form method="POST" action="/Camagru/landing_page/login.php">
				<p style="font-family: Courier New, Courier, monospace">Username:<br><input type="text" name="login" style="width: 80%"></p>
				<p style="font-family: Courier New, Courier, monospace">Password:<br><input type="password" name="password" style="width: 80%"></p>
				<input type="submit" id="submit" value="OK">
				<p style="text-align: center"><u>Forgot your Passwrod?</u></p>
				<A href="http://localhost:8080/Camagru/email_r/email.php"><p><u>Click here</u></p></A>
			</form>
			<hr>
			<p style="text-align: center"><u>New User?</u></p>
			<A href="http://localhost:8080/Camagru/new_user/new.php"><p><u>Click here</u></p></A>
		</DIV>
	</div>
	<footer id="footer">
		<p>&copy; Terms and conditions apply.<br>cosincla2018.</p>
	</footer>
</body>
</html>