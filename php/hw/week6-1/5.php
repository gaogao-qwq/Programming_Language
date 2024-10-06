<?php
  function upload_func($file, $file_path) {
    $error = $file['error'];
    switch ($error) {
    case 0:
      $filename = $file['name'];
      $destination = __DIR__."/../".$file_path."/".$filename;
      move_uploaded_file(from: $file['tmp_name'], to: $destination);
      return 1;
    case 4:
      return 0;
    default:
      return -1;
    }
  }

  ob_clean();
  if (empty($_POST) || !isset($_POST["upload"])) {
    exit("上传文件过大或未通过表单提交");
  }
  $code = upload_func(file: $_FILES['picture'], file_path: "uploads");
  switch ($code) {
  case 0:
    echo "没有选择上传文件";
    break;
  case 1:
    echo "文件上传成功";
    break;
  case 2:
    echo "文件上传失败";
    break;
  }
?>
