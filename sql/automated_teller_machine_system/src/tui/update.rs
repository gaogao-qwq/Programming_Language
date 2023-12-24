use crossterm::event::{KeyCode, KeyEvent, KeyModifiers};
use tui_textarea::Input;

use crate::tui::app::App;

use super::{app::{CurrentScreen, InputMode}, ui::{terminal_ui, customer_login_ui::{self}}};

pub fn update(app: &mut App, key_event: KeyEvent) {
    match app.current_screen {
        CurrentScreen::TerminalLogin => update_terminal_login(app, key_event),
        CurrentScreen::CustomerLogin => update_customer_login(app, key_event),
        CurrentScreen::CustomerRegister => update_customer_register(app, key_event),
        CurrentScreen::CustomerMenu => update_customer_menu(app, key_event),
    }
}

fn update_terminal_login(app: &mut App, key_event: KeyEvent) {
    match app.input_mode {
        InputMode::Normal => match key_event.code {
            KeyCode::Char('q') => {
                if app.terminal_ui.show_popup {
                    app.terminal_ui.close_popup();
                }
            },
            KeyCode::Char('c') | KeyCode::Char('C') => {
                if key_event.modifiers == KeyModifiers::CONTROL {
                    app.quit()
                }
            },
            KeyCode::Down | KeyCode::Char('j') => {
                app.terminal_ui.down();
            },
            KeyCode::Up | KeyCode::Char('k') => {
                app.terminal_ui.up();
            }
            KeyCode::Enter => match app.terminal_ui.current_focus {
                terminal_ui::CurrentFocus::ConfirmButton => {
                    if app.terminal_ui.auth() {
                        app.current_terminal_id = app.terminal_ui.machine_code_input.lines().get(0).unwrap().to_string();
                        app.current_screen = CurrentScreen::CustomerLogin;
                    }
                },
                _ => match app.terminal_ui.is_input() {
                    true => app.input_mode = InputMode::Insert,
                    false => {},
                },
            }
            _ => {},
        },
        InputMode::Insert => match key_event.code {
            KeyCode::Esc => app.input_mode = InputMode::Normal,
            KeyCode::Enter => {
                app.terminal_ui.down();
                if app.terminal_ui.is_input() {return}
                app.input_mode = InputMode::Normal;
            },
            KeyCode::Backspace => {
                match app.terminal_ui.current_focus {
                    terminal_ui::CurrentFocus::MachineCodeInput => {
                        app.terminal_ui.machine_code_input.delete_char();
                    },
                    terminal_ui::CurrentFocus::PasswordInput => {
                        app.terminal_ui.password_input.delete_char();
                    },
                    _ => {},
                }
            }
            KeyCode::Char(_) => {
                match app.terminal_ui.current_focus {
                    terminal_ui::CurrentFocus::MachineCodeInput => {
                        app.terminal_ui.machine_code_input.input(Input::from(key_event));
                    },
                    terminal_ui::CurrentFocus::PasswordInput => {
                        app.terminal_ui.password_input.input(Input::from(key_event));
                    },
                    _ => {},
                }
            },
            _ => {},
        },
    }
}

fn update_customer_login(app: &mut App, key_event: KeyEvent) {
    match app.input_mode {
        InputMode::Normal => match key_event.code {
            KeyCode::Char('q') => {
                if app.customer_login_ui.show_popup {
                    app.customer_login_ui.close_popup();
                }
            },
            KeyCode::Char('c') | KeyCode::Char('C') => {
                if key_event.modifiers == KeyModifiers::CONTROL {
                    app.quit()
                }
            },
            KeyCode::Down | KeyCode::Char('j') => {
                app.customer_login_ui.down();
            },
            KeyCode::Up | KeyCode::Char('k') => {
                app.customer_login_ui.up();
            }
            KeyCode::Enter => match app.customer_login_ui.current_focus {
                customer_login_ui::CurrentFocus::ConfirmButton => 
                    match app.customer_login_ui.auth() {
                        true => {
                            app.customer_login_ui.clear_input();
                            app.current_screen = CurrentScreen::CustomerMenu
                        },
                        false => {},
                },
                customer_login_ui::CurrentFocus::RegisterButton => {
                    app.current_screen = CurrentScreen::CustomerRegister;
                }
                _ => match app.customer_login_ui.is_input() {
                    true => app.input_mode = InputMode::Insert,
                    false => {},
                },
            },
            _ => {},
        },
        InputMode::Insert => match key_event.code {
            KeyCode::Esc => app.input_mode = InputMode::Normal,
            KeyCode::Enter => {
                app.customer_login_ui.down();
                if app.customer_login_ui.is_input() {return}
                app.input_mode = InputMode::Normal
            },
            KeyCode::Backspace => {
                match app.customer_login_ui.current_focus {
                    customer_login_ui::CurrentFocus::CardIdInput => {
                        app.customer_login_ui.card_id_input.delete_char();
                    },
                    customer_login_ui::CurrentFocus::PasswordInput => {
                        app.customer_login_ui.password_input.delete_char();
                    },
                    _ => {},
                }
            }
            KeyCode::Char(_) => {
                match app.customer_login_ui.current_focus {
                    customer_login_ui::CurrentFocus::CardIdInput => {
                        app.customer_login_ui.card_id_input.input(Input::from(key_event));
                    },
                    customer_login_ui::CurrentFocus::PasswordInput => {
                        app.customer_login_ui.password_input.input(Input::from(key_event));
                    },
                    _ => {},
                }
            },
            _ => {},
        },
    }
}

fn update_customer_register(app: &mut App, key_event: KeyEvent) {
    match app.input_mode {
        InputMode::Normal => match key_event.code {
            KeyCode::Char('q') => {
                if app.customer_register_ui.show_popup {
                    app.terminal_ui.close_popup();
                }
            },
            KeyCode::Char('c') | KeyCode::Char('C') => {
                if key_event.modifiers == KeyModifiers::CONTROL {
                    app.quit()
                }
            },
            _ => {},
        },
        InputMode::Insert => match key_event.code {
            _ => {},
        },
    }
}

fn update_customer_menu(app: &mut App, key_event: KeyEvent) {
    match app.input_mode {
        InputMode::Normal => match key_event.code {
            KeyCode::Char('c') | KeyCode::Char('C') => {
                if key_event.modifiers == KeyModifiers::CONTROL {
                    app.quit()
                }
            },
            _ => {},
        },
        InputMode::Insert => match key_event.code {
            _ => {},
        },
    }
}

