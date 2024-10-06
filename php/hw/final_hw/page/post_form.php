<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 发帖</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
</head>

<body>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/nav_bar.php"); ?>
  <div class="d-flex flex-nowrap">
    <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/side_bar.php") ?>
    <div class="container-xxl mt-4">
      <div class="card">
        <div class="card-header">发帖</div>
        <div class="card-body">
          <form id="login-form" method="post" action="../service/post.php">
            <div class="mb-3">
              <label for="title" class="form-label">标题</label>
              <input type="text" class="form-control" name="title" required>
            </div>
            <div class="mb-3">
              <label for="content" class="form-label">内容</label>
              <textarea type="text" class="form-control" name="content" rows="3" required></textarea>
            </div>
            <button type="submit" class="btn btn-primary">发帖</button>
          </form>
        </div>
      </div>
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>


