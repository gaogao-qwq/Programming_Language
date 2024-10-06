<?php
require_once 'public_func.php';
$link = dbInitial();
//接收id
$id = isset($_GET['id']) ? $_GET['id'] : '';
if ($id == '') die('无参数传递');
if (!empty($_POST)) {
  //接收数据，update_html中用户修改的数据
  $name = isset($_POST['name']) ? $_POST['name'] : '';
  $dep = isset($_POST['dep']) ? $_POST['dep'] : '';
  $major = isset($_POST['major']) ? $_POST['major'] : '';
  if (($name == '') || ($dep == '') || ($major == '')) die('字段不能为空！');

  //安全过滤
  $name = safeHandle($link, $name);
  $dep = safeHandle($link, $dep);
  $major = safeHandle($link, $major);

  //sql语句
  $sql = "update `basic_info` set `name`='$name',`department`='$dep',`major`='$major' where `id`='$id'";
  //执行
  if ($res = query($link, $sql)) {
    header('Location:index.php');
  } else {
    die('修改信息失败');
  }
}
require 'update_html.php';
