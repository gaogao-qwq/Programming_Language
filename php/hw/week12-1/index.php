<?php
session_start();
if (isset($_session["name"])) {
  header("refresh:1;url=index_show.php");
} else {
  echo "您还未登录。请先<a href='register_html.php'>注册</a>或<a href='login_html.php'>登录</a>";
}
