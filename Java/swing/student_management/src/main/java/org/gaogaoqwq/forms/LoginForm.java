package org.gaogaoqwq.forms;

import org.gaogaoqwq.repository.StudentRepository;

import javax.swing.*;

public class LoginForm extends JFrame {
    public JPanel contentPanel;
    private JTextField snoField;
    public JButton loginButton;
    public JPasswordField passwordField;

    public LoginForm() {
        setContentPane(contentPanel);
        setTitle("学生管理系统-登录");
        setSize(500, 300);
        getRootPane().setDefaultButton(loginButton);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

        loginButton.addActionListener(e -> {
            String sno = snoField.getText();
            String password = String.valueOf(passwordField.getPassword());
            if (sno.isEmpty()) {
                JOptionPane.showMessageDialog(
                        null, "学号不能为空！", "Oops", JOptionPane.ERROR_MESSAGE);
                return;
            }
            if (password.isEmpty()) {
                JOptionPane.showMessageDialog(
                        null, "密码不能为空！", "Oops", JOptionPane.ERROR_MESSAGE);
                return;
            }
            if (!StudentRepository.validateStudent(sno, password)) {
                JOptionPane.showMessageDialog(
                        null, "学号或密码错误！", "Oops", JOptionPane.ERROR_MESSAGE);
                return;
            }
            new ManageForm();
            dispose();
        });

        setVisible(true);
    }
}
