<?php
function fact(int $num) {
  $res = $num;
  for ($i = 2; $i < $num; ++$i) {
    $res *= $i;
  }
  return $res;
}

$sum = 0;
for ($i = 1; $i < 10; ++$i) {
  $sum += fact($i);
}
echo $sum;
?>
