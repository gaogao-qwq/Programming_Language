<?php
//连接数据库、设置字符集、选择数据库的函数
function dbInitial()
{
  $link = mysqli_connect('localhost', 'root', 'root');
  if (!$link) die('连接数据库失败。' . mysqli_connect_error());
  mysqli_query($link, 'set names utf8'); //连接数据库时将编码方式转化为utf8，防止数据库乱码。
  mysqli_query($link, 'use `ustb`'); //打开数据库ustb
  return $link;
}

//创建执行sql语句的函数
function query($link, $sql)
{
  $res = mysqli_query($link, $sql);

  if ($res) {
    return $res;
  } else {
    echo '错误的sql语句是：' . $sql;
    echo mysqli_error($link);
    die();
  }
}

//处理结果集的函数。 先执行sql语句，再处理返回的资源
function fetchAll($link, $sql)
{
  if ($result = query($link, $sql)) {
    $emp = array();
    while ($row = mysqli_fetch_assoc($result)) {
      $emp[] = $row;
    }
    //释放结果集资源
    mysqli_free_result($result);
    return $emp;
  } else {

    //执行失败
    return false;
  }
}

//封装处理单条数据的函数
function fetchRow($link, $sql)
{
  if ($result = query($link, $sql)) {
    $row = mysqli_fetch_row($result);
    $row = $row[0];
    return $row;
  } else {
    return false;
  }
}

//封装表单数据安全性过滤的函数
function safeHandle($link, $data)
{
  $data = htmlspecialchars($data);  // 将输入数据中可能存在的html字符进行转义
  $data = mysqli_real_escape_string($link, $data); //转义在sql语句中使用的字符串中的特殊字符转义
  return $data;
}
