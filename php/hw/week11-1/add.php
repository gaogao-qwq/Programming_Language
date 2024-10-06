<?php
if (session_id() == "") {
  session_start();
}
$pid = $_GET["pid"] ?? 1;
$products = $_SESSION["products"];
$products[$pid] = $pid;
$_SESSION["products"] = $products;
header("Location:cart.php");
