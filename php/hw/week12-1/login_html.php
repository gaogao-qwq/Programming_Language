<html>

<head>
  <link href="./css/login_style.css" rel="stylesheet" type="text/css">
</head>

<body>
  <form method="post" action="login.php">
    <table class="logintb">
      <caption>
        <h2>欢迎登录</h2>
      </caption>
      <tr>
        <td class="login_w3">用户名</td>
        <td><input class="login_tex" type="text" name="username" value=""></td>
      </tr>
      <tr>
        <td class="login_w2">密码</td>
        <td><input class="login_tex" type="password" name="password" value=""></td>
      </tr>
      <tr>
        <td><input type="submit" value="登陆"></td>
        <td><input type="reset" value="重新填写"></td>
      </tr>
    </table>
    <?php
    if (!empty($_GET['error']) && $_GET['error'] == 1) {
      echo "<font color='red'>密码错误，请重新输入！</font>";
    } elseif (!empty($_GET['error']) && $_GET['error'] == 2) {
      echo "<font color='red'>该账号不存在！</font>";
    }
    ?>
  </form>
</body>

</html>
