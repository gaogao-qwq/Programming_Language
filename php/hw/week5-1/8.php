<?php
$hobbies = ["r" => "running", "f" => "fishing", "c" => "cooking"];
foreach ($hobbies as $key => &$value) {
  $value = "I like ".$value;
}
print_r($hobbies);
?>
