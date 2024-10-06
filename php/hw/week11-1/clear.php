<?php
if (session_id() == "") {
  session_start();
}
session_unset();
header("Location:cart.php");
