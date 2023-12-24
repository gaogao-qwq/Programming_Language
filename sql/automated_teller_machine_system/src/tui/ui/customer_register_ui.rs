use ratatui::{Frame, layout::{Rect, Layout, Direction, Constraint, Alignment}, widgets::{Block, Borders, BorderType, Padding, Paragraph, Clear}, style::{Style, Color}};
use tui_textarea::TextArea;

#[derive(Debug)]
pub struct CustomerRegisterUi<'a> {
    pub name_input: TextArea<'a>,
    pub pid_input: TextArea<'a>,
    pub telephone_input: TextArea<'a>,
    pub address_input: TextArea<'a>,
    pub register_button: Paragraph<'a>,
    pub back_button: Paragraph<'a>,
    pub show_popup: bool,
    pub popup_message: String,
}

impl<'a> CustomerRegisterUi<'a> {

    pub fn new() -> Self {
        let mut name_input = TextArea::default();
        let mut pid_input = TextArea::default();
        let mut telephone_input = TextArea::default();
        let mut address_input = TextArea::default();

        let register_button = Paragraph::new("提交信息")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
            );

        let back_button = Paragraph::new("取消开卡")
            .alignment(Alignment::Center)
            .block(
                Block::default()
                    .borders(Borders::ALL)
                    .style(Style::default().fg(Color::DarkGray))
            );

        Self {
            name_input,
            pid_input,
            telephone_input,
            address_input,
            register_button,
            back_button,
            show_popup: false,
            popup_message: String::from(""),
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
            .title("ATM 终端 - 客户开卡")
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
                Constraint::Max(3),
                Constraint::Max(3),
            ])
            .split(input_area);
        let title = Paragraph::new("请提供个人信息和借记卡密码")
            .style(Style::default().fg(Color::Yellow))
            .alignment(Alignment::Center);

        f.render_widget(main_block, main_area);
        f.render_widget(title, input_layout[0]);
        f.render_widget(self.name_input.widget(), input_layout[1]);
        f.render_widget(self.pid_input.widget(), input_layout[2]);
        f.render_widget(self.telephone_input.widget(), input_layout[3]);
        f.render_widget(self.address_input.widget(), input_layout[4]);
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
