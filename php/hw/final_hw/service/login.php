<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/error_code.php");
if (!$_POST) {
  header("location:../page/login.php?error=" . ErrorCode::InvalidRequest->value);
}
include_once($_SERVER["DOCUMENT_ROOT"] . "/database/conn.php");

$username = isset($_POST["username"]) ? trim($_POST["username"]) : "";
$password = isset($_POST["password"]) ? trim($_POST["password"]) : "";
$username = mysqli_real_escape_string($conn, $username);
$res = mysqli_query($conn, "select `password` from `user` where `name` = '$username';");

$row = mysqli_fetch_assoc($res);
if (!$row) {
  header("location:../page/login.php?error=" . ErrorCode::InvalidUsername->value);
  exit;
}

if ($password == $row["password"]) {
  session_start();
  $_SESSION["name"] = $username;
  header("location:../index.php");
} else {
  header("location:../page/login.php?error=" . ErrorCode::InvalidPassword->value);
}
exit;
