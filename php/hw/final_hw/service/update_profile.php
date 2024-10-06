<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/user.php");

$username = $_SESSION["name"];
$newUsername = isset($_POST["username"]) ? trim($_POST["username"]) : "";
$password = isset($_POST["password"]) ? trim($_POST["password"]) : "";
$newPassword = isset($_POST["newPassword"]) ? trim($_POST["newPassword"]) : "";

$res = mysqli_query($conn, "select * from `user` where `username` = '$newUsername'");
if ($res) {
  header("location:../page/profile.php?error=" . ErrorCode::ExistUsername->value);
  exit;
}

$res = mysqli_query($conn, "select * from `user` where `username` = '$username'");
$row = mysqli_fetch_assoc($res);
if (!$row) {
  header("location:../page/profile.php?error=" . ErrorCode::InvalidUser->value);
  exit;
}

if ($password != $row("password")) {
  header("location:../page/profile.php?error=" . ErrorCode::InvalidPassword->value);
  exit;
}

$id = $row["id"];
if (!empty($newUsername)) {
  $res = mysqli_query($conn, "update `user` u set u.name = '$newUsername' where u.id = '$id'");
}
if (!empty($newPassword)) {
  $res = mysqli_query($conn, "update `user` u set u.password = '$newPassword' where u.id = '$id'");
}
header("location:../page/profile.php");
