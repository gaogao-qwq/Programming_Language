package org.gaogaoqwq;

import org.gaogaoqwq.dao.SqlConnector;

import java.sql.Connection;

public class DataInitialzer {

    private static final Connection conn = SqlConnector.getConn();

    public static void init() {
        initDatabase();
        initTable();
        initData();
    }

    private static void initDatabase() {
        try {
            var statement = conn.createStatement();
            statement.execute("CREATE DATABASE IF NOT EXISTS student_management;");
            statement.execute("USE student_management;");
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to initialize database: " + e.getMessage());
            System.exit(1);
        }
    }

    private static void initTable() {
        try {
            var statement = conn.createStatement();
            statement.execute(
                    "CREATE TABLE IF NOT EXISTS student (" +
                            "id INT PRIMARY KEY AUTO_INCREMENT," +
                            "sno VARCHAR(255) NOT NULL," +
                            "name VARCHAR(255) NOT NULL," +
                            "password VARCHAR(255) NOT NULL," +
                            "chinese_score INT NOT NULL," +
                            "math_score INT NOT NULL," +
                            "INDEX (sno, name)" +
                        ");"
            );
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to initialize table: " + e.getMessage());
            System.exit(1);
        }
    }

    private static void initData() {
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT COUNT(*) FROM student;");
            if (res.next() && res.getInt(1) > 0) {
                statement.close();
                return;
            }
            statement.execute(
                    "INSERT INTO student (sno, name, password, chinese_score, math_score) VALUES " +
                            "('2018210000', '张三', '123456', 90, 80)," +
                            "('2018210001', '李四', '654321', 80, 90)," +
                            "('2018210002', '王五', '123456', 70, 70)," +
                            "('2018210003', '赵六', '123456', 60, 60)," +
                            "('2018210004', '钱七', '123456', 50, 50)," +
                            "('1234567890', '你好', '123456', 100, 100);"
            );
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to initialize data: " + e.getMessage());
            System.exit(1);
        }
    }

}
