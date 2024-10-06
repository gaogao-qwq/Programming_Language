<?php
$link = mysqli_connect("localhost", "root", "root");
if (!$link) exit(mysqli_connect_error());
mysqli_query($link, "use `ustb`;");

if (!$_POST) {
  header("location:login_html.php?error=2");
}

$username = isset($_POST["username"]) ? trim($_POST["username"]) : "";
$password = isset($_POST["password"]) ? trim($_POST["password"]) : "";

$username = mysqli_real_escape_string($link, $username);
$res = mysqli_query($link, "select `password` from `user` where `username` = '$username';");
if ($row = mysqli_fetch_assoc($res)) {
  if ($password == $row["password"]) {
    session_start();
    $_SESSION["name"] = $username;
    echo "登录成功，正在跳转...";
    header("refresh:2;url=index_show.php");
  } else {
    header("location:login_html.php?error=1");
  }
}

