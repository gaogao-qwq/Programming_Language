<?php
$sum = 0;
$i = 1;
while ($i <= 100) {
  if ($i & 1) {
    $sum += $i;
  }
  ++$i;
}
echo $sum;
?>
