<?php
if (isset($_GET["score"]) && is_numeric($_GET["score"])) {
  $score = $_GET["score"];
} else {
  http_response_code(404);
  exit();
}
switch ($score / 10) {
  case $score == 100:
  case 9:
    http_response_code(200);
    $grade = "优秀";
    break;
  case 8:
    http_response_code(200);
    $grade = "良好";
    break;
  case 7:
  case 6:
    http_response_code(200);
    $grade = "及格";
    break;
  case 5:
  case 4:
  case 3:
  case 2:
  case 1:
  case 0:
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
