<html>

<head>
  <title>公告信息</title>
</head>

<body>
  <form action="show_message.php" method="post" name="addmess" id="addmess">
    添加信息
    <table width="560" height="180" border="0" cellpadding="4" cellspacing="1" bordercolor="#ACD2DB" bgcolor="#ACD2DB" class="big_td">
      <tr>
        <td width="100" height="25" align="right" valign="middle" bgcolor="#DEEBEF" scope="col">标题：</td>
        <td height="25" align="left" valign="middle" bgcolor="#DEEBEF" scope="col">
          <input type="text" name="title" id="title" />
          &nbsp;
        </td>
      </tr>
      <tr>
        <td align="right" valign="middle" bgcolor="#DEEBEF">内容：</td>
        <td align="left" valign="middle" bgcolor="#DEEBEF">
          <textarea name="content" id="content" cols="56" rows="10"></textarea>
        </td>
      </tr>
      <tr>
        <td height="30" align="right" valign="middle" bgcolor="#DEEBEF">类别：</td>
        <td height="30" align="left" valign="middle" bgcolor="#DEEBEF">
          <select name="type" id="type">
            <option value="企业公告" selected="selected">企业公告</option>
            <option value="活动安排">活动安排</option>
          </select>
        </td>
      </tr>
      <tr>
        <td height="30" colspan="2" align="center" valign="middle" bgcolor="#DEEBEF">
          <input name="submit" type="submit" id="submit" value="发布" />
          &nbsp;
          <input name="submit2" type="reset" id="submit2" value="重置" />
        </td>
      </tr>
    </table>
  </form>
</body>

</html>
