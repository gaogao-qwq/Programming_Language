use ratatui::Frame;
use tui_textarea::TextArea;

#[derive(Debug)]
pub struct CustomerMenuUi<'a> {
    pub input: TextArea<'a>,
}

impl<'a> CustomerMenuUi<'a> {
    
    pub fn new() -> Self {
        Self {
            input: TextArea::default()
        }
    }

    pub fn render(&mut self, f: &mut Frame) {

    }

}
