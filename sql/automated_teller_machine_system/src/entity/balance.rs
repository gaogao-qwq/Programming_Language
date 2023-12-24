use rust_decimal::Decimal;

#[derive(Debug, PartialEq, Eq)]
pub struct Balance {
    id: i32,
    amount: Decimal,
    currency_id: i64,
    card_id: String
}
