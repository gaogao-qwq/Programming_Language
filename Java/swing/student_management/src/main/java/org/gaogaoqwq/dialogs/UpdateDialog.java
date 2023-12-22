package org.gaogaoqwq.dialogs;

import org.gaogaoqwq.entity.Student;
import org.gaogaoqwq.repository.StudentRepository;

import javax.swing.*;
import java.awt.event.*;

public class UpdateDialog extends JDialog {
    private JPanel contentPane;
    private JButton buttonOK;
    private JButton buttonCancel;
    private JTextField snoField;
    private JTextField nameField;
    private JTextField chineseField;
    private JTextField mathField;
    private JTextField passwordField;
    private final Student currentStudent;

    public UpdateDialog(Student student) {
        currentStudent = student;
        setContentPane(contentPane);
        setTitle("更新学生");
        setSize(500, 300);
        setModal(true);
        getRootPane().setDefaultButton(buttonOK);
        initTextFields();

        buttonOK.addActionListener(e -> onOK());
        buttonCancel.addActionListener(e -> onCancel());
        contentPane.registerKeyboardAction(e ->
                onCancel(),
                KeyStroke.getKeyStroke(KeyEvent.VK_ESCAPE, 0),
                JComponent.WHEN_ANCESTOR_OF_FOCUSED_COMPONENT);

        setVisible(true);
    }

    private void onOK() {
        var sno = snoField.getText();
        var name = nameField.getText();
        var chineseScore = chineseField.getText();
        var mathScore = mathField.getText();
        var password = passwordField.getText();
        if (sno.isEmpty() || name.isEmpty() || chineseScore.isEmpty() || mathScore.isEmpty() || password.isEmpty()) {
            JOptionPane.showMessageDialog(
                    null, "请填写完整", "Oops", JOptionPane.ERROR_MESSAGE);
            return;
        }

        var student = Student.builder()
                .id(currentStudent.getId())
                .sno(sno)
                .name(name)
                .chineseScore(Integer.parseInt(chineseScore))
                .mathScore(Integer.parseInt(mathScore))
                .password(password)
                .build();
        StudentRepository.updateStudent(student);
        dispose();
    }

    private void onCancel() {
        dispose();
    }

    private void initTextFields() {
        snoField.setText(currentStudent.getSno());
        nameField.setText(currentStudent.getName());
        chineseField.setText(String.valueOf(currentStudent.getChineseScore()));
        mathField.setText(String.valueOf(currentStudent.getMathScore()));
        passwordField.setText(currentStudent.getPassword());
    }
}
