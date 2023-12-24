use crate::repository::card_repository::CardRepository;

pub struct CustomerService {}

impl CustomerService {
    
    pub fn login(id: &str, password: &str) -> bool {
        let c = CardRepository::get_card_by_id(id);
        if c.is_none() {
            return false;
        }
        return c.unwrap().password.eq(password);
    }

}
