use super::{card_repository::CardRepository, terminal_repository::TerminalRepository, customer_repository::CustomerRepositiry};

pub fn init() {
    CardRepository::init();
    TerminalRepository::init();
    CustomerRepositiry::init();
}
