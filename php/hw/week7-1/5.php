<?php
function func1() {
  static $num = 0;
  ++$num;
  echo "$num ";
}

function func2() {
  $num = 0;
  ++$num;
  echo "$num ";
}

for ($i = 0; $i < 10; ++$i) {
  func1();
}
echo "\n";
for ($i = 0; $i < 10; ++$i) {
  func2();
}
?>
