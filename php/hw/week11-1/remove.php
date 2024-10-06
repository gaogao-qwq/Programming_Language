<?php
if (session_id() == "") {
  session_start();
}
$pid = $_GET["pid"] ?? 1;
unset($_SESSION["products"][$pid]);
header("Location:cart.php");
