<?php
session_start();
if (isset($_GET["action"]) && $_GET["action"] == "logout") {
  unset($_SESSION["name"]);
  if (empty($_SESSION)) session_destroy();
  header("location:login_html.php");
  die;
}
