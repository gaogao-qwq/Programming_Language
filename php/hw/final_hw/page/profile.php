<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 个人资料</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
  <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/4.2.0/crypto-js.min.js"></script>
</head>

<body>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/nav_bar.php"); ?>
  <div class="d-flex flex-nowrap">
    <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/side_bar.php") ?>
    <div class="container-sm mt-5">
      <div class="card">
        <div class="card-header">
          <ul class="nav nav-tabs card-header-tabs" id="profile-tab" role="tablist">
            <li class="nav-item" role="presentation">
              <button class="nav-link active"
                data-bs-toggle="tab"
                type="button"
                role="tab"
                aria-selected="true"
              >更新个人信息</button>
            </li>
            <li class="nav-item" role="presentation">
              <button class="nav-link"
                data-bs-toggle="tab"
                type="button" role="tab"
                aria-selected="false"
              >我的发帖</button>
            </li>
            <li class="nav-item" role="presentation">
              <button class="nav-link"
                data-bs-toggle="tab"
                type="button"
                role="tab"
                aria-selected="false"
              >我的回复</button>
            </li>
          </ul>
        </div>
        <div class="card-body">
          <div class="tab-content">
            <div class="tab-pane fade show active" role="tabpanel" tabindex="0">
              <form id="profile-update-form" method="post" action="../service/update_profile.php">
                <div class="row mb-3">
                  <label for="new-password" class="col-sm-2 col-form-label">新密码</label>
                  <div class="col-sm-10">
                    <input type="text" class="form-control" name="newPassword">
                  </div>
                </div>
                <div class="row mb-3">
                  <label for="password" class="col-sm-2 col-form-label">密码</label>
                  <div class="col-sm-10">
                    <input type="text" class="form-control" name="password" required>
                  </div>
                </div>
                <button type="submit" class="btn btn-primary">更新个人资料</button>
                <a href="../service/logout.php" class="btn btn-danger">登出</a>
              </form>
            </div>
            <div class="tab-pane fade" role="tabpanel" tabindex="0">
              列表
            </div>
            <div class="tab-pane fade" role="tabpanel" tabindex="0">
              列表
            </div>
          </div>
        </div>
      </div>
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
  <script type="text/javascript">
    const form = document.getElementById("profile-update-form");
    form.addEventListener("submit", (event) => {
      event.preventDefault()
      const newPassword = form.elements.newPassword.value;
      const password = form.elements.password.value;
      form.elements.newPassword.value = CryptoJS.SHA256(newPassword).toString();
      form.elements.password.value = CryptoJS.SHA256(password).toString();
      form.submit();
    });
  </script>
</body>
