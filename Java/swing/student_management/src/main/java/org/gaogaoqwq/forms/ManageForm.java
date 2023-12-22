package org.gaogaoqwq.forms;

import org.gaogaoqwq.dialogs.AddDialog;
import org.gaogaoqwq.dialogs.UpdateDialog;
import org.gaogaoqwq.entity.Student;
import org.gaogaoqwq.repository.StudentRepository;

import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.util.List;

public class ManageForm extends JFrame {
    private JPanel contentPanel;
    private JTable studentTable;
    private JButton addButton;
    private JButton deleteButton;
    private JButton updateButton;
    private JTextField queryField;
    private JButton queryButton;
    private JComboBox queryComboBox;
    private JButton queryCancelButton;

    public ManageForm() {
        setContentPane(contentPanel);
        setTitle("学生管理系统-管理页面");
        setSize(800, 500);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        initQueryComboBox();
        fetchData();

        addButton.addActionListener(e -> onAdd());
        deleteButton.addActionListener(e -> onDelete());
        updateButton.addActionListener(e -> onUpdate());
        queryButton.addActionListener(e -> onQuery());
        queryCancelButton.addActionListener(e -> onQueryCancel());

        setVisible(true);
    }

    private void onAdd() {
        new AddDialog();
        fetchData();
    }

    private void onDelete() {
        var selectedRow = studentTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(
                    null, "请选中一行", "Oops", JOptionPane.ERROR_MESSAGE);
            return;
        }
        var sno = String.valueOf(studentTable.getValueAt(selectedRow, 0));
        var res = StudentRepository.deleteStudentBySno(sno);
        if (res == 0) {
            JOptionPane.showMessageDialog(
                    null, "删除失败", "Oops", JOptionPane.ERROR_MESSAGE);
            return;
        }
        fetchData();
    }

    private void onUpdate() {
        var selectedRow = studentTable.getSelectedRow();
        if (selectedRow == -1) {
            JOptionPane.showMessageDialog(
                    null, "请选中一行", "Oops", JOptionPane.ERROR_MESSAGE);
            return;
        }
        var sno = String.valueOf(studentTable.getValueAt(selectedRow, 0));
        var opt = StudentRepository.getStudentBySno(sno);
        if (opt.isEmpty()) {
            JOptionPane.showMessageDialog(
                    null, "学生不存在", "Oops", JOptionPane.ERROR_MESSAGE);
            return;
        }
        new UpdateDialog(opt.get());
        fetchData();
    }

    private void onQuery() {
        var queryOption = queryComboBox.getSelectedIndex();
        if (queryOption == -1) {
            JOptionPane.showMessageDialog(
                    null, "请选择查询方式", "Oops", JOptionPane.ERROR_MESSAGE);
            return;
        }
        switch (queryOption) {
            case 0 -> {
                var sno = queryField.getText();
                if (sno.isEmpty()) {
                    JOptionPane.showMessageDialog(
                            null, "请输入学号", "Oops", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                var students = StudentRepository.queryStudentBySno(sno);
                if (students.isEmpty()) {
                    JOptionPane.showMessageDialog(
                            null, "未找到该学生", "Oops", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                updateTable(students);
            }
            case 1 -> {
                var name = queryField.getText();
                if (name.isEmpty()) {
                    JOptionPane.showMessageDialog(
                            null, "请输入姓名", "Oops", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                var students = StudentRepository.queryStudentByName(name);
                if (students.isEmpty()) {
                    JOptionPane.showMessageDialog(
                            null, "未找到该学生", "Oops", JOptionPane.ERROR_MESSAGE);
                    return;
                }
                updateTable(students);
            }
        }
    }

    private void onQueryCancel() {
        fetchData();
    }

    private void initQueryComboBox() {
        String[] queryOptions = new String[] { "按学号", "按姓名" };
        var model = new DefaultComboBoxModel<>(queryOptions);
        queryComboBox.setModel(model);
        queryComboBox.setEditable(false);
    }

    private void fetchData() {
        var students = StudentRepository.getStudents();
        updateTable(students);
    }

    private void updateTable(List<Student> students) {
        var columnNames = new String[] { "学号", "姓名", "语文", "数学" };
        var data = students.stream().map(student -> new String[] {
                student.getSno(),
                student.getName(),
                String.valueOf(student.getChineseScore()),
                String.valueOf(student.getMathScore())
        }).toArray(String[][]::new);
        var model = new DefaultTableModel();
        model.setDataVector(data, columnNames);
        studentTable.setModel(model);
        SwingUtilities.updateComponentTreeUI(this);
    }

}
