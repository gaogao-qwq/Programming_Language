<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/database/user.php");

$res = mysqli_query($conn, <<<EOT
  select r.name as role_name
  from `user` u
      join `role` r on r.id = u.role_id
  where u.name = '$username';
EOT);
$row = mysqli_fetch_assoc($res);
if ($row["role_name"] != "admin") {
  header("location:../index.php?error=" . ErrorCode::InvalidRequest->value);
  return;
}

$id = $_GET["id"];
if (empty($id)) {
  header("location:../index.php?error=" . ErrorCode::InvalidRequest->value);
  return;
}

$res = mysqli_query($conn, <<<EOT
  delete
  from `post`
  where `id` = $id;
EOT);
if (!$res) {
  header("location:../index.php?error=" . ErrorCode::DeleteFailed->value);
} else {
  header("location:../index.php?error=" . ErrorCode::Success->value);
}
