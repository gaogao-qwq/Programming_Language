<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title>无标题文档</title>
  <link rel="stylesheet" type="text/css" href="./css/mystyle.css">
</head>


<body>
  <center>
    <table width="1452" border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td colspan="9" height="109" background="images/Topbanner.jpg">&nbsp;</td>
      </tr>
      <tr>
        <td colspan="9" height="10">&nbsp;</td>
      </tr>
      <tr>

        <td width="10%" align="center" valign="middle">
          <b><?php echo date("Y-m-d"); ?></b>
        </td>
        <td width="10%" align="center" valign="middle"><a href="index.php" class="a">浏览全部</a></td>
        <td width="10%" align="center" valign="middle"><a href="add_book.php">添加图书</a></td>
        <td width="15%" align="center" valign="middle"><a href="search1.php">精确查询（按图书编号）</a></td>
        <td width="15%" align="center" valign="middle"><a href="search2.php">模糊查询（按图书书名）</a></td>
        <td width="10%" align="center" valign="middle"><a href="#">图书信息修改</a></td>
        <td width="10%" align="center" valign="middle"><a href="#">图书删除</a></td>
        <td width="10%" align="center" valign="middle"><a href="#">统计</a></td>
        <td width="10%" align="center" valign="middle"><a href="#">退出系统</a></td>

      </tr>
      <tr>
        <td colspan="9" height="10">&nbsp;</td>
      </tr>
      <tr>
        <td colspan="9" height="10" align="center">
          <h1>查询图书的结果为：</h1>
        </td>
      </tr>
      <tr>
        <td colspan="9" height="10">&nbsp;</td>
      </tr>
    </table>
    <?php include_once("conn/conn.php");
    $sqlstr = "select * from books where bookid = '{$_POST['bookid']}'";
    $result = mysqli_query($conn, $sqlstr);
    if (mysqli_num_rows($result) < 1) {
      echo "<h3 style='text-align: center; color: red; font-size: 12pt'>
        不包含《{$_POST['bookid']}》此图书</h3>
        <br><a href='search.php'>重新查询</a>";
    } else {
      echo '<div style="width: 1452; margin: auto;">
              <table width="100%" border="1" cellpadding="1" cellspacing="1" bordercolor="#ffffff" bgcolor="#cccccc">
                <tr>
                  <td width="10%" align="center">图书编号</td>
                  <td width="20%" align="center">书名</td>
                  <td width="10%" align="center">价格</td>
                  <td width="15%" align="center">出版单位</td>
                  <td width="10%" align="center">编著</td>
                  <td width="10%" align="center">出版时间</td>
                  <td width="10%" align="center">类别</td>
                  <td width="10%" align="center">操作</td>
                </tr>';
      while ($rows = mysqli_fetch_array($result)) {
        echo "<tr>
                <td width=\"10%\" height=\"25\" align=\"center\" bgcolor=\"#ffffff\">{$rows["bookid"]}</td>
                <td width=\"10%\" align=\"center\" bgcolor=\"#ffffff\">{$rows["bookname"]}</td>
                <td width=\"10%\" align=\"center\" bgcolor=\"#ffffff\">{$rows["bookprice"]}</td>
                <td width=\"15%\" align=\"center\" bgcolor=\"#ffffff\">{$rows["press"]}</td>
                <td width=\"10%\" align=\"center\" bgcolor=\"#ffffff\">{$rows["writer"]}</td>
                <td width=\"10%\" align=\"center\" bgcolor=\"#ffffff\">{$rows["presstime"]}</td>
                <td width=\"10%\" align=\"center\" bgcolor=\"#ffffff\">{$rows["booktype"]}</td>
                <td width=\"15%\" align=\"center\" bgcolor=\"#ffffff\">
                  <a href=editform2.php?bookid={$rows[0]}>修改</a>
                  <a href=delete2.php?bookid={$rows[0]}>删除</a>
                </td>
              </tr>";
      }
      echo "</table><br><a href='search1.php'>重新查询</a></div>";
    }
    ?>

</body>

</html>
