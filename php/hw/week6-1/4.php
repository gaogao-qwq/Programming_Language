<?php
include_once(__DIR__."/1.php");
include_once(__DIR__."/2.php");
include_once(__DIR__."/3.php");

nine_func();
echo "<hr/>";
nine_param_func(opt: "+");
echo "<hr/>";
nine_param_func(opt: "x", border: 2);
echo "<hr/>";
echo $GLOBALS["max_func"]();
echo "<hr/>";
echo $GLOBALS["max_func"](100, 200);
echo "<hr/>";
?>
