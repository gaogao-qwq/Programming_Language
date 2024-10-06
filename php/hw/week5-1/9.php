<?php
$hobbies = ["r" => "running", "f" => "fishing", "c" => "cooking"];
foreach ($hobbies as $value) {
  echo $value."<br>\n";
}
foreach ($hobbies as $key => $value) {
  echo $key."==>".$value."<br>\n";
}
?>
