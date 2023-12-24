use super::ui::{terminal_ui::TerminalUi, customer_login_ui::CustomerLoginUi, customer_register_ui::CustomerRegisterUi, customer_menu_ui::CustomerMenuUi};

#[derive(Debug)]
pub enum CurrentScreen {
    TerminalLogin,
    CustomerLogin,
    CustomerRegister,
    CustomerMenu,
}

#[derive(Debug)]
pub enum InputMode {
    Normal,
    Insert,
}


#[derive(Debug)]
pub struct App<'a> {
    pub should_quit: bool,
    pub current_customer_id: String,
    pub current_terminal_id: String,
    pub current_screen: CurrentScreen,
    pub input_mode: InputMode,
    pub terminal_ui: TerminalUi<'a>,
    pub customer_login_ui: CustomerLoginUi<'a>,
    pub customer_register_ui: CustomerRegisterUi<'a>,
    pub customer_menu_ui: CustomerMenuUi<'a>,
}

impl<'a> App<'a> {
    pub fn new() -> Self {
        Self {
            should_quit: false,
            current_customer_id: String::from(""),
            current_terminal_id: String::from(""),
            current_screen: CurrentScreen::TerminalLogin,
            input_mode: InputMode::Normal,
            terminal_ui: TerminalUi::new(),
            customer_login_ui: CustomerLoginUi::new(),
            customer_register_ui: CustomerRegisterUi::new(),
            customer_menu_ui: CustomerMenuUi::new(),
        }
    }

    pub fn tick(&self) {}

    // pub fn login_terminal(&mut self, terminal_id: String, token: String) -> bool {
    //     
    // }

    pub fn quit(&mut self) {
        self.should_quit = true;
    }
}
