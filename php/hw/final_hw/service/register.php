<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/error_code.php");
if (empty($_POST)) {
  header("location:../page/register.php?error=" . ErrorCode::InvalidRequest->value);
}
include_once($_SERVER["DOCUMENT_ROOT"] . "/database/conn.php");

$username = isset($_POST["username"]) ? trim($_POST["username"]) : "";
$password = isset($_POST["password"]) ? trim($_POST["password"]) : "";
$username = mysqli_real_escape_string($conn, $username);
$res = mysqli_query($conn, "select * from `user` where `name` = '$username';");
if (mysqli_fetch_assoc($res)) {
  header("location:../page/register.php?error=" . ErrorCode::ExistUsername->value);
  exit;
}

$create_date = date('Y-m-d H:i:s');
$res = mysqli_query($conn, "insert into `user` (`name`, `password`, `create_date`, `role_id`)
  values ('$username', '$password', '$create_date', 10001);");

if ($res) {
  session_start();
  $_SESSION["name"] = $username;
  header("location:../index.php");
} else {
  header("location:../page/register.php?error=" . ErrorCode::RegistrationFailed->value);
}
