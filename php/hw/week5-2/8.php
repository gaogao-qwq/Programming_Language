<?php
$product = array(
  array ("新想手机","N95","2300","黑色"),
  array("飞人U盘","80G","80","金钻灰"),
  array("达人MP5","N203","398","经典黑"),
  array("小鸟游戏盘","愤怒版","30","包装")
);
?>

<table border="1">
  <tr>
    <td>编号</td>
    <td>商品名称</td>
    <td>型号</td>
    <td>价格</td>
    <td>备注</td>
  </tr>
<?php
for ($i = 0; $i < count($product); ++$i) {
  echo "<tr>";
  echo "<td>".$i."</td>";
  echo "<td>".$product[$i]['0']."</td>";
  echo "<td>".$product[$i]['1']."</td>";
  echo "<td>".$product[$i]['2']."</td>";
  echo "<td>".$product[$i]['3']."</td>";
  echo "</tr>";
}
?>
