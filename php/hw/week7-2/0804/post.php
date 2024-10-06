<!DOCTYPE html PUBLIC "-//W3C//DTD XHTML 1.0 Transitional//EN" "http://www.w3.org/TR/xhtml1/DTD/xhtml1-transitional.dtd">
<html xmlns="http://www.w3.org/1999/xhtml">

<head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8" />
  <title>输出个人信息</title>
  <style type="text/css">
    <!--
    body,
    td,
    th {
      font-size: 12px;
      padding: 5px;
    }
    -->
  </style>
</head>

<body>
  <table width="501" border="0" align="center" cellspacing="1" bgcolor="#BBBBBB">
    <tr>
      <td height="43" colspan="2" bgcolor="#DDDDDD">
        <font color="#333333" size="+2">您输入的个人资料信息</font>
      </td>
    </tr>
    <tr>
      <td width="104" height="20" align="right" bgcolor="#DDDDDD">姓名：</td>
      <td width="390" height="20" bgcolor="#DDDDDD"><?php echo $_POST['name']; ?></td>
    </tr>
    <tr>
      <td height="20" align="right" bgcolor="#DDDDDD">性别：</td>
      <td height="20" bgcolor="#DDDDDD"><?php echo $_POST['sex']; ?></td>
    </tr>
    <tr>
      <td height="20" align="right" bgcolor="#DDDDDD">出生年月：</td>
      <td height="20" bgcolor="#DDDDDD"><?php echo $_POST['year'] . "年" . $_POST['month'] . "月"; ?></td>
    </tr>
    <tr>
      <td height="20" align="right" bgcolor="#DDDDDD">爱好：</td>
      <td height="20" bgcolor="#DDDDDD">
        <?php
        for ($i = 0; $i < count($_POST['interest']); $i++) {
          echo $_POST['interest'][$i] . "&nbsp;";
        }
        ?></td>
    </tr>
    <tr>
      <td height="20" align="right" bgcolor="#DDDDDD">地址：</td>
      <td height="20" bgcolor="#DDDDDD"><?php echo $_POST['address']; ?></td>
    </tr>
    <tr>
      <td height="20" align="right" bgcolor="#DDDDDD">电话：</td>
      <td height="20" bgcolor="#DDDDDD"><?php echo $_POST['tel']; ?></td>
    </tr>
    <tr>
      <td height="20" align="right" bgcolor="#DDDDDD">qq：</td>
      <td height="20" bgcolor="#DDDDDD"><?php echo $_POST['qq']; ?></td>
    </tr>
    <tr>
      <td height="96" align="right" valign="top" bgcolor="#DDDDDD">自我评价：</td>
      <td height="96" bgcolor="#DDDDDD" valign="top"><?php echo $_POST['comment']; ?></td>
    </tr>
  </table>
</body>

</html>
