use mysql::prelude::Queryable;

use crate::{dao::sql_connector::SqlConnector, entity::terminal::Terminal};


#[derive(Debug)]
pub struct TerminalRepository {}

impl TerminalRepository {

    pub fn init() {}

    pub fn add_terminal(terminal: Terminal) -> i32 {
        let mut conn = SqlConnector::get_bank_system_conn();
        let cnt: Option<i32> = conn.query_first(format!(
            "INSERT INTO terminal (code, password) VALUE ('{}', '{}');",
            terminal.code, terminal.password
        )).unwrap();
        cnt.unwrap_or(0)
    }

    pub fn get_terminal_by_code(code: &str) -> Option<Terminal> {
        let mut conn = SqlConnector::get_bank_system_conn();
        let res = conn.query_map(
            format!("SELECT * FROM terminal WHERE code = '{}'", code),
            |(id, code, password)| {
                Terminal { id, code, password }
            }
        ).unwrap_or(Vec::new());

        if res.is_empty() {
            return Option::None
        }

        return Some(res.get(0).unwrap().to_owned())
    }

}
