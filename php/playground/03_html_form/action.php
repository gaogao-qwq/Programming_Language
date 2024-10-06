<!DOCTYPE html>
<html>
  <body>
    Hello, <?php echo htmlspecialchars($_POST['name']); ?>.
    You are <?php echo (int)$_POST['name']; ?> years old.
  </body>
</html>
