#[derive(Debug, PartialEq)]
pub struct Transaction {
    id: String,
    transaction_date: String,
    amount: f64,
    transaction_type: String,
    note: String,
    currency_id: i32,
    card_id: String,
    terminal_id: i32
}
