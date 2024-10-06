<html>
<body>
<?php
  $arr = array("2 cny", "100 cny", "500cny", "1888 cny",
    "5888cny", "18888 cny", "58888 cny", "188888 cny",
    "588888 cny", "2888888 cny");
  echo "pool: ";
  print_r($arr);
  echo "<br/>";
  $idx = rand(min: 0, max: 9);
  echo "Congratulations, You got: ".$arr[$idx];
?>
</body>
</html>
