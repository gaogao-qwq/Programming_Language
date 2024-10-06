<?php
$sum = 0;
for ($i = 1; $i <= 100; $i++) {
  if (!($i & 1)) {
    continue;
  }
  $sum += $i;
}
echo $sum;
?>
