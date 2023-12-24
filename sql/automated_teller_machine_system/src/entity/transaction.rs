use rust_decimal::Decimal;

#[derive(Debug, PartialEq, Eq)]
pub struct Transaction {
    id: String,
    transaction_date: String,
    amount: Decimal,
    transaction_type: String,
    note: String,
    currency_id: i32,
    card_id: String,
    terminal_id: i32
}
