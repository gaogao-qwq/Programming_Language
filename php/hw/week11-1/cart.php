<?php
if (session_id() == "") {
  session_start();
}
?>
<a href="clear.php">清空购物车</a><br />
<a href="destroy.php">删除Session会话文件和携带SID的Cookie</a><br />
<hr />
商品清单如下：<br />
将商品1<a href="add.php?pid=1">添加到购物车</a><br />
将商品2<a href="add.php?pid=2">添加到购物车</a><br />
将商品3<a href="add.php?pid=3">添加到购物车</a><br />
<hr />
购物车清单如下：<br />
<?php
$products = $_SESSION["products"] ?? [];
foreach ($products as $key => $value) {
  echo "将商品{$value}<a href='remove.php?pid=$key'>移出购物车<a/><br/>";
}
?>
