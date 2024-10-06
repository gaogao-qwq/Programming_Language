<?php
enum ErrorCode: int {
  case Success = 0;
  case InvalidRequest = 1;
  case InvalidUser = 2;
  case InvalidUsername = 3;
  case InvalidPassword = 4;
  case InvalidSession = 5;
  case ExistUsername = 6;
  case RegistrationFailed = 7;
  case UpdateFailed = 8;
  case DeleteFailed = 9;
  case PostFailed = 10;
  case InvalidPost = 11;
  case ReplyFailed = 12;
};

$error_msg = "";
if (empty($_GET["error"])) {
  return;
}

$error_code = intval($_GET["error"]);
switch ($error_code) {
case ErrorCode::Success->value:
  $error_msg = "操作成功";
  break;
case ErrorCode::InvalidRequest->value:
  $error_msg = "非法请求";
  break;
case ErrorCode::InvalidUser:
  $error_msg = "用户不存在";
  break;
case ErrorCode::InvalidUsername->value:
  $error_msg = "用户名不存在";
  break;
case ErrorCode::InvalidPassword->value:
  $error_msg = "密码错误";
  break;
case ErrorCode::InvalidSession->value:
  $error_msg = "会话过期或非法";
  break;
case ErrorCode::ExistUsername->value:
  $error_msg = "用户名已存在";
  break;
case ErrorCode::RegistrationFailed->value:
  $error_msg = "注册失败";
  break;
case ErrorCode::UpdateFailed->value:
  $error_msg = "更新失败";
  break;
case ErrorCode::DeleteFailed->value:
  $error_msg = "删除失败";
  break;
case ErrorCode::PostFailed->value:
  $error_msg = "发帖失败";
  break;
case ErrorCode::InvalidPost->value:
  $error_msg = "帖子不存在";
  break;
case ErrorCode::ReplyFailed->value:
  $error_msg = "评论失败";
  break;
}
