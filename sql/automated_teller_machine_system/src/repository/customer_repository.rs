use mysql::prelude::Queryable;

use crate::{entity::customer::Customer, dao::sql_connector::SqlConnector};

use super::card_repository::CardRepository;

#[derive(Debug)]
pub struct CustomerRepositiry {}

impl CustomerRepositiry {

    pub fn init() {}

    pub fn add_customer(customer: Customer) -> i32 {
        let mut conn = SqlConnector::get_bank_system_conn();
        let cnt: Option<i32> = conn.query_first(format!(
            "INSERT INTO customer (name, pid, telephone, address)
            VALUE ('{}', '{}', '{}', '{}');",
            customer.name, customer.pid, customer.telephone, customer.address
        )).unwrap();
        cnt.unwrap_or(0)
    }

    pub fn get_customer_by_card_id(card_id: &str) -> Option<Customer> {
        let card_opt = CardRepository::get_card_by_id(card_id);
        if card_opt.is_none() {
            return Option::None;
        }
        let card = card_opt.unwrap();

        let mut conn = SqlConnector::get_bank_system_conn();
        let res = conn.query_map(
            format!("SELECT * FROM WHERE id = {}", card.customer_id),
            |(id, name, pid, telephone, address)| {
                Customer {id, name, pid, telephone, address}
            }
        ).unwrap_or(Vec::new());
        if res.is_empty() {
            return Option::None;
        }

        return Some(res.get(0).unwrap().to_owned());
    }

}
