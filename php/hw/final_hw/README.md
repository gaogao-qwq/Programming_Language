# README

```text
./
├── component              # 组件
│   ├── nav_bar.php          + 顶部导航栏
│   ├── side_bar.php         + 侧边功能栏
│   └── toast.php            + 信息弹窗
├── database               # 数据库连接与工具脚本
│   ├── conn.php
│   ├── init.sql             + 数据表初始化sql语句
│   └── user.php
├── enum                   # 枚举类
│   ├── error_code.php       + 错误代码枚举
│   └── post_status.php      + 帖子状态枚举
├── index.php              # 主页
├── page                   # 子页面
│   ├── inbox.php            + 收件箱
│   ├── login.php            + 登录页
│   ├── post_censor.php      + 审核页
│   ├── post_detail.php      + 帖子详情页
│   ├── post_form.php        + 发帖表单
│   ├── profile.php          + 个人资料页
│   ├── register.php         + 注册页
│   └── search_result.php    + 搜索结果页
├── README.md              # 文档
└── service                # 业务逻辑封装
    ├── censor_post.php
    ├── delete_post.php
    ├── login.php
    ├── logout.php
    ├── post.php
    ├── register.php
    ├── reply.php
    ├── update_post.php
    └── update_profile.php
```
