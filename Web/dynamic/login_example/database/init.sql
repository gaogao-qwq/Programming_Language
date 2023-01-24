CREATE TABLE IF NOT EXISTS userinfo (
    uid INT NOT NULL AUTO_INCREMENT,
    email varchar(64),
    username char(32),
    password char(64),
    created date,
    PRIMARY KEY(uid),
    INDEX email_index (email),
    INDEX username_index (username)
) AUTO_INCREMENT=10000;