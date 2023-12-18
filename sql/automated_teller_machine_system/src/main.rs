mod entity;

use mysql::{Pool, PooledConn, prelude::Queryable};
use url::Url;

const SHOW_DATABASE: &str = "SHOW DATABASES;";
const CREATE_DATABASE_QUERY: &str = "CREATE DATABASE IF NOT EXISTS bank_system;";
const USE_DATABASE_QUERY: &str = "USE bank_system;";

fn init_database(conn: &mut PooledConn) -> std::result::Result<(), mysql::Error> {
    let results: Vec<String> = conn.query(SHOW_DATABASE)?;
    if !results.contains(&String::from("bank_system")) {
        println!("Database not exist, creating one...");
        conn.query_drop(CREATE_DATABASE_QUERY)?;
    }
    conn.query_drop(USE_DATABASE_QUERY)?;
    Ok(())
}

fn main() -> std::result::Result<(), Box<dyn std::error::Error>> {
    let url = Url::parse("mysql://root:root@localhost:3306")?;

    let pool = Pool::new(url.as_str())?;

    let mut conn = pool.get_conn()?;
    init_database(&mut conn)?;

    let version = conn.server_version();
    println!("Version: {}.{}.{}", version.0, version.1, version.2);

    Ok(())
}
