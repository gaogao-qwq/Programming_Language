<?php
  include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/error_code.php");
?>
<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 注册</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
  <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/4.2.0/crypto-js.min.js"></script>
</head>

<body>
  <div class="toast-container top-0 start-50 translate-middle-x">
    <div class="toast align-items-center text-bg-primary border-0 fade"
      id="error-toast"
      role="alert"
      aria-live="assertive"
      aria-atomic="true"
      data-bs-delay="2000"
    >
      <div class="d-flex">
        <div class="toast-body">
          <?php echo isset($error_msg) ? $error_msg : "" ?>
        </div>
        <button type="button"
          class="btn-close btn-close-white me-2 m-auto"
          data-bs-dismiss="toast"
          aria-label="Close"></button>
      </div>
    </div>
  </div>
  <div class="d-flex justify-content-center align-items-center" style="min-height: 100vh;">
    <div class="register-container">
      <div class="card text-center">
        <div class="card-header">注册</div>
        <div class="card-body">
          <form id="register-form" method="post" action="../service/register.php">
            <div class="row mb-3">
              <label for="username" class="col-sm-2 col-form-label">用户名</label>
              <div class="col-sm-10">
                <input type="text" class="form-control" name="username" required>
              </div>
            </div>
            <div class="row mb-3">
              <label for="password" class="col-sm-2 col-form-label">密码</label>
              <div class="col-sm-10">
                <input type="password" class="form-control" name="password" required>
              </div>
            </div>
            <a href="login.php" class="btn btn-secondary">已经有账号？去登录</a>
            <button type="submit" class="btn btn-primary">注册</button>
          </form>
        </div>
      </div>
    </div>
  </div>

  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
  <?php
    if (!empty($error_msg)) {
      echo <<<EOT
      <script type="text/javascript">
        const errorToast = document.getElementById("error-toast");
        bootstrap.Toast.getOrCreateInstance(errorToast).show();
      </script>
      EOT;
    }
  ?>
  <script type="text/javascript">
    const form = document.getElementById("register-form");
    form.addEventListener("submit", (event) => {
      event.preventDefault();
      var password = form.elements.password.value;
      console.log(password);
      form.elements.password.value = CryptoJS.SHA256(password).toString();
      form.submit();
    })
  </script>
</body>

<style>
  .register-container {
    max-width: 550px;
    width: 100%;
    padding-right: 15px;
    padding-left: 15px;
    margin-right: auto;
    margin-left: auto;
  }
</style>

</html>
