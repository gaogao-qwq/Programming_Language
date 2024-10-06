<?php
require_once 'public_func.php';
$link = dbInitial();
//接收id
$id = isset($_GET['id']) ? $_GET['id'] : '';
if ($id == '') die('无参数传递');

//sql语句
$sql = "delete from `basic_info` where `id`='$id'";
//执行
if ($res = query($link, $sql)) {
  header('Location:index.php');
} else {
  die('删除数据失败！');
}
