<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 登录</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
  <script src="https://cdnjs.cloudflare.com/ajax/libs/crypto-js/4.2.0/crypto-js.min.js"></script>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</head>

<body>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/toast.php"); ?>
  <div class="d-flex justify-content-center align-items-center" style="min-height: 100vh;">
    <div class="login-container">
      <div class="card text-center">
        <div class="card-header">登录</div>
        <div class="card-body">
          <form id="login-form" method="post" action="../service/login.php">
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
            <a href="register.php" class="btn btn-secondary">没有账号？去注册</a>
            <button type="submit" class="btn btn-primary">登录</button>
          </form>
        </div>
      </div>
    </div>
  </div>
  <script type="text/javascript">
    const form = document.getElementById("login-form");
    form.addEventListener("submit", (event) => {
      event.preventDefault();
      const password = form.elements.password.value;
      form.elements.password.value = CryptoJS.SHA256(password).toString();
      form.submit();
    })
  </script>
</body>

<style>
  .login-container {
    max-width: 550px;
    width: 100%;
    padding-right: 15px;
    padding-left: 15px;
    margin-right: auto;
    margin-left: auto;
  }
</style>

</html>
