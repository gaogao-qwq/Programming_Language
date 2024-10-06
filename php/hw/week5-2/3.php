<?php
$arr = array(
  0 => 'PHP自学视频教程',
  1 => 'JAVA自学视频教程',
  2 => 'VB自学视频教程',
  3 => 'VC自学视频教程');

// each 函数已自 PHP 7.2.0 起被废弃，并自 PHP 8.0.0 起被移除。 强烈建议不要依赖本函数。
// while (list($name, $value) = each($arr)) {
//   echo "$name = $value"."\n";
// }
foreach ($arr as $key => $value) {
  echo "$key = $value"."\n";
}
?>
