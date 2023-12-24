use mysql::prelude::Queryable;

use crate::{dao::sql_connector::SqlConnector, repository::terminal_repository::TerminalRepository, entity::terminal::Terminal};

#[derive(Debug)]
pub struct DataIntializer {}

impl DataIntializer {
    fn init_database() -> Result<(), mysql::Error> {
        let mut conn = SqlConnector::get_conn();
        conn.query_drop("CREATE DATABASE bank_system;")?;
        Ok(())
    }

    fn init_table() -> Result<(), mysql::Error> {
        let mut conn = SqlConnector::get_conn();
        conn.query_drop(r#"
        USE bank_system;

        CREATE TABLE IF NOT EXISTS customer
        (
            id        INT AUTO_INCREMENT PRIMARY KEY,
            name      VARCHAR(255) COMMENT "开户名",
            pid       CHAR(18) UNIQUE COMMENT "身份证号，固定18位",
            telephone VARCHAR(12) COMMENT "手机号码，12或11位",
            address   VARCHAR(255) COMMENT "地址，可空"
        );

        CREATE TABLE IF NOT EXISTS card
        (
            id             CHAR(19) PRIMARY KEY COMMENT "卡号，固定19位",
            password       CHAR(6) COMMENT "密码，固定6位",
            open_money     DECIMAL(15, 2) COMMENT "开户金额，只能是CNY",
            open_date      DATETIME COMMENT "开户时间",
            is_report_loss TINYINT(1) COMMENT "是否挂失",
            customer_id    INT COMMENT "客户外键",
            FOREIGN KEY (customer_id) REFERENCES customer (id)
        );

        CREATE TABLE IF NOT EXISTS balance
        (
            id          INT AUTO_INCREMENT PRIMARY KEY,
            amount      DECIMAL(15, 2) COMMENT "余额",
            currency_id INT COMMENT "货币种类外键",
            card_id     CHAR(19) COMMENT "银行卡外键"
        );

        CREATE TABLE IF NOT EXISTS currency_type
        (
            id   INT AUTO_INCREMENT PRIMARY KEY,
            code CHAR(3) COMMENT "货币代号，固定3位"
        );

        CREATE TABLE IF NOT EXISTS terminal
        (
            id       INT AUTO_INCREMENT PRIMARY KEY,
            code     VARCHAR(255) UNIQUE COMMENT "终端代号",
            password VARCHAR(255) COMMENT "终端密码"
        );

        CREATE TABLE IF NOT EXISTS transaction
        (
            id               CHAR(36) PRIMARY KEY COMMENT "交易流水号，UUID，固定36位",
            transaction_date DATETIME COMMENT "交易日期",
            amount           DECIMAL(15, 2) COMMENT "交易金额",
            type             VARCHAR(10) CHECK ( type IN ('income', 'expense')) COMMENT "交易类型，income或expense",
            note             VARCHAR(255) COMMENT "交易备注",
            currency_id      INT COMMENT "交易币种",
            card_id          CHAR(19) PRIMARY KEY COMMENT "产生交易的银行卡外键",
            terminal_id      INT COMMENT "完成该交易的终端机外键",
            FOREIGN KEY (currency_id) REFERENCES currency_type (id),
            FOREIGN KEY (terminal_id) REFERENCES terminal (id)
        );
        "#)?;
        Ok(())
    }

    fn init_data() -> Result<(), mysql::Error> {
        TerminalRepository::add_terminal(Terminal {
            id: 0,
            code: String::from("T-1"),
            password: String::from("123456")
        });
        TerminalRepository::add_terminal(Terminal {
            id: 0,
            code: String::from("T-2"),
            password: String::from("654321")
        });
        Ok(()) 
    }

    pub fn init() -> Result<(), mysql::Error> {
        let mut conn = SqlConnector::get_conn();
        let results: Vec<String> = conn.query("SHOW DATABASES;")?;
        if !results.contains(&String::from("bank_system")) {
            println!("Database not exist, creating one...");
            Self::init_database()?;
            Self::init_table()?;
            Self::init_data()?;
            return Ok(())
        }
        conn.query_drop("USE bank_system;")?;
        Ok(()) 
    }
}
