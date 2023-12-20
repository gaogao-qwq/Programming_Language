package org.gaogaoqwq.dao;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

public class SqlConnector {
    private static final String connectionString = "jdbc:mysql://localhost:3306";
    private static final String user = "root";
    private static final String password = "root";
    private static Connection conn;

    public static Connection getConn() {
        if (conn == null) {
            try {
                conn = DriverManager.getConnection(connectionString, user, password);
                Runtime.getRuntime().addShutdownHook(new Thread() {
                    @Override
                    public void run() {
                        try {
                            if (conn != null && !conn.isClosed()) {
                                conn.close();
                                System.out.println("MySQL connection closed on program exit.");
                            }
                        } catch (SQLException e) {
                            System.out.println("Failed to close MySQL connection on program exit: " + e.getMessage());
                            System.exit(1);
                        }
                    }
                });
            } catch (Exception e) {
                System.out.println("Failed to connect to MySQL: " + e.getMessage());
                System.exit(1);
            }
        }
        return conn;
    }

    private SqlConnector() {}

}
