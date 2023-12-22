use ratatui::{backend::CrosstermBackend, Terminal};

use crate::{
    dao::sql_connector::SqlConnector,
    data_initializer::DataIntializer,
    tui::{
        app::App,
        event::{EventHandler, Event},
        tui::Tui,
        update::update
    }
};

mod tui;
mod entity;
mod repository;
mod service;
mod dao;
mod data_initializer;

fn main() -> std::result::Result<(), Box<dyn std::error::Error>> {
    SqlConnector::init_conn()?;
    DataIntializer::init()?;
    let conn = SqlConnector::get_conn();
    let version = conn.server_version();
    println!("Version: {}.{}.{}", version.0, version.1, version.2);
    
    let mut app = App::new();
    let backend = CrosstermBackend::new(std::io::stderr());
    let terminal = Terminal::new(backend)?;
    let events = EventHandler::new(250);
    let mut tui = Tui::new(terminal, events);
    tui.enter()?;

    while !app.should_quit {
        tui.draw(&mut app)?;
        match tui.events.next()? {
            Event::Tick => {}
            Event::Key(key_event) => update(&mut app, key_event),
            Event::Mouse(_) => {}
            Event::Resize(_, _) => {}
        };
    }

    tui.exit()?;
    Ok(())
}
