<?php
$ip = "192.168.1.2";
$num_str = explode(".", $ip);
$count = count($num_str);
for ($i = 0; $i < $count; ++$i) {
  echo $num_str[$i]."<br>";
}
?>
