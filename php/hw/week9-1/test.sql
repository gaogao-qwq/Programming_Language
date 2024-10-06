/*
SQLyog Ultimate v12.09 (64 bit)
MySQL - 5.5.62 : Database - test
*********************************************************************
*/
/*!40101 SET NAMES utf8 */;

/*!40101 SET SQL_MODE=''*/;

/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;

/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;

/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;

/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

CREATE DATABASE /*!32312 IF NOT EXISTS*/ `test` /*!40100 DEFAULT CHARACTER SET utf8 */;

USE `test`;

/*Table structure for table `list` */
DROP TABLE IF EXISTS `list`;

CREATE TABLE `list` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `title` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = MyISAM AUTO_INCREMENT = 3 DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;

/*Data for the table `list` */
insert into
  `list` (`id`, `title`)
values
  (1, '江苏张家港：传承红色基因 建设文明典范城市'),
  (2, '乌克兰国防部长27日表的“车“黄鼠狼”步兵战车。');

/*Table structure for table `post` */
DROP TABLE IF EXISTS `post`;

CREATE TABLE `post` (
  `id` int(11) NOT NULL AUTO_INCREMENT,
  `list_id` int(11) NOT NULL,
  `text` varchar(200) COLLATE utf8_unicode_ci NOT NULL,
  `name` varchar(20) COLLATE utf8_unicode_ci NOT NULL,
  `time` datetime NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE = MyISAM AUTO_INCREMENT = 3 DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;

/*Data for the table `post` */
insert into
  `post` (`id`, `list_id`, `text`, `name`, `time`)
values
  (
    1,
    1,
    '6月7日，正在青海考察调研的习近平总书记走进西宁的企业和社区。 \r\n\r\n总书记此行——进企业，看特色产业发展、推进乡村振兴；入社区，考察社区加强基层党建、完善基层治理、推进民族团结进步等情况。 \r\n\r\n走进人民中间，一声声询问，一句句叮嘱，饱含总书记对人民幸福、美好生活的关切。',
    '央视新闻客户端',
    '2021-06-05 00:00:00'
  ),
  (
    2,
    2,
    '6月7日，习近平总书记在青海省西宁市青海圣源地毯集团有限公司考察调研。\r\n\r\n7日下午，习近平总书记来到西宁市青海圣源地毯集团有限公司考察调研。 ',
    '央视新闻',
    '2021-06-08 00:00:00'
  );

/*Table structure for table `produce` */
DROP TABLE IF EXISTS `produce`;

CREATE TABLE `produce` (
  `id` int(11) NOT NULL AUTO_INCREMENT COMMENT '商品编号',
  `pname` varchar(20) COLLATE utf8_unicode_ci NOT NULL COMMENT '商品名称',
  `price` int(11) NOT NULL COMMENT '商品价格',
  `pcount` int(11) NOT NULL COMMENT '商品数量',
  `remark` varchar(50) COLLATE utf8_unicode_ci NOT NULL COMMENT '商品备注',
  PRIMARY KEY (`id`)
) ENGINE = MyISAM AUTO_INCREMENT = 22 DEFAULT CHARSET = utf8 COLLATE = utf8_unicode_ci;

/*Data for the table `produce` */
insert into
  `produce` (`id`, `pname`, `price`, `pcount`, `remark`)
values
  (2, '炫迈口香糖', 5, 10, '根本停不下来'),
  (3, '乐事', 3, 15, '就是脆'),
  (5, '可乐', 3, 20, 'yyds'),
  (9, '奶茶', 10, 30, '一天一杯美滋滋'),
  (10, '薯条', 7, 33, '新鲜出炉'),
  (20, '你好', 3, 8, '77');

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;

/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;

/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;

/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;
