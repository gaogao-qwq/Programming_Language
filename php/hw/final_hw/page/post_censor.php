<?php
  include_once($_SERVER["DOCUMENT_ROOT"] . "/database/user.php");
  if (!$is_admin) {
    header("location:../index.php?error=" . ErrorCode::InvalidRequest->value);
  }
?>
<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 审核</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
</head>

<body>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/nav_bar.php"); ?>
  <div class="d-flex flex-nowrap">
    <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/side_bar.php"); ?>
    <div class="container-xxl mt-4">
      <div class="list-group">
        <?php
          $res = mysqli_query($conn, <<<EOT
            select p.id,
                p.title,
                u.name as author,
                p.content,
                p.create_date
            from `post` p
                join `user` u on p.user_id = u.id
            where p.status = 0
            order by p.create_date desc;
          EOT);
          if ($res->num_rows == 0) {
          ?>
            <div class="fw-bold h3">🤷没有待审核的帖子</div>
          <?php
            return;
          }
          while ($row = mysqli_fetch_assoc($res)) {
        ?>
        <div class="list-group-item">
          <div class="ms-2 me-auto">
            <div class="fw-bold mb-2"><?php echo $row["title"] ?></div>
            <div class="mb-2"><?php echo $row["content"] ?></div>
            <div class="row mb-2">
              <div class="col align-self-start text-start">
                <i class="bi bi-person-fill"></i>
                发帖人：<?php echo $row["author"] ?>
              </div>
              <div class="col align-self-end text-end">
                <i class="bi bi-calendar-fill"></i>
                发帖日期：<?php echo $row["create_date"] ?>
              </div>
            </div>
          </div>
        </div>
        <div class="d-grid gap-2 d-md-flex justify-content-md-end list-group-item">
          <a href="<?php echo "../service/censor_post.php?id={$row["id"]}" ?>"
              class="btn btn-success" role="button">通过</a>
          <a href="<?php echo "../service/delete_post.php?id={$row["id"]}" ?>"
              class="btn btn-danger" role="button">删除</a>
        </div>
        <?php } ?>
      </div>
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
