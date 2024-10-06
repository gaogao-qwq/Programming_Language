<html>
<body>
<table
  width="580"
  height="180"
  border="0"
  cellpadding="0"
  cellspacing="0"
>
  <tr>
    <td>
      <img src="images/bg.jpg"width="580"height="150">
    </td>
  </tr>
  <tr>
    <td
      height="30"
      align="left"
      bgcolor"#eeefe9"
      class="style1"
    >
      购物车商品信息展示
    </td>
  </tr>
</table>

<?php
$name = array(
  "1" => "品牌笔记本电脑",
  "2" => "高档男士村衫",
  "3" => "品牌3G手机",
  "4" => "高档女士挎包"
);
$price = array(
  "1" => "4998元",
  "2" => "588元",
  "3" => "4666元",
  "4" => "698元"
);
$counts = array(
  "1" => 1,
  "2" => 1,
  "3" => 2,
  "4" => 1
);
echo '
  <table
    width = "580"
    border = "1"
    cellpadding = "1"
    bordercolor = "#ffffff"
    bgcolor = "#ff0000"
  >
    <tr>
      <td width = "145" align = "center" bgcolor = "#ffffff" class = "style1">商品名称</td>
      <td width = "145" align = "center" bgcolor = "#ffffff" class = "style1">价格</td>
      <td width = "145" align = "center" bgcolor = "#ffffff" class = "style1">数量</td>
      <td width = "145" align = "center" bgcolor = "#ffffff" class = "style1">金额</td>
    </tr>';
foreach ($name as $key => $value) {
  echo '
    <tr>
      <td height = "25" align = "center" bgcolor = "#ffffff" class = "style2">'.$value.'</td>
      <td align = "center" bgcolor = "#ffffff" class = "style2">'.$price[$key].'</td>
      <td align = "center" bgcolor = "#ffffff" class = "style2">'.$counts[$key].'</td>
      <td align = "center" bgcolor = "#ffffff" class = "style2">'.$counts[$key] * $price[$key].'</td>
    </tr>';
}
echo "</table>"
?>
</body>
</html>
