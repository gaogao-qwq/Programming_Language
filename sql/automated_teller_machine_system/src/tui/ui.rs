use ratatui::{
    prelude::{Alignment, Frame},
    style::{Style, Color},
    widgets::{Block, Borders, BorderType, Paragraph},
};

use super::app::App;

pub fn render(app: &mut App, f: &mut Frame) {
    f.render_widget(
    Paragraph::new(format!(
      "
        Press `Esc`, `Ctrl-C` or `q` to stop running.\n\
        Press `j` and `k` to increment and decrement the counter respectively.\n\
        Counter: {}
      ",
      app.counter
    ))
    .block(
      Block::default()
        .title("Counter App")
        .title_alignment(Alignment::Center)
        .borders(Borders::ALL)
        .border_type(BorderType::Rounded),
    )
    .style(Style::default().fg(Color::Yellow))
    .alignment(Alignment::Center),
    f.size(),
  )
}
