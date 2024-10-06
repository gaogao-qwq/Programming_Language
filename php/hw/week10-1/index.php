<!DOCTYPE html>
<html lang="en">

<head>
  <meta charset="UTF-8">
  <meta name="viewport" content="width=device-width, initial-scale=1.0">
  <title>浏览全部图书信息</title>
  <link rel="stylesheet" type="text/css" href="./css/mystyle.css">
</head>

<body>
  <center>
    <table width="1452" border="0" cellpadding="0" cellsapcing="0">
      <tr>
        <td colspan="9" height="109" background="images/Topbanner.jpg">&nbsp;</td>
      </tr>
      <tr>
        <td colspan="9" height="10">&nbsp;</td>
      </tr>
      <tr>
        <td whidth="10%" align="center" valign="middle">
          <b><?php echo date("Y-m-d"); ?></b>
        </td>
        <td whidth="10%" align="center" valign="middle">
          <a href="" class="a"> 浏览全部</a>
        </td>
        <td whidth="10%" align="center" valign="middle">
          <a href="add_book.php">添加图书</a>
        </td>
        <td whidth="15%" align="center" valign="middle">
          <a href="search1.php">精确查询（按图书编号）</a>
        </td>
        <td whidth="15%" align="center" valign="middle">
          <a href="search2.php">模糊查询（按图书书名）</a>
        </td>
        <td whidth="10%" align="center" valign="middle">
          <a href="searchedit.php">图书信息修改</a>
        </td>
        <td whidth="10%" align="center" valign="middle">
          <a href="seachdel.php">删除图书</a>
        </td>
        <td whidth="10%" align="center" valign="middle">
          <a href="#">统计</a>
        </td>
        <td whidth="10%" align="center" valign="middle">
          <a href="#">退出系统</a>
        </td>
      </tr>
      <tr>
        <td colspan="9" height="10">&nbsp;</td>
      </tr>
      <tr>
        <td colspan="9" height="10" align="center">
          <h1>浏览全部图书信息</h1>
        </td>
      </tr>
      <tr>
        <td colspan="9" height="10">&nbsp;</td>
      </tr>
    </table>
    <table width="1452" border="200" cellpadding="0" cellspacing="0">
      <tr>
        <td align="center" valign="middle">
          <?php
          include_once("./conn/conn.php")
          ?>
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
            </tr>
            <?php
            $pageSize = 6;
            $sqlstr = "select * from books order by bookid;";
            $total = mysqli_query($conn, $sqlstr);
            $totalNum = mysqli_num_rows($total);
            $pageCount = ceil($totalNum / $pageSize);
            !isset($_GET["page"]) ? $page = 1 : $page = $_GET["page"];
            $page <= $pageCount ? $page : $page = $pageCount;
            $firstPageNum = $pageSize * ($page - 1);
            $sqlstr = "select * from books order by bookid limit " . $firstPageNum . "," . $pageSize;
            $result = mysqli_query($conn, $sqlstr);
            while ($rows = mysqli_fetch_array($result)) {
            ?>
              <tr>
                <td width="10%" height="25" align="center" bgcolor="#ffffff"><?php echo $rows["bookid"]; ?></td>
                <td width="10%" align="center" bgcolor="#ffffff"><?php echo $rows["bookname"]; ?></td>
                <td width="10%" align="center" bgcolor="#ffffff"><?php echo $rows["bookprice"]; ?></td>
                <td width="15%" align="center" bgcolor="#ffffff"><?php echo $rows["press"]; ?></td>
                <td width="10%" align="center" bgcolor="#ffffff"><?php echo $rows["writer"]; ?></td>
                <td width="10%" align="center" bgcolor="#ffffff"><?php echo $rows["presstime"]; ?></td>
                <td width="10%" align="center" bgcolor="#ffffff"><?php echo $rows["booktype"]; ?></td>
                <td width="15%" align="center" bgcolor="#ffffff">
                  <?php
                  echo "<a href=editform2.php?bookid=" . $rows[0] . ">修改</a>";
                  echo "<a href=delete2.php?bookid=" . $rows[0] . ">删除</a>";
                  ?>
                </td>
              </tr>
            <?php } ?>
            <tr>
              <td height="25" colspan="8" align="left" bgcolor="#ffffff">&nbsp;&nbsp;
                <?php
                echo "共" . $totalNum . "本图书&nbsp;&nbsp;";
                echo "第" . $page . "页/共" . $pageCount . "页&nbsp;&nbsp;";
                if ($page != 1) {
                  echo "<a href='?page=1'>首页</a>&nbsp;";
                  echo "<a href='?page=" . ($page - 1) . "'>上一页</a>&nbsp;";
                } else {
                  echo "首页&nbsp;上一页&nbsp;&nbsp;";
                }
                if ($page != $pageCount) {
                  echo "<a href='?page=" . ($page + 1) . "'>下一页</a>&nbsp;";
                  echo "<a href='?page=".$pageCount."'>尾页</a>&nbsp;&nbsp;";
                } else {
                  echo "下一页&nbsp;尾页&nbsp;&nbsp;";
                }
                ?>
              </td>
            </tr>
          </table>
        </td>
      </tr>
    </table>
    <table width="1452" border="0" cellpadding="0" cellspacing="0">
      <tr>
        <td height="8">&nbsp;</td>
      </tr>
      <tr>
        <td height="64" background="images/bottombanner.jpg">&nbsp;</td>
      </tr>
    </table>
  </center>
</body>

</html>
