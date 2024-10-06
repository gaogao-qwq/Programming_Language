<?php
header('content-type:text/html;charset=utf-8');
require 'public_func.php';
$link = dbInitial();

//分页
//$sql="select * from `user` limit $lim,$page_size";
$sql = "select * from `user` limit 0,5";
// $sql="select * from `user` limit 5,5";
// $sql="select * from `user` limit 10,5";
// $sql="select * from `user` limit 15,5";
$emp = fetchAll($link, $sql);

?>
<html>

<head>
  <link href="css/type.css" rel="stylesheet" type="text/css">
</head>

<body>
  <div class="zi">
    <h2>员工信息列表</h2>
  </div>
  <div class="zi">
    <h2><a href="add_html.php">添加员工</a></h2>
  </div>

  <table class="borderd">
    <tr>
      <td>编号</td>
      <td>姓名</td>
      <td>部门</td>
      <td>专业</td>
      <td>操作</td>
    </tr>
    <?php if (!empty($emp)) { ?>
      <?php foreach ($emp as $value) : ?>
        <tr>
          <td><?php echo $value['id']; ?></td>
          <td><?php echo $value['name']; ?></td>
          <td><?php echo $value['department']; ?></td>
          <td><?php echo $value['major']; ?></td>
          <td><img src="img/edt.gif"><a href="update.php?id=<?php echo $value['id']; ?>">编辑</a>&nbsp;&nbsp;&nbsp;&nbsp;<img src="img/del.gif">删除</td>
        </tr>
      <?php endforeach; ?>
    <?php } else { ?>
      <tr>
        <td colspan="5">暂无员工信息！</td>
      </tr>
    <?php } ?>
  </table>



</body>

</html>
