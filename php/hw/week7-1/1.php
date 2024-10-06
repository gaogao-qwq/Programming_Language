<?php
class Circle {
  private $radius = 0;

  function __construct(float $radius) {
    $this->radius = $radius;
  }

  function getPerimeter() {
    return 2 * pi() * $this->radius;
  }

  function getArea() {
    return pi() * pow($this->radius, 2);
  }
}

$circle = new Circle(3);
echo $circle->getPerimeter()."\n".$circle->getArea();
?>
