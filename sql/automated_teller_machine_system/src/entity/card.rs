use rust_decimal::Decimal;

#[derive(Debug, PartialEq, Eq, Clone)]
pub struct Card {
    pub id: String,
    pub password: String,
    pub open_money: Decimal,
    pub open_date: String,
    pub is_report_loss: bool,
    pub customer_id: i32,
}
