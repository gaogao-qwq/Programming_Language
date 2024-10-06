<?php
$sum = 0;
$i = 1;
do {
  if ($i & 1) {
    $sum += $i;
  }
  ++$i;
} while($i <= 100);
echo $sum;
?>
