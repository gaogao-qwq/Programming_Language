<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/error_code.php");
session_start();
$username = $_SESSION["name"];
if (empty($username)) {
  header("location:../page/login.php?error=" . ErrorCode::InvalidSession->value);
  return;
}

include_once($_SERVER["DOCUMENT_ROOT"] . "/database/conn.php");
$res = mysqli_query($conn, <<<EOT
  select r.name as role_name
  from `user` u
      join `role` r on r.id = u.role_id
  where u.name = '$username';
EOT);
$row = mysqli_fetch_assoc($res);
$is_admin = $row["role_name"] == "admin";
