<html>

<head>
  <meta charset="utf-8">
  <title>添加员工信息</title>
  <link href="css/type.css" rel="stylesheet" type="text/css">
</head>

<body>
  <div class="add_container">
    <div class="add_biaoti">
      <h2>添加员工信息</h2>
    </div>
    <form action="add.php" method="post">
      <table class="add_borderd">
        <tr>
          <th>姓名：</th>
          <td><input type="text" name="name"></td>
        </tr>
        <tr>
          <th>部门：</th>
          <td><input type="text" name="dep"></td>
        </tr>
        <tr>
          <th>专业：</th>
          <td><input type="text" name="major"></td>
        </tr>
        <tr>
          <td><input type="submit" value="保存资料"></td>
          <td><input type="reset" value="重新填写"></td>
        </tr>
      </table>
    </form>
  </div>
</body>

</html>
