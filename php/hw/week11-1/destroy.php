<?php
if (session_id() == "") {
  session_start();
}
session_destroy();
setcookie(session_name(), "", 1);
