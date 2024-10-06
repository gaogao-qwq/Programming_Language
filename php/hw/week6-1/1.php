<?php
function nine_func() {
  echo "<table border=1>";
  for ($i = 1; $i <= 9; ++$i) {
    echo "<tr>";
    for ($j = $i; $j <= 9; ++$j) {
      echo "<td align='center'>";
      echo $i."x".$j."=".$i*$j;
      echo "</td>";
    }
    echo "</tr>";
  }
  echo "</table>";
}
?>
