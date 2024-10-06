<?php
function nine_param_func($opt, $border = 1) {
  echo "<table border=$border>";
  for ($i = 1; $i <= 9; ++$i) {
    echo "<tr>";
    for ($j = $i; $j <= 9; ++$j) {
      echo "<td align='center'>";
      $exp = match($opt) {
        "+" => $i."+".$j."=".$i+$j,
        "x" => $i."x".$j."=".$i*$j,
      };
      echo $exp;
      echo "</td>";
    }
    echo "</tr>";
  }
  echo "</table>";
}
?>
