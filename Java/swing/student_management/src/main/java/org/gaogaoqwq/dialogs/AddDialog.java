package org.gaogaoqwq.dialogs;

import org.gaogaoqwq.entity.Student;
import org.gaogaoqwq.repository.StudentRepository;

import javax.swing.*;
import java.awt.event.KeyEvent;

public class AddDialog extends JDialog {
    private JPanel contentPane;
    private JButton buttonOK;
    private JButton buttonCancel;
    private JTextField snoField;
    private JTextField nameField;
    private JTextField chineseField;
    private JTextField mathField;
    private JPasswordField passwordField;

    public AddDialog() {
        setContentPane(contentPane);
        setTitle("添加学生");
        setSize(500, 300);
        setModal(true);
        getRootPane().setDefaultButton(buttonOK);

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
        var password = String.valueOf(passwordField.getPassword());

        if (sno.isEmpty() || name.isEmpty() || chineseScore.isEmpty() || mathScore.isEmpty() || password.isEmpty()) {
            JOptionPane.showMessageDialog(
                    null, "请填写完整", "Opps", JOptionPane.ERROR_MESSAGE);
            return;
        }

        var res = StudentRepository.addStudent(Student.builder()
                .sno(sno)
                .name(name)
                .chineseScore(Integer.parseInt(chineseScore))
                .mathScore(Integer.parseInt(mathScore))
                .password(password).build());
        if (res == 0) {
            JOptionPane.showMessageDialog(
                    null, "添加失败", "Opps", JOptionPane.ERROR_MESSAGE);
            return;
        }
        dispose();
    }

    private void onCancel() {
        dispose();
    }

}
