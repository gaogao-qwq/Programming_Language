<?php
function example(int &$num) {
  $num = $num * 5 + 10;
  echo "Inside function:\$num=$num\n";
}
$num = 1;
example($num);
echo "Outside function:\$num=$num\n";
?>
