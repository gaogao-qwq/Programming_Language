use mysql::prelude::Queryable;

use crate::{dao::sql_connector::SqlConnector, entity::card::Card};

#[derive(Debug)]
pub struct CardRepository {}

impl CardRepository {

    pub fn init() {}
    
    pub fn add_card(card: Card) -> i32 {
        let mut conn = SqlConnector::get_bank_system_conn();
        let cnt: Option<i32> = conn.query_first(format!(
            "INSERT INTO card (id, password, open_money, open_date, is_report_loss, customer_id)
            VALUE ('{}', '{}', {}, CURRENT_DATE, 0, {});",
            card.id, card.password, card.open_money, card.customer_id
        )).unwrap();
        cnt.unwrap_or(0)
    }

    pub fn get_card_by_id(id: &str) -> Option<Card> {
        let mut conn = SqlConnector::get_bank_system_conn();
        let res = conn.query_map(
            format!("SELECT * FROM card WHERE id = '{}';", id),
            |(id, password, open_money, open_date, is_report_loss, customer_id)| {
                Card { id, password, open_money, open_date, is_report_loss, customer_id }
            }
        ).unwrap_or(Vec::new());

        if res.is_empty() {
            return Option::None
        }

        return Some(res.get(0).unwrap().to_owned());
    }

}
