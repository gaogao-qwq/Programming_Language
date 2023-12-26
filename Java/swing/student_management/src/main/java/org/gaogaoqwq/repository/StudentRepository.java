package org.gaogaoqwq.repository;

import org.gaogaoqwq.dao.SqlConnector;
import org.gaogaoqwq.entity.Student;

import java.sql.Connection;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

import static java.text.MessageFormat.*;

public class StudentRepository {

    private static final Connection conn = SqlConnector.getConn();

    public static boolean addStudent(Student student) {
        boolean result;
        try {
            var statement = conn.createStatement();
            result = statement.execute(
                    format("INSERT INTO student (sno, name, password, chinese_score, math_score) " +
                            "VALUES ({0},{1},{2},{3},{4});",
                            student.getSno(),
                            student.getName(),
                            student.getPassword(),
                            student.getChineseScore(),
                            student.getMathScore()));
        } catch (Exception e) {
            System.out.println("Failed to add student: " + e.getMessage());
            return false;
        }
        return result;
    }

    public static Optional<Student> getStudentBySno(String sno) {
        Optional<Student> student = Optional.empty();
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT * FROM student WHERE sno = " + sno + ";");
            if (res.next()) {
                student = Optional.of(Student.builder()
                        .id(res.getString("id"))
                        .sno(res.getString("sno"))
                        .name(res.getString("name"))
                        .password(res.getString("password"))
                        .chineseScore(res.getInt("chinese_score"))
                        .mathScore(res.getInt("math_score"))
                        .build());
            }
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to get student by sno: " + e.getMessage());
            return student;
        }
        return student;
    }

    public static Optional<Student> getStudentById(int id) {
        Optional<Student> student = Optional.empty();
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT * FROM student WHERE id = " + id + ";");
            if (res.next()) {
                student = Optional.of(Student.builder()
                        .id(res.getString("id"))
                        .sno(res.getString("sno"))
                        .name(res.getString("name"))
                        .password(res.getString("password"))
                        .chineseScore(res.getInt("chinese_score"))
                        .mathScore(res.getInt("math_score"))
                        .build());
            }
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to get student by id: " + e.getMessage());
            return student;
        }
        return student;
    }

    public static List<Student> queryStudentBySno(String sno) {
        List<Student> students = new ArrayList<>();
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT * FROM student WHERE sno LIKE '%" + sno + "%';");
            while (res.next()) {
                students.add(Student.builder()
                        .id(res.getString("id"))
                        .sno(res.getString("sno"))
                        .name(res.getString("name"))
                        .password(res.getString("password"))
                        .chineseScore(res.getInt("chinese_score"))
                        .mathScore(res.getInt("math_score"))
                        .build());
            }
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to query student by sno: " + e.getMessage());
            return List.of();
        }
        return students;
    }

    public static List<Student> queryStudentByName(String name) {
        List<Student> students = new ArrayList<>();
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT * FROM student WHERE name LIKE '%" + name + "%';");
            while (res.next()) {
                students.add(Student.builder()
                        .id(res.getString("id"))
                        .sno(res.getString("sno"))
                        .name(res.getString("name"))
                        .password(res.getString("password"))
                        .chineseScore(res.getInt("chinese_score"))
                        .mathScore(res.getInt("math_score"))
                        .build());
            }
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to query student by name: " + e.getMessage());
            return List.of();
        }
        return students;
    }

    public static List<Student> getStudents() {
        List<Student> students = new ArrayList<>();
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT * FROM student");
            while (res.next()) {
                students.add(Student.builder()
                        .id(res.getString("id"))
                        .sno(res.getString("sno"))
                        .name(res.getString("name"))
                        .password(res.getString("password"))
                        .chineseScore(res.getInt("chinese_score"))
                        .mathScore(res.getInt("math_score"))
                        .build());
            }
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to get students: " + e.getMessage());
            return List.of();
        }
        return students;
    }

    public static boolean validateStudent(String sno, String password) {
        try {
            var statement = conn.createStatement();
            var res = statement.executeQuery("SELECT * FROM student WHERE sno = " + sno + ";");
            if (res.next()) {
                return res.getString("password").equals(password);
            }
            statement.close();
        } catch (Exception e) {
            System.out.println("Failed to validate student: " + e.getMessage());
            return false;
        }
        return false;
    }

    public static int updateStudent(Student student) {
        int result = 0;
        try {
            var statement = conn.createStatement();
            result = statement.executeUpdate(
                    format("UPDATE student SET " +
                                    "sno = {0}, name = {1}, password = {2}, chinese_score = {3}, math_score = {4} " +
                                    "WHERE id = {5};",
                            student.getSno(),
                            student.getName(),
                            student.getPassword(),
                            student.getChineseScore(),
                            student.getMathScore(),
                            student.getId()));
        } catch (Exception e) {
            System.out.println("Failed to update student: " + e.getMessage());
            return result;
        }
        return result;
    }

    public static int deleteStudentBySno(String sno) {
        int result = 0;
        try {
            var statement = conn.createStatement();
            result = statement.executeUpdate("DELETE FROM student WHERE sno = " + sno + ";");
        } catch (Exception e) {
            System.out.println("Failed to delete student by id: " + e.getMessage());
            return result;
        }
        return result;
    }

}
