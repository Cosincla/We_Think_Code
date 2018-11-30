<?php

ini_set('display_errors', 1);
ini_set('display_startup_errors', 1);
error_reporting(E_ALL);

require_once($_SERVER['DOCUMENT_ROOT'].'/Camagru/config/database.php');

try {    
    $sql = "CREATE DATABASE IF NOT EXISTS `cosincla_camagru`;";
    $conn->exec($sql);

    $sql = "CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`users`(
        id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
        `name` VARCHAR(191) NOT NULL,
        surname VARCHAR(191) NOT NULL,
        username VARCHAR(20) UNIQUE NOT NULL,
        `password` CHAR(128) NOT NULL,
        email VARCHAR(191) UNIQUE NOT NULL,
        email_on_comment TINYINT(1) NOT NULL DEFAULT 0,
        validated TINYINT(1) NOT NULL DEFAULT 0
    );";
    $conn->exec($sql);

    $sql = "CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`profile_photos`(
        id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
        `user_id` VARCHAR(20) NOT NULL,
        selected TINYINT(1) NOT NULL DEFAULT 0
    );";
    $conn->exec($sql);
    
    $sql = "CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`uploads`(
        id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
        image_creator VARCHAR(20) NOT NULL,
        image_id VARCHAR(191) NOT NULL,
        date_created TIMESTAMP DEFAULT CURRENT_TIMESTAMP NOT NULL
    );";
    $conn->exec($sql);

    $sql = "CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`likes`(
        image_creator VARCHAR(20) NOT NULL,
        image_id VARCHAR(191) NOT NULL,
        like_id VARCHAR(20) PRIMARY KEY NOT NULL,
        `like` TINYINT(1) NOT NULL
    );";
    $conn->exec($sql);

    $sql = "CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`comments`(
        id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
        image_id VARCHAR(191) NOT NULL,
        image_creator VARCHAR(20) NOT NULL,
        `comment` VARCHAR(200) NOT NULL,
        commenter VARCHAR(20) NOT NULL
    );";
    $conn->exec($sql);

    $sql = "CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`verification`(
        id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
        `user_id` VARCHAR(191) NOT NULL,
        `unlock` VARCHAR(20) NOT NULL
    );";
    $conn->exec($sql);
}
catch(PDOexception $e) {
    echo "Connection failed: " . $e->getMessage();
}
?>