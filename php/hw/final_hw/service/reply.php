<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/database/user.php");

$res = mysqli_query($conn, "select u.id from `user` u where u.name = '$username'");
$row = mysqli_fetch_assoc($res);

$post_id = $_GET["post_id"];
$content = $_POST["content"];
$user_id = $row["id"];
$create_date = date('Y-m-d H:i:s');
$res = mysqli_query($conn, <<<EOT
  insert into `reply` (content, create_date, update_date, user_id, post_id)
  values ('$content', '$create_date', '$create_date', $user_id, $post_id);
EOT);

if (!$res) {
  header("location:../page/post_detail.php?id=$post_id&error=" . ErrorCode::PostFailed->value);
} else {
  $res = mysqli_query($conn, <<<EOT
    update `post` p set p.update_date = '$create_date';
  EOT);
  header("location:../page/post_detail.php?id=$post_id&error=" . ErrorCode::Success->value);
}
