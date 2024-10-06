



<?php
echo 8%(-3);
$a = true;
$b = false;
$c = "100abc";
$d = "abc100";
$e = 100;
$f = 0;
var_dump($a + $e);
echo ($a + $e)."<br>";
var_dump($b + $e);
echo ($b + $e)."<br>";
var_dump($c + $e);
echo ($c + $e)."<br>"; # E_WARNING
# var_dump($d + $e); TypeError
var_dump((int)$d + $e);
# echo ($d + $e)."<br>"; TypeError
echo ((int)$d + $e)."<br>";
var_dump($a . $e);
echo ($a . $e)."<br>";
var_dump($a && $e);
echo ($a && $e)."<br>";
?>
