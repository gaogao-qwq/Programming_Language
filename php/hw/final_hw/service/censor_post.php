<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/database/user.php");
include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/post_status.php");

$id = $_GET["id"];
if (empty($id)) {
  header("location:../page/post_censor.php?error=" . ErrorCode::InvalidRequest->value);
  return;
}

$res = mysqli_query($conn, <<<EOT
  update `post` p
  set p.status = 1
  where p.id = $id;
EOT);
if (!$res) {
  header("location:../page/post_censor.php?error=" . ErrorCode::InvalidRequest->value);
} else {
  header("location:../page/post_censor.php?error=" . ErrorCode::Success->value);
}

