CREATE DATABASE IF NOT EXISTS books;

USE books;

DROP TABLE IF EXISTS `books`;

CREATE TABLE `books` (
  `bookid` char(10) NOT NULL COMMENT '图书编号',
  `bookname` varchar(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '书名',
  `bookprice` varchar(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci NOT NULL COMMENT '价格',
  `press` varchar(30) DEFAULT NULL COMMENT '出版单位',
  `writer` varchar(8) DEFAULT NULL COMMENT '编著',
  `presstime` date DEFAULT NULL COMMENT '出版时间',
  `booktype` varchar(30) CHARACTER SET utf8 COLLATE utf8_unicode_ci DEFAULT NULL COMMENT '类别',
  PRIMARY KEY (`bookid`)
) ENGINE=MyISAM AUTO_INCREMENT=50 DEFAULT CHARSET=gb2312;


insert  into `books`(`bookid`,`bookname`,`bookprice`,`press`,`writer`,`presstime`,`booktype`) values ('2021080001','MySQL数据库应用教程','35','合肥工业大学出版社','董国钢','2019-01-01','励志'),('2021080003','自控力','38','印刷工业出版社','凯利','2014-05-01','励志'),('2021080004','百年孤独','50','人民邮电出版社','马尔克斯','1967-07-11','魔幻'),('2021080005','活着','31','北京十月文艺出版社','余华','2021-08-12','励志'),('2021080006','生死疲劳','35','浙江文艺出版社','莫言','1976-09-23','励志'),('2021080007','晚熟的人','38','浙江文艺出版社','莫言','1976-09-23','励志'),('2021080008','许三观卖血记','35','北京十月文艺出版社','余华','2021-08-12','励志'),('2021080009','兄弟','35','北京十月文艺出版社','余华','2021-08-12','励志'),('2021080010','哈利波特全套','278','人民文学出版社','罗琳JK','2021-08-12','魔幻'),('2021080011','三体','64.8','人民文学出版社','刘慈欣','2021-08-23','科幻'),('2021080012','流浪地球','125','广西师范大学出版社','刘慈欣','2021-08-23',NULL);


DROP TABLE IF EXISTS `users`;

CREATE TABLE `users` (
  `username` varchar(10) DEFAULT NULL,
  `password` varchar(12) DEFAULT NULL,
  `usertype` varchar(12) DEFAULT NULL
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

insert  into `users`(`username`,`password`,`usertype`) values ('admin','admin',NULL),('dgg','dgg123456',NULL);

