<?php
  switch (date(format: "D")) {
    case 'Mon':
      echo "今天星期一";
      break;
    case 'Tue':
      echo "今天星期二";
      break;
    case 'Wed':
      echo "今天星期三";
      break;
    case 'Thu':
      echo "今天星期四";
      break;
    case 'Fri':
      echo "今天星期五";
      break;
    default:
      echo "今天放假";
      break;
  }
?>
