<?php 
class Person {
  public $name = "张三";
  public $age = 0;
  public $gender = "Male";

  public function talk(): void {
    echo "$this->name 在说话";
  }

  public function walk(): void {
    print("$this->name 在走路");
  }
};


$person = new Person();

print("echo: <br/>");
$person->walk();
print("print: <br/>");
$person->talk();
print("<br/>");
print("print_r: <br/>");
print_r(value: $person);
print("<br/>");
print("var_dump: <br/>");
var_dump($person);
print("<br/>");
print("var_export: <br/>");
var_export(value: $person);
print("<br/>");

?>
