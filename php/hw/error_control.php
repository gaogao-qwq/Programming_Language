<?php 
fopen(filename: "text.txt", mode: "r") or
  print("Failed opening file and continue: error was '" .
    error_get_last()['message'] . "'");
print("<hr/>");
@fopen(filename: "text.txt", mode: "r") or
  die("Failed opening file and terminate process: error was '" .
    error_get_last()['message'] . "'");
print("<hr/>");
print("This line won't print")
?>
