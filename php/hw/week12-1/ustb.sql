CREATE TABLE IF NOT EXISTS `basic_info` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `department` varchar(20) NOT NULL,
  `major` varchar(20) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = InnoDB DEFAULT CHARSET = utf8 AUTO_INCREMENT = 14;

INSERT INTO
  `basic_info` (`id`, `name`, `department`, `major`)
VALUES
  (1, '张名字', '市场部', '网络工程'),
  (2, '张三', '财务部', '软件工程'),
  (3, '田大海', '开发部', '数字媒体'),
  (4, '李四', '开发部', '网络工程'),
  (5, '王五', '财务部', '市场营销'),
  (6, '小王', '开发部', '网络工程'),
  (7, '小李子', '开发部', '网络工程'),
  (8, '王蒙', '开发部', '数字媒体'),
  (9, '李四', '市场部', '历史学'),
  (10, '谷歌', '开发部', '历史学'),
  (11, '谷歌', '市场部', '软件工程'),
  (12, '电磁', '开发部', '软件工程'),
  (13, '王长江', '市场部', '软件工程');

CREATE TABLE IF NOT EXISTS `user` (
  `id` int(10) NOT NULL AUTO_INCREMENT,
  `username` varchar(20) CHARACTER
  SET
    utf8 NOT NULL,
    `password` varchar(20) CHARACTER
  SET
    utf8 NOT NULL,
    `email` varchar(50) CHARACTER
  SET
    utf8 NOT NULL,
    PRIMARY KEY (`id`)
) ENGINE = InnoDB DEFAULT CHARSET = utf32 AUTO_INCREMENT = 2;

INSERT INTO
  `user` (`id`, `username`, `password`, `email`)
VALUES
  (1, 'luck', '12345', '853882915@qq.com');
