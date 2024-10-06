<strong>九九乘法表</strong>
<br/>
<table border="1">
<?php
  for ($i = 1; $i <= 9; ++$i) {
    echo "<tr>";
    for ($j = $i; $j <= 9; ++$j) {
      echo "<td align='center'>";
      echo "$i x $j = " . $i * $j;
      echo "</td>";
    }
  }
?>
</table>
