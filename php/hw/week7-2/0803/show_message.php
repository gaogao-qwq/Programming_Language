<html>

<head>
  <title>查看消息</title>
  </title>
</head>

<body>
  查看消息
  <table width="560" height="192" border="0" cellpadding="4" cellspacing="1" bordercolor="#ACD2DB" bgcolor="#ACD2DB" class="big_td">
    <tr>
      <td width="100" height="25" align="right" valign="middle" bgcolor="#DEEBEF" scope="col">标题：</td>
      <td height="25" align="left" valign="middle" bgcolor="#DEEBEF" scope="col">&nbsp;&nbsp;<?php echo $_POST["title"]; ?></td>
    </tr>
    <tr>
      <td height="31" align="right" valign="middle" bgcolor="#DEEBEF">类别：</td>
      <td align="left" valign="middle" bgcolor="#DEEBEF">&nbsp;&nbsp;<?php echo $_POST["type"]; ?></td>
    </tr>
    <tr>
      <td height="104" align="right" valign="middle" bgcolor="#DEEBEF">内容：</td>
      <td height="104" align="left" valign="middle" bgcolor="#DEEBEF">&nbsp;&nbsp;<?php echo $_POST["content"]; ?></td>
    </tr>
  </table>
</body>

</html>
