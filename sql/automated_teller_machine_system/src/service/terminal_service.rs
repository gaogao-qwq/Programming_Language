use crate::repository::terminal_repository::TerminalRepository;

pub struct TerminalService {}

impl TerminalService {
    
    pub fn login(code: &str, password: &str) -> bool {
        let t = TerminalRepository::get_terminal_by_code(code);
        if t.is_none() {
            return false;
        }
        return t.unwrap().password.eq(password);
    }

}
