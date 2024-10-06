<!DOCTYPE html>
<html>
  <body>
    <?php
    // null type
    static $null_var;   # uninitialized variable will be null type variable
    var_dump($null_var);

    // bool type
    $var_bool = true;
    var_dump($var_bool);
    /**
     * When converting to bool, the following values are considered false:
     * the boolean false itself
     * the integer 0 (zero)
     * the floats 0.0 and -0.0 (zero)
     * the empty string "", and the string "0"
     * an array with zero elements
     * the unit type NULL (including unset variables)
     * Internal objects that overload their casting behaviour to bool. For example: SimpleXML objects created from empty elements without attributes.
     * Every other value is considered true (including resource and NAN).
     */
    var_dump((bool) "0", (bool) null, (bool) 0, (bool) 0.0, (bool) array());
    echo "<br/>";

    // int type
    $var_int = 0xffffffff;
    var_dump($var_int);

    // float type
    $var_float = 3.1415926;
    var_dump($var_float);

    // No int division operator in PHP!
    var_dump(25 / 7);           # float instead if floor int
    var_dump(intdiv(25, 7));    # intdiv() will round it towards zero
    var_dump((int) (25 / 7));   # cast float to int also round it towards zero
    var_dump(round(25 / 7));    # round() provides finer control over rounding

    // PHP typically uses the IEEE 754 double precision.
    // So never trust floating number results to the last digit,
    // and do not compare floating point numbers directly for equality.
    $var_float_a = 0.1 + 0.2;   # float(0.30000000000000004) instaed of float(0.3)
    var_dump($var_float_a);
    
    ?>
  </body>
</html>
