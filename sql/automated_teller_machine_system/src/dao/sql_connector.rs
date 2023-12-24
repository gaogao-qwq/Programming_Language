use mysql::{Pool, PooledConn, prelude::Queryable};
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

    pub fn get_bank_system_conn() -> PooledConn {
        let mut conn =  CONNECTOR.get().expect("SqlConnector not initilized yet")
            .pool.get_conn().expect("Failed to get connection from pool");
        conn.query_drop("USE bank_system").expect("Failed to get bank_system database");
        return conn;
    }

    pub fn init_conn() -> std::result::Result<(), Box<dyn std::error::Error>> {
        let url = Url::parse("mysql://root:root@localhost:3306")?;
        let pool = Pool::new(url.as_str())?;
        CONNECTOR.set(SqlConnector { pool }).expect("Failed to initialize SqlConnector");
        Ok(())
    }
}

