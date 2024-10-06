use gdnmb;

create table if not exists role
(
    id   int auto_increment
        primary key,
    name varchar(255) not null,
    constraint role_uk
        unique (name)
) auto_increment = 10000;
insert into gdnmb.role (name)
values ('admin');
insert into gdnmb.role (name)
values ('user');


create table if not exists user
(
    id          int auto_increment
        primary key,
    name        varchar(255) null,
    password    varchar(255) null,
    create_date datetime     not null,
    role_id     int          not null,
    constraint user_uk
        unique (name),
    constraint user_role_id_fk
        foreign key (role_id) references role (id)
) auto_increment = 10000;
insert into user (name, password, create_date, role_id)
values ('root', '4813494d137e1631bba301d5acab6e7bb7aa74ce1185d456565ef51d737677b2', '2020-01-01 00:00:00', 10000);
insert into gdnmb.user (name, password, create_date, role_id)
values ('user1', '0a041b9462caa4a31bac3567e0b6e6fd9100787db2ab433d96f6d178cabfce90', '2023-08-08 00:00:00', 10001);
insert into gdnmb.user (name, password, create_date, role_id)
values ('user2', '6025d18fe48abd45168528f18a82e265dd98d421a7084aa09f61b341703901a3', '2023-04-06 00:00:00', 10001);
insert into gdnmb.user (name, password, create_date, role_id)
values ('user3', '5860faf02b6bc6222ba5aca523560f0e364ccd8b67bee486fe8bf7c01d492ccb', '2023-06-08 00:00:00', 10001);

create table if not exists post
(
    id          int auto_increment
        primary key,
    title       varchar(255)   not null,
    content     varchar(10000) not null,
    create_date datetime       not null,
    update_date datetime       not null,
    status      int default 0  not null,
    user_id     int            not null,
    constraint post_user_id_fk
        foreign key (user_id) references user (id)
) auto_increment = 10000;
insert into gdnmb.post (title, content, create_date, update_date, status, user_id)
values ('帖子标题1', '帖子内容1', '2023-10-01 17:32:33', '2024-04-06 12:30:00', 1, 10002);
insert into gdnmb.post (title, content, create_date, update_date, status, user_id)
values ('帖子标题2', '帖子内容2', '2023-11-30 13:47:33', '2024-03-11 12:30:00', 1, 10001);
insert into gdnmb.post (title, content, create_date, update_date, status, user_id)
values ('帖子标题3', '帖子内容3', '2023-12-12 18:17:33', '2024-02-23 12:30:00', 1, 10003);
insert into gdnmb.post (title, content, create_date, update_date, status, user_id)
values ('帖子标题4', '帖子内容4', '2023-12-04 13:35:33', '2024-02-20 15:32:00', 1, 10001);
insert into gdnmb.post (title, content, create_date, update_date, status, user_id)
values ('帖子标题5', '帖子内容5', '2023-11-23 12:53:33', '2024-01-23 14:42:00', 1, 10003);

create table if not exists reply
(
    id          int auto_increment
        primary key,
    content     varchar(1000) not null,
    create_date datetime      null,
    update_date datetime      null,
    user_id     int           not null,
    post_id     int           not null,
    constraint reply_post_id_fk
        foreign key (post_id) references post (id),
    constraint reply_user_id_fk
        foreign key (user_id) references user (id)
) auto_increment = 10000;
insert into `reply` (content, create_date, update_date, user_id, post_id)
values ('回复1', '2024-03-12 15:30:00', '2024-03-12 15:30:00', 10003, 10000);
insert into `reply` (content, create_date, update_date, user_id, post_id)
values ('回复2', '2024-04-06 12:30:00', '2024-04-06 12:30:00', 10000, 10000);
insert into `reply` (content, create_date, update_date, user_id, post_id)
values ('回复3', '2024-03-11 12:30:00', '2024-03-11 12:30:00', 10002, 10001);

