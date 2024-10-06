<!doctype html>
<html lang="en" data-bs-theme="dark">

<head>
  <meta charset="utf-8">
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <title>G岛匿名版 - 帖子</title>
  <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/css/bootstrap.min.css" rel="stylesheet">
  <link href="https://cdn.jsdelivr.net/npm/bootstrap-icons@1.11.3/font/bootstrap-icons.min.css" rel="stylesheet">
</head>

<body>
  <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/nav_bar.php"); ?>
  <div class="d-flex flex-nowrap">
    <?php include_once($_SERVER["DOCUMENT_ROOT"] . "/component/side_bar.php"); ?>
    <?php
      $post_id = $_GET["id"];
      if (empty($post_id)) {
        header("location:../index.php?error=" . ErrorCode::InvalidPost->value);
        return;
      }
      $res = mysqli_query($conn, <<<EOT
        select p.title,
            u.name as author,
            p.content,
            p.update_date
        from `post` p
            join `user` u on p.user_id = u.id
        where p.id = $post_id;
      EOT);
      $row = $res->fetch_assoc();
    ?>
    <div class="container-xxl mt-4">
      <div class="card mb-4">
        <div class="card-header"><?php echo $row["title"]; ?></div>
        <div class="card-body">
          <p class="mb-0 fw-bold"><i class="bi bi-person-fill me-1"></i><?php echo $row["author"]; ?></p>
          <p class="small"><i class="bi bi-calendar-fill me-1"></i><?php echo $row["update_date"] ?></p>
          <p class="card-text"><?php echo $row["content"]; ?></p>
        </div>
      </div>
      <div class="list-group">
        <?php
          $res = mysqli_query($conn, <<<EOT
            select r.id,
                r.content,
                u.name as author
            from `post` p
                join `reply` r on r.post_id = p.id
                join `user` u on r.user_id = u.id
            where p.id = $post_id
            order by r.create_date;
          EOT);
          if ($res->num_rows == 0) {
        ?>
          <div class="fw-bold h3 mt-4 mb-4">🤷还没有评论</div>
        <?php
          } else {
            while($row = mysqli_fetch_assoc($res)) {
        ?>
          <div class="list-group-item">
            <div class="ms-2 me-auto">
              <div class="fw-bold mb-2"><?php echo $row["author"] ?></div>
              <div class="mb-2"><?php echo $row["content"] ?></div>
            </div>
          </div>
        <?php }} ?>
      </div>
      <div class="card mt-4">
        <div class="card-header">发表评论</div>
        <div class="card-body">
          <form id="login-form" method="post" action="../service/reply.php?post_id=<?php echo $post_id; ?>">
            <div class="mb-3">
              <textarea type="text" class="form-control" name="content" rows="3" required></textarea>
            </div>
            <button type="submit" class="btn btn-primary">发布</button>
          </form>
        </div>
      </div>
    </div>
  </div>
  <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.3/dist/js/bootstrap.bundle.min.js"></script>
</body>
