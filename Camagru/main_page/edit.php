<?php
$target_dir = "uploads/";
if(isset($_POST["submit"])) {
    $check = getimagesize($_FILES["fileToUpload"]["tmp_name"]);
    if($check !== false) {
       $new_image = "new.png";
        $filename = $_FILES["fileToUpload"]["tmp_name"];
        if (move_uploaded_file($filename, $target_dir.$new_image)) {
          header("Location: Camagru/main_page/mp.php");
        } else {
            echo "Sorry, there was an error uploading your file.";
        }
    } else {
        echo "File is not an image.";
    }
}
?>