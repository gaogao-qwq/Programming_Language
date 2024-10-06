<?php
$sum = 0;
for ($i = 1;; $i++) {
  if ($i > 100) break;
  if ($i & 1) $sum += $i;
}
echo $sum;
?>
