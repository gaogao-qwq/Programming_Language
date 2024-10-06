<?php
$res = 0;
$sum = 1;
for ($i = 1; $i <= 6; ++$i) {
  $sum *= $i;
  $res += $sum;
}
echo $res;
?>
