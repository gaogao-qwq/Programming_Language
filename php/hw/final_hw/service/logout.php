<?php
include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/error_code.php");
session_start();
session_destroy();
setcookie(session_name(), "", 1);
header("location:../page/login.php?error=" . ErrorCode::Success->value);
exit;
