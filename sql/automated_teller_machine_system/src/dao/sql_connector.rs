use mysql::{Pool, PooledConn};
use once_cell::sync::OnceCell;
use url::Url;

#[derive(Debug)]
pub struct SqlConnector {
    pool: Pool,
}

static CONNECTOR: OnceCell<SqlConnector> = OnceCell::new();

impl SqlConnector {
    pub fn get_conn() -> PooledConn {
        return CONNECTOR.get().expect("SqlConnector not initialized yet")
            .pool.get_conn().expect("Failed to get connection from pool");
    }

    pub fn init_conn() -> std::result::Result<(), Box<dyn std::error::Error>> {
        let url = Url::parse("mysql://root:root@localhost:3306")?;
        let pool = Pool::new(url.as_str())?;
        CONNECTOR.set(SqlConnector { pool }).expect("Failed to initialize SqlConnector");
        Ok(())
    }
}

