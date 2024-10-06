<!DOCTYPE html>
<html>
  <head>
    <title>PHP Test</title>
  </head>
  <body>
  <?php echo '<p>Hello World</p>'; ?>
  <?php
  if (str_contains($_SERVER['HTTP_USER_AGENT'], 'Firefix')) {
    echo "<p>You are using Firefox</p>";
  } elseif (str_contains($_SERVER['HTTP_USER_AGENT'], 'Chrome')) {
    echo "<p>You are using Chrome</p>";
  }
  ?>
  <?php phpinfo(); ?>
  </body>
</html>

