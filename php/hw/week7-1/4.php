<?php
$str1 = "str1";
$str2 = "str2";
function func() {
  $str1 = "str3";
  echo "$str1\n";
  global $str2;
  echo "$str2\n";
}
func();
?>
