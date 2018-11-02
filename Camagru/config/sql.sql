CREATE DATABASE IF NOT EXISTS cosincla_camagru; CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`users`(
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `name` VARCHAR(191) NOT NULL,
    surname VARCHAR(191) NOT NULL,
    username VARCHAR(20) UNIQUE NOT NULL,
    `password` CHAR(128) NOT NULL,
    email VARCHAR(191) UNIQUE NOT NULL,
    email_on_comment TINYINT(1) NOT NULL
);
CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`profile_photos`(
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    `user_id` VARCHAR(20) NOT NULL,
    image_id VARCHAR(191) NOT NULL
);
CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`uploads`(
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    image_creator VARCHAR(20) NOT NULL,
    image_id VARCHAR(191) NOT NULL,
    date_created DATE NOT NULL
);
CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`likes`(
    image_creator VARCHAR(20) NOT NULL,
    image_id VARCHAR(191) NOT NULL,
    like_id VARCHAR(20) NOT NULL,
    `like` TINYINT(1) NOT NULL
);
CREATE TABLE IF NOT EXISTS `cosincla_camagru`.`comments`(
    id INT AUTO_INCREMENT PRIMARY KEY NOT NULL,
    image_id VARCHAR(191) NOT NULL,
    image_creator VARCHAR(20) NOT NULL,
    `comment` VARCHAR(200) NOT NULL,
    commenter VARCHAR(20) NOT NULL
);