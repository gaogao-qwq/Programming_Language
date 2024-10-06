<?php
$n = $_GET["o"] ?? 100;
$sum = 0;
for ($i = 0; $i < $n; ++$i) {
  $sum += $i;
}
echo $sum;
?>
