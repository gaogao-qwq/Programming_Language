<?php
$link = mysqli_connect("localhost", "root", "root");
if (!$link) exit(mysqli_connect_error());
mysqli_query($link, "use `ustb`;");

$username = isset($_POST["username"]) ? trim($_POST["username"]) : "";
$password = isset($_POST["password"]) ? trim($_POST["password"]) : "";
$repassword = isset($_POST["repassword"]) ? trim($_POST["repassword"]) : "";
$email = isset($_POST["email"]) ? trim($_POST["email"]) : "";

if ($username == "" || $password == "" || $repassword == "" || $email == "") die("字段不能为空");
if ($password != $repassword) die("密码输入不一致");

$username = mysqli_real_escape_string($link, $username);
$username = mysqli_real_escape_string($link, $email);
$res = mysqli_query($link, "select `password` from `user` where `username` = '$username';");
if ($emp = mysqli_fetch_assoc($res)) {
  echo "用户名已存在";
  header("refresh:2;url=register_html.php");
}

$res = mysqli_query($link, "insert into `user` (`username`, `password`, `email`)
  values ('$username', '$password', '$email');");
if ($res) {
  echo "注册成功";
  echo "请<a href='login_html.php'>登录</a>";
}
