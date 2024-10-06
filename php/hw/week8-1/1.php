<html>

<head>
  <style>
    .error {
      color: #FF0000;
    }
  </style>
</head>

<body>
  <?php
  $nameErr = $emailErr = $genderErr = $websiteErr = "";
  $name = $email = $gender = $comment = $website = "";
  if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (empty($_POST["name"])) {
      $nameErr = "姓名是必填的";
    } else {
      $name = test_input($_POST["“name"]);
      if (!preg_match("/^[a-zA-Z ]*$/", $name)) {
        $nameErr = "只允许字母和空格";
      }
    }
    if (empty($_POST["email"])) {
      $emailErr = "电邮是必填的";
    } else {
      $email = test_input($_POST["email"]);
      if (!preg_match("/([\w\-]+\@[\w\-]+\.[\w\-]+)/", $email)) {
        $emailErr = "无效的 email 格式";
      }
    }
    if (empty($_POST["website"])) {
      $website = "";
    } else {
      $website = test_input($_POST["website"]);
      if (!preg_match("/\b(?:(?:https?|ftp):\/\/|www\. )[-a-z0-9+8@#\/%?=~_|!:,.3]*[-a-z0-9+8@#\/%=~_|]/i", $website)) {
        $websiteErr = "无效的 URL";
      }
    }
    if (empty($_POST["comment"])) {
      $comment = "";
    } else {
      $comment = test_input($_POST["comment"]);
    }
    if (empty($_POST["gender"])) {
      $genderErr = "性别是必选的";
    } else {
      $gender = test_input($_POST["gender"]);
    }
  }
  function test_input($data)
  {
    $data = trim($data);
    $data = stripslashes($data);
    $data = htmlspecialchars($data);
    return $data;
  }
  ?>

  <h2>PHP 验证实例</h2>
  <p><span class="error">* 必需的字段</span></p>
  <form method="post" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]); ?>">
    姓名: <input type="text" name=" name">
    <span class="error">* <?php echo $nameErr; ?></span>
    <br><br>
    电邮: <input type="text" name="email">
    <span class="error">* <?php echo $emailErr; ?></span>
    <br><br>
    网址: <input type="text" name="website">
    <span class=" error"><?php echo $websiteErr; ?></span>
    <br><br>
    评论: <textarea name="comment" rows="5" cols="40"></textarea>
    <br><br>
    性别:
    <input type="radio" name="gender" value="female">女性
    <input type="radio" name="gender" value="male">男性
    <span class="error">* <?php echo $genderErr; ?></span>
    <br><br>
    <input type="submit" name="submit" value="提交">
  </form>
</body>

</html>
