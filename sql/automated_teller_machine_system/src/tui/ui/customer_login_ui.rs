use ratatui::{widgets::{Paragraph, Block, Borders, BorderType, Padding, Clear}, style::{Style, Color, Modifier}, layout::{Alignment, Rect, Layout, Direction, Constraint}, Frame};
use tui_textarea::TextArea;

use crate::service::customer_service::CustomerService;

#[derive(Debug)]
pub enum CurrentFocus {
    CardIdInput,
    PasswordInput,
    RegisterButton,
    ConfirmButton,
}

#[derive(Debug)]
pub struct CustomerLoginUi<'a> {
    pub current_focus: CurrentFocus,
    pub card_id_input: TextArea<'a>,
    pub password_input: TextArea<'a>,
    pub register_button: Paragraph<'a>,
    pub confirm_button: Paragraph<'a>,
    pub show_popup: bool,
    pub popup_message: String,
}

impl<'a> CustomerLoginUi<'a> {
    
    pub fn new() -> Self {
        let mut card_id_input = TextArea::default();
        card_id_input.set_placeholder_text("请输入卡号");
        card_id_input.set_cursor_line_style(Style::default().add_modifier(Modifier::UNDERLINED));
        card_id_input.set_cursor_style(Style::default().add_modifier(Modifier::SLOW_BLINK));
        card_id_input.set_block(
            Block::default()
                .borders(Borders::ALL)
                .style(Style::default().fg(Color::Yellow))
                .title("卡号")
        );

        let mut password_input = TextArea::default();
        password_input.set_mask_char('●');
        password_input.set_placeholder_text("请输入密码");
        password_input.set_cursor_line_style(Style::default());
        password_input.set_cursor_style(Style::default());
        password_input.set_block(
            Block::default()
                .borders(Borders::ALL)
                .style(Style::default().fg(Color::DarkGray))
                .title("密码")
        );

        let register_button = Paragraph::new("开卡")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
            );

        let confirm_button = Paragraph::new("登入")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
            );

        Self {
            current_focus: CurrentFocus::CardIdInput,
            card_id_input,
            password_input,
            register_button,
            confirm_button,
            show_popup: false,
            popup_message: String::from(""),
        }
    }

    pub fn up(&mut self) {
        match self.current_focus {
            CurrentFocus::CardIdInput => {
                self.inactivate_card_id_input();
                self.activate_confirm_button();
                self.current_focus = CurrentFocus::ConfirmButton;
            },
            CurrentFocus::PasswordInput => {
                self.inactivate_password_input();
                self.activate_card_id_input();
                self.current_focus = CurrentFocus::CardIdInput;
            },
            CurrentFocus::RegisterButton => {
                self.inactivate_register_button();
                self.activate_password_input();
                self.current_focus = CurrentFocus::PasswordInput;
            }
            CurrentFocus::ConfirmButton => {
                self.inactivate_confirm_button();
                self.activate_register_button();
                self.current_focus = CurrentFocus::RegisterButton;
            },
        }
    }

    pub fn down(&mut self) {
        match self.current_focus {
            CurrentFocus::CardIdInput => {
                self.inactivate_card_id_input();
                self.activate_password_input();
                self.current_focus = CurrentFocus::PasswordInput;
            },
            CurrentFocus::PasswordInput => {
                self.inactivate_password_input();
                self.activate_register_button();
                self.current_focus = CurrentFocus::RegisterButton;
            },
            CurrentFocus::RegisterButton => {
                self.inactivate_register_button();
                self.activate_confirm_button();
                self.current_focus = CurrentFocus::ConfirmButton;
            }
            CurrentFocus::ConfirmButton => {
                self.inactivate_confirm_button();
                self.activate_card_id_input();
                self.current_focus = CurrentFocus::CardIdInput;
            },
        }
    }

    pub fn auth(&mut self) -> bool {
        let card_id_opt = self.card_id_input.lines().get(0);
        let password_opt = self.password_input.lines().get(0);
        let card_id = card_id_opt.expect("Empty card id");
        let password = password_opt.expect("Empty password");
        if !CustomerService::login(card_id.as_str(), password.as_str()) {
            self.show_popup(format!("认证失败。"));
            return false;
        }
        return true;
    }

    pub fn clear_input(&mut self) {
        self.card_id_input.delete_line_by_head();
        self.password_input.delete_line_by_head();
    }

    pub fn is_input(&mut self) -> bool {
        match self.current_focus {
            CurrentFocus::CardIdInput | CurrentFocus::PasswordInput => {
                return true;
            },
            _ => return false,
        }
    }

    pub fn show_popup(&mut self, msg: String) {
        self.show_popup = true;
        self.popup_message = msg;
    }

    pub fn close_popup(&mut self) {
        self.show_popup = false;
        self.popup_message = String::from("");
    }

    pub fn render(&mut self, f: &mut Frame) {
        let main_block = Block::default()
            .title("ATM 终端 - 客户登入")
            .title_alignment(Alignment::Center)
            .borders(Borders::ALL)
            .border_type(BorderType::Rounded)
            .padding(Padding::new(30, 30, 5, 5));
        let main_area = f.size();
        let input_area = main_block.inner(main_area);
        let input_layout = Layout::default()
            .direction(Direction::Vertical)
            .constraints([
                Constraint::Length(2),
                Constraint::Max(3),
                Constraint::Max(3),
                Constraint::Max(3),
                Constraint::Max(3),
            ])
            .split(input_area);
        let title = Paragraph::new("请输入卡号和密码")
            .style(Style::default().fg(Color::Yellow))
            .alignment(Alignment::Center);

        f.render_widget(main_block, main_area);
        f.render_widget(title, input_layout[0]);
        f.render_widget(self.card_id_input.widget(), input_layout[1]);
        f.render_widget(self.password_input.widget(), input_layout[2]);
        f.render_widget(self.register_button.clone(), input_layout[3]);
        f.render_widget(self.confirm_button.clone(), input_layout[4]);
        if self.show_popup {
            let message = Paragraph::new(self.popup_message.as_str())
                .block(Block::default()
                        .borders(Borders::ALL)
            );
            let area = Self::centered_rect(60, 20, main_area);
            f.render_widget(Clear, area);
            f.render_widget(message, area);
        }
    }

    fn centered_rect(percent_x: u16, percent_y: u16, r: Rect) -> Rect {
        let popup_layout = Layout::default()
            .direction(Direction::Vertical)
            .constraints([
                Constraint::Percentage((100 - percent_y) / 2),
                Constraint::Percentage(percent_y),
                Constraint::Percentage((100 - percent_y) / 2),
            ])
            .split(r);

        Layout::default()
            .direction(Direction::Horizontal)
            .constraints([
                Constraint::Percentage((100 - percent_x) / 2),
                Constraint::Percentage(percent_x),
                Constraint::Percentage((100 - percent_x) / 2),
            ])
            .split(popup_layout[1])[1]
    }

    fn activate_card_id_input(&mut self) {
        self.card_id_input.set_cursor_line_style(Style::default().add_modifier(Modifier::UNDERLINED));
        self.card_id_input.set_cursor_style(Style::default().add_modifier(Modifier::SLOW_BLINK));
        self.card_id_input.set_block(
            Block::default()
            .borders(Borders::ALL)
            .style(Style::default().fg(Color::Yellow))
            .title("卡号")
        );
    }

    fn inactivate_card_id_input(&mut self) {
        self.card_id_input.set_cursor_line_style(Style::default());
        self.card_id_input.set_cursor_style(Style::default());
        self.card_id_input.set_block(
            Block::default()
                .borders(Borders::all())
                .style(Style::default().fg(Color::DarkGray))
                .title("卡号")
        );
    }

    fn activate_password_input(&mut self) {
        self.password_input.set_cursor_line_style(Style::default().add_modifier(Modifier::UNDERLINED));
        self.password_input.set_cursor_style(Style::default().add_modifier(Modifier::SLOW_BLINK));
        self.password_input.set_block(
            Block::default()
            .borders(Borders::ALL)
            .style(Style::default().fg(Color::Yellow))
            .title("密码")
        );
    }

    fn inactivate_password_input(&mut self) {
        self.password_input.set_cursor_line_style(Style::default());
        self.password_input.set_cursor_style(Style::default());
        self.password_input.set_block(
            Block::default()
                .borders(Borders::all())
                .style(Style::default().fg(Color::DarkGray))
                .title("密码")
        );
    }

    fn activate_register_button(&mut self) {
        self.register_button = Paragraph::new("开卡")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::Yellow))
        );
    }

    fn inactivate_register_button(&mut self) {
        self.register_button = Paragraph::new("开卡")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
        );
    }

    fn activate_confirm_button(&mut self) {
        self.confirm_button = Paragraph::new("登入")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::Yellow))
        );
    }

    fn inactivate_confirm_button(&mut self) {
        self.confirm_button = Paragraph::new("登入")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
        );
    }

}
