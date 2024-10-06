<html>

<head>
  <link href="./css/login_style.css" rel="stylesheet" type="text/css">
</head>

<body>
  <form method="post" action="register.php">
    <table class="borderd">
      <caption>
        <h2>欢迎注册新用户</h2>
      </caption>
      <tr>
        <td class="w3">用户名</td>
        <td><input class="tex" type="text" name="username"></td>
      </tr>
      <tr>
        <td class="w2">密码</td>
        <td><input class="tex" type="password" name="password"></td>
      </tr>
      <tr>
        <td>确认密码</td>
        <td><input class="tex" type="password" name="repassword"></td>
      </tr>
      <tr>
        <td class="w2">邮箱</td>
        <td><input class="tex" type="text" name="email"></td>
      </tr>
      <tr>
        <td><input type="submit" value="提交信息"></td>
        <td><input type="reset" value="重新填写"></td>
      </tr>
    </table>
  </form>
</body>

</html>
