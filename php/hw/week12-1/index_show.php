<?php
require 'public_func.php';
$link = dbInitial();
session_start();
if (!isset($_SESSION["name"])) {
  echo "您还未登录。请先<a href='register_html.php'>注册</a>或<a href='login_html.php'>登录</a>";
  exit();
}

//分页
$page_size = 6;
$sql = "select count(*) from `basic_info`";
$page_count = fetchRow($link, $sql);
$page_num = ceil($page_count / $page_size);
$page = isset($_GET['page']) ? intval($_GET['page']) : 1;
$page = $page > $page_num ? $page_num : $page;
$page = $page < 1 ? 1 : $page;
$lim = ($page - 1) * $page_size;

$sql = "select * from `basic_info` limit $lim,$page_size";
$emp = fetchAll($link, $sql);
?>

<html>

<head>
  <link href="css/type.css" rel="stylesheet" type="text/css">
</head>

<body>
  <div class="hello">欢迎<?php echo $_SESSION["name"]; ?>登录</div>
  <div class="hello"><a href="unlogin.php?action=logout">退出</a></div>
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
          <td><img src="img/edt.gif"><a href="update.php?id=<?php echo $value['id']; ?>">编辑</a>&nbsp;&nbsp;&nbsp;&nbsp;<img src="img/del.gif"><a href="del.php?id=<?php echo $value['id']; ?>">删除</a></td>
        </tr>
      <?php endforeach; ?>
    <?php } else { ?>
      <tr>
        <td colspan="5">暂无员工信息！</td>
      </tr>
    <?php } ?>
  </table>
  <div class="page_style">
    <a href="index.php?page=1">首页</a>
    <a href="index.php?page=<?php echo ($page > 1) ? ($page - 1) : 1; ?>">上一页</a>
    <a href="index.php?page=<?php echo ($page < $page_num) ? ($page + 1) : $page_num; ?>">下一页</a>
    <a href="index.php?page=<?php echo $page_num; ?>">尾页</a>
  </div>
</body>

</html>
