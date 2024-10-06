<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/database/user.php");

$res = mysqli_query($conn, "select u.id from `user` u where u.name = '$username'");
$row = mysqli_fetch_assoc($res);

$title = $_POST["title"];
$content = $_POST["content"];
$user_id = $row["id"];
$create_date = date('Y-m-d H:i:s');
$res = mysqli_query($conn, <<<EOT
  insert into `post` (`title`, `content`, `create_date`, `update_date`, `user_id`)
  values ('$title', '$content', '$create_date', '$create_date', $user_id);
EOT);

if (!$res) {
  header("location:post_form.php?error=" . ErrorCode::PostFailed->value);
} else {
  header("location:../index.php?error=" . ErrorCode::Success->value);
}

