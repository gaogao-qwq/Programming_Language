use ratatui::{
    prelude::{Alignment, Frame},
    style::{Style, Color, Modifier},
    widgets::{Block, Borders, BorderType, Paragraph, Padding, Clear}, layout::{Layout, Direction, Constraint, Rect},
};
use tui_textarea::TextArea;

use crate::service::terminal_service::TerminalService;

#[derive(Debug)]
pub enum CurrentFocus {
    MachineCodeInput,
    PasswordInput,
    ConfirmButton,
}

#[derive(Debug)]
pub struct TerminalUi<'a> {
    pub current_focus: CurrentFocus,
    pub machine_code_input: TextArea<'a>,
    pub password_input: TextArea<'a>,
    pub confirm_button: Paragraph<'a>,
    pub show_popup: bool,
    pub popup_message: String,
}

impl<'a> TerminalUi<'a> {

    pub fn new() -> Self {
        let mut machine_code_input = TextArea::default();
        machine_code_input.set_placeholder_text("请输入终端机代号");
        machine_code_input.set_cursor_line_style(Style::default().add_modifier(Modifier::UNDERLINED));
        machine_code_input.set_cursor_style(Style::default().add_modifier(Modifier::SLOW_BLINK));
        machine_code_input.set_block(
            Block::default()
                .borders(Borders::ALL)
                .style(Style::default().fg(Color::Yellow))
                .title("终端机号")
        );

        let mut password_input = TextArea::default();
        password_input.set_mask_char('●');
        password_input.set_placeholder_text("请输入令牌");
        password_input.set_cursor_line_style(Style::default());
        password_input.set_cursor_style(Style::default());
        password_input.set_block(
            Block::default()
                .borders(Borders::ALL)
                .style(Style::default().fg(Color::DarkGray))
                .title("终端机令牌")
        );

        let confirm_button = Paragraph::new("确认")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
            );

        Self {
            current_focus: CurrentFocus::MachineCodeInput,
            machine_code_input,
            password_input,
            confirm_button,
            show_popup: false,
            popup_message: String::from(""),
        }
    }

    pub fn is_input(&mut self) -> bool {
        match self.current_focus {
            CurrentFocus::MachineCodeInput | CurrentFocus::PasswordInput => {
                return true;
            },
            _ => return false,
        }
    }

    pub fn up(&mut self) {
        match self.current_focus {
            CurrentFocus::MachineCodeInput => {
                self.inactivate_code_input();
                self.activate_confirm_button();
                self.current_focus = CurrentFocus::ConfirmButton;
            },
            CurrentFocus::PasswordInput => {
                self.inactivate_password_input();
                self.activate_code_input();
                self.current_focus = CurrentFocus::MachineCodeInput;
            },
            CurrentFocus::ConfirmButton => {
                self.inactivate_confirm_button();
                self.activate_password_input();
                self.current_focus = CurrentFocus::PasswordInput;
            },
        }
    }

    pub fn down(&mut self) {
        match self.current_focus {
            CurrentFocus::MachineCodeInput => {
                self.inactivate_code_input();
                self.activate_password_input();
                self.current_focus = CurrentFocus::PasswordInput;
            },
            CurrentFocus::PasswordInput => {
                self.inactivate_password_input();
                self.activate_confirm_button();
                self.current_focus = CurrentFocus::ConfirmButton;
            },
            CurrentFocus::ConfirmButton => {
                self.inactivate_confirm_button();
                self.activate_code_input();
                self.current_focus = CurrentFocus::MachineCodeInput;
            },
        }
    }

    pub fn auth(&mut self) -> bool {
        let machine_code_opt = self.machine_code_input.lines().get(0);
        let password_opt = self.password_input.lines().get(0);
        let machine_code = machine_code_opt.expect("Empty machine code");
        let password = password_opt.expect("Empty password");
        if !TerminalService::login(machine_code.as_str(), password.as_str()) {
            self.show_popup(format!("认证失败，请向系统管理员询问凭证。"));
            return false;
        }
        return true;
    }

    pub fn show_popup(&mut self, msg: String) {
        self.show_popup = true;
        self.popup_message = msg;
    }

    pub fn close_popup(&mut self) {
        self.show_popup = false;
        self.popup_message = String::from("");
    }

    fn activate_code_input(&mut self) {
        self.machine_code_input.set_cursor_line_style(Style::default().add_modifier(Modifier::UNDERLINED));
        self.machine_code_input.set_cursor_style(Style::default().add_modifier(Modifier::SLOW_BLINK));
        self.machine_code_input.set_block(
            Block::default()
            .borders(Borders::ALL)
            .style(Style::default().fg(Color::Yellow))
            .title("终端机号")
        );
    }

    fn inactivate_code_input(&mut self) {
        self.machine_code_input.set_cursor_line_style(Style::default());
        self.machine_code_input.set_cursor_style(Style::default());
        self.machine_code_input.set_block(
            Block::default()
                .borders(Borders::all())
                .style(Style::default().fg(Color::DarkGray))
                .title("终端机号")
        );
    }

    fn activate_password_input(&mut self) {
        self.password_input.set_cursor_line_style(Style::default().add_modifier(Modifier::UNDERLINED));
        self.password_input.set_cursor_style(Style::default().add_modifier(Modifier::SLOW_BLINK));
        self.password_input.set_block(
            Block::default()
            .borders(Borders::ALL)
            .style(Style::default().fg(Color::Yellow))
            .title("终端机令牌")
        );
    }

    fn inactivate_password_input(&mut self) {
        self.password_input.set_cursor_line_style(Style::default());
        self.password_input.set_cursor_style(Style::default());
        self.password_input.set_block(
            Block::default()
                .borders(Borders::all())
                .style(Style::default().fg(Color::DarkGray))
                .title("终端机令牌")
        );
    }

    fn activate_confirm_button(&mut self) {
        self.confirm_button = Paragraph::new("确认")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::Yellow))
        );
    }

    fn inactivate_confirm_button(&mut self) {
        self.confirm_button = Paragraph::new("确认")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
        );
    }

    pub fn render(&mut self, f: &mut Frame) {
        let main_block = Block::default()
            .title("ATM 终端")
            .title_alignment(Alignment::Center)
            .borders(Borders::ALL)
            .border_type(BorderType::Rounded)
            .padding(Padding::new(30, 30, 10, 10));

        let main_area = f.size();
        let input_area = main_block.inner(main_area);
        let input_layout = Layout::default()
            .direction(Direction::Vertical)
            .constraints([
                Constraint::Length(2),
                Constraint::Max(3),
                Constraint::Max(3),
                Constraint::Max(3),
            ])
            .split(input_area);

        let title = Paragraph::new("终端机需要输入终端机号与令牌才能启用，\n请先向系统管理员取得终端机号码和令牌。")
            .style(Style::default().fg(Color::Yellow))
            .alignment(Alignment::Center);


        f.render_widget(main_block, main_area);
        f.render_widget(title, input_layout[0]);
        f.render_widget(self.machine_code_input.widget(), input_layout[1]);
        f.render_widget(self.password_input.widget(), input_layout[2]);
        f.render_widget(self.confirm_button.clone(), input_layout[3]);
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

}

