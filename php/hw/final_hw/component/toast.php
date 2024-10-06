<?php
  $relative_path = $_SERVER["REQUEST_URI"];
  include_once($_SERVER["DOCUMENT_ROOT"] . "/enum/error_code.php");
?>
<div class="toast-container mt-2 top-0 start-50 translate-middle-x">
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
