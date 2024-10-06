<?php
require_once 'public_func.php';
$link = dbInitial();
$sql = "select `name`,`department`,`major` from `basic_info` where `id`=$id";
$emp = fetchAll($link, $sql);
?>

<html>

<head>
  <meta charset="utf-8">
  <title>添加员工信息</title>
  <link href="css/type.css" rel="stylesheet" type="text/css">
</head>

<body>
  <form method="post" action="">
    <div class="update_biaoti">
      <h2>修改员工信息</h2>
    </div>
    <table class="update_borderd">
      <tr>
        <td>姓名</td>
        <td><input type="text" name="name" value="<?php echo $emp[0]['name']; ?>"></td>
      </tr>
      <tr>
        <td>年龄</td>
        <td><input type="text" name="dep" value="<?php echo $emp[0]['department']; ?>"></td>
      </tr>
      <tr>
        <td>部门</td>
        <td><input type="text" name="major" value="<?php echo $emp[0]['major']; ?>"></td>
      </tr>
      <tr>
        <td><input type="submit" value="提交信息"></td>
        <td><input type="reset" value="重新填写"></td>
      </tr>
    </table>
  </form>
</body>

</html>
