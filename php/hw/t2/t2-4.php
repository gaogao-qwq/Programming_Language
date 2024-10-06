


<?php
echo "Print predefined constants: <br>";
echo "Operating system PHP was built for: ".PHP_OS."<br>";
// Hmmm...
echo "Execution operator yas: ".`uname -srmon`."<br>";
echo "The current PHP version: ".PHP_VERSION."<br>";
// Magic constant btw.
echo "The full path and filename of the file with symlinks resolved:".__FILE__."<br>";

define(value: 3.1415826, constant_name: "PI");
echo "Print user-defined constants:<br>";
$r = 20;
$c = 2 * $r * PI;
echo "The circumference of a circle with a radius of $r is: $c<br>";
?>
