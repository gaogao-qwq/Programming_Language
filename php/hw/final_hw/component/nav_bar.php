<nav class="navbar navbar-expand-md bg-body-tertiary justify-content-center sticky-top">
  <div class="container">
    <a href="/" class="navbar-brand d-flex w-50 me-auto">G岛匿名版（伪）</a>
    <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#collapsingNavbar3">
      <span class="navbar-toggler-icon"></span>
    </button>
    <div class="navbar-collapse collapse w-100" id="collapsingNavbar3">
      <ul class="navbar-nav w-100 justify-content-center">
        <form class="d-flex" action="page/search_result.php">
          <input class="form-control me-2" name="search" type="search" placeholder="搜索帖子" aria-label="Search">
          <button class="btn btn-outline-success" type="submit"><i class="bi bi-search"></i></button>
        </form>
      </ul>
      <ul class="nav navbar-nav ms-auto w-100 justify-content-end">
        <li class="nav-item">
          <a class="nav-link" href="/page/inbox.php"><i class="bi bi-inboxes-fill"></i></a>
        </li>
        <li class="nav-item">
          <a class="nav-link" href="/page/profile.php"><i class="bi bi-person-fill"></i></a>
        </li>
        <li class="nav-item dropdown">
          <a class="nav-link dropdown-toggle"
            id="navbarScrollingDropdown"
            role="button"
            data-bs-toggle="dropdown"
            aria-expanded="false"
          >
            <i id="theme-icon" class="bi bi-sun-fill"></i>
          </a>
          <ul class="dropdown-menu dropdown-menu-right" aria-labelledby="navbarScrollingDropdown">
            <li><a id="light-mode-item" class="dropdown-item">光明模式</a></li>
            <li><a id="dark-mode-item" class="dropdown-item">黑暗模式</a></li>
          </ul>
        </li>
      </ul>
    </div>
  </div>
</nav>
<script type="text/javascript">
  const lightModeLink = document.getElementById('light-mode-item');
  const darkModeLink = document.getElementById('dark-mode-item');
  lightModeLink.addEventListener('click', () => onToggleThemeMode(true));
  darkModeLink.addEventListener('click', () => onToggleThemeMode(false));

  function onToggleThemeMode(light) {
    const themeIcon = document.getElementById("theme-icon");
    if (light) {
      document.documentElement.setAttribute('data-bs-theme', 'light');
      themeIcon.classList.remove('bi-moon-stars-fill');
      themeIcon.classList.add('bi-sun-fill');
    } else {
      document.documentElement.setAttribute('data-bs-theme', 'dark');
      themeIcon.classList.remove('bi-sun-fill');
      themeIcon.classList.add('bi-moon-stars-fill');
    }
  }
</script>
