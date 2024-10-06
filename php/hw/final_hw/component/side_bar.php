<?php
  include_once($_SERVER["DOCUMENT_ROOT"] . "/database/user.php");
  $relative_path = $_SERVER["REQUEST_URI"];
  $relative_path = parse_url($relative_path)["path"];
  enum CurrentPage {
    case Index;
    case Inbox;
    case Profile;
    case PostCensor;
    case PostForm;
  };
  switch ($relative_path) {
    case "/index.php":
      $current_page = CurrentPage::Index;
      break;
    case "/page/inbox.php":
      $current_page = CurrentPage::Inbox;
      break;
    case "/page/profile.php":
      $current_page = CurrentPage::Profile;
      break;
    case "/page/post_censor.php":
      $current_page = CurrentPage::PostCensor;
      break;
    case "/page/post_form.php":
      $current_page = CurrentPage::PostForm;
      break;
    default:
      $current_page = CurrentPage::Index;
  }
?>
<div class="d-flex flex-column flex-shrink-0 p-3" style="width: 280px;">
  <ul class="nav nav-pills flex-column mb-auto">
    <li><a href="/" class="nav-link <?php echo $current_page == CurrentPage::Index ? "active" : "" ?>">
        <i class="bi bi-house-door-fill pe-2"></i>主页</a></li>
    <li><a href="/page/inbox.php" class="nav-link <?php echo $current_page == CurrentPage::Inbox ? "active" : "" ?>">
        <i class="bi bi-inbox-fill pe-2"></i>收件箱</a></li>
    <li><a href="/page/profile.php" class="nav-link <?php echo $current_page == CurrentPage::Profile ? "active" : "" ?>">
        <i class="bi bi-person-fill pe-2"></i>个人资料</a></li>
    <hr>
    <?php if ($is_admin) { ?>
    <li><a href="/page/post_censor.php" class="nav-link <?php echo $current_page == CurrentPage::PostCensor ? "active" : "" ?>">
        <i class="bi bi-file-earmark-check-fill pe-2"></i>审核</a></li>
    <?php } ?>
    <li><a href="/page/post_form.php" class="nav-link <?php echo $current_page == CurrentPage::PostForm ? "active" : "" ?>">
        <i class="bi bi-pencil-square pe-2"></i>发帖</a></li>
  </ul>
</div>
