<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 搜索结果</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</head>

<body>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/toast.php"); ?>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/nav_bar.php"); ?>
  <div class="d-flex flex-nowrap">
    <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/side_bar.php"); ?>
    <div class="container-xxl mt-4 mb-4">
      <!-- Start of traversal -->
      <div class="list-group">
        <?php
          $search = $_GET["search"];
          $res = mysqli_query($conn, <<<EOT
            select p.title,
                u.name as author,
                p.id,
                p.create_date,
                p.update_date,
                (select COUNT(*) from `reply` r where r.post_id = p.id) as reply_count
            from `post` p
                join `user` u on p.user_id = u.id
            where p.status = 1
                and p.title like '%$search%'
            order by p.update_date desc;
          EOT);
          while ($row = mysqli_fetch_assoc($res)) {
        ?>
        <a href="<?php echo "page/post_detail.php?id={$row["id"]}" ?>"
            class="list-group-item list-group-item-action">
          <div class="ms-2 me-auto">
            <div class="fw-bold mb-2"><?php echo $row["title"] ?></div>
            <div class="row mb-2">
              <div class="col align-self-start text-start">
                <i class="bi bi-person-fill"></i>
                楼主：<?php echo $row["author"] ?>
              </div>
              <div class="col align-self-start text-center">
                <i class="bi bi-chat-dots-fill"></i>
                回复数：<?php echo $row["reply_count"] ?>
              </div>
              <div class="col align-self-end text-end">
                <i class="bi bi-calendar-fill"></i>
                发帖日期：<?php echo $row["create_date"] ?>
              </div>
              <div class="col align-self-end text-end">
                <i class="bi bi-calendar-fill"></i>
                更新日期：<?php echo $row["update_date"] ?>
              </div>
            </div>
          </div>
        </a>
        <?php
          if ($is_admin) {
        ?>
        <div class="d-grid gap-2 d-md-flex justify-content-md-end list-group-item">
          <a href="<?php echo "service/update_post.php?id={$row["id"]}" ?>"
              class="btn btn-primary" role="button">编辑</a>
          <a href="<?php echo "service/delete_post.php?id={$row["id"]}" ?>"
              class="btn btn-danger" role="button">删除</a>
        </div>
        <?php }} ?>
      </div>
      <!-- End of traversal -->
    </div>
  </div>
</body>

</html>
