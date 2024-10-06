<!-- When a string needs to be evaluated as number
(e.g. arithmetic operations, int type declaration, etc.)
the following steps are taken to determine the outcome: -->

<!-- 1. If the string is numeric, resolve to an int if the
string is an integer numeric string and fits into the
limits of the int type limits (as defined by PHP_INT_MAX),
otherwise resolve to a float. -->

<!-- 2. If the context allows leading numeric strings and
the string is one, resolve to an int if the leading
part of the string is an integer numeric string and fits
into the limits of the int type limits (as defined by
PHP_INT_MAX), otherwise resolve to a float. Additionally
an error of level E_WARNING is raised. -->

<!-- 3. The string is not numeric, throw a TypeError. -->
<?php
# $a = 3 + "abc10"; TypeError
$a = 3 + (int)"abc10";
$b = 3 + "10abc"; # E_WARNING
# $c = "abc10" + 3; TypeError
$c = (int)"abc10" + 3;
$d = "10abc" + 3; # E_WARNING
$e = 3 + true;
$f = false + "10abc"; # E_WARNING
echo "The result of 3 + 'abc10' is:".$a."<br>";
echo "The result of 3 + '10abc' is:".$b."<br>";
echo "The result of 'abc10' + 3 is:".$c."<br>";
echo "The result of '10abc' + 3 is:".$d."<br>";
echo "The result of 3 + true is:".$e."<br>";
echo "The result of false + '10abc' is:".$f."<br>";
?>
