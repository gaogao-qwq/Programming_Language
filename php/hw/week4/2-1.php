<?php
if (isset($_GET["score"]) && is_numeric($_GET["score"])) {
  $score = $_GET["score"];
} else {
  http_response_code(404);
  exit();
}
switch ($score) {
  case $score >= 90 && $score <= 100:
    http_response_code(200);
    $grade = "优秀";
    break;
  case $score >= 80 && $score < 90:
    http_response_code(200);
    $grade = "良好";
    break;
  case $score >= 60 && $score < 80:
    http_response_code(200);
    $grade = "及格";
    break;
  case $score < 60:
    http_response_code(200);
    $grade = "不及格";
    break;
  default:
    http_response_code(200);
    $grade = "请输入 0 到 100 的数字";
    break;
}
echo $grade;
?>
