<?php
$hobbies = ["r" => "running", "f" => "fishing", "c" => "cooking"];
do {
  $key = key($hobbies);
  $value = current($hobbies);
  echo $key."==>".$value."<br>";
} while(next($hobbies));
?>
