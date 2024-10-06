<?php
$ip = "192.168.1.2";
$exploded = explode(".", $ip);
$new_ip = implode(";", $exploded);
var_dump($new_ip);
?>
