from PyQt6 import QtGui
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import *
from PyQt6.QtCore import Qt
from Forms.VerificationWindow import Ui_VericationWindow
from user import UserList
import main_menu


class VerificationWindow(QDialog, Ui_VericationWindow):
    def __init__(self, user_list: UserList, parent=None, *args, **kwargs):
        super().__init__(parent, *args, **kwargs)
        self.setWindowFlag(Qt.WindowType.Dialog)
        self.setWindowModality(Qt.WindowModality.ApplicationModal)
        self.setupUi(self)
        self.icon = QtGui.QIcon("Images:icon.png")
        assert not self.icon.isNull()
        self.setWindowIcon(self.icon)
        self.user_list = user_list
        self.is_login = False

    @pyqtSlot()
    def on_loginButton_clicked(self):
        if self.user_list.user_list.get(self.cardNumTextEdit.toPlainText()) is None:
            QMessageBox.warning(self, "喜报", "卡号不存在", QMessageBox.StandardButton.Ok,
                                QMessageBox.StandardButton.Ok)
            return

        if self.user_list.user_list[self.cardNumTextEdit.toPlainText()].wrong_pwd_cnt >= 3:
            QMessageBox.warning(self, "喜报", "该卡已被锁定", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)
            return

        if self.user_list.user_list[self.cardNumTextEdit.toPlainText()].password \
                != self.passwordTextEdit.toPlainText():
            self.user_list.user_list[self.cardNumTextEdit.toPlainText()].wrong_pwd_cnt += 1
            QMessageBox.warning(self, "喜报", "密码错误", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)
            if self.user_list.user_list[self.cardNumTextEdit.toPlainText()].wrong_pwd_cnt >= 3:
                QMessageBox.warning(self, "喜报", "密码连续错误 3次，该卡已被锁定", QMessageBox.StandardButton.Ok,
                                    QMessageBox.StandardButton.Ok)
            return
        # 正确输入密码将对应卡号错误密码次数归零
        self.user_list.user_list[self.cardNumTextEdit.toPlainText()].wrong_pwd_cnt = 0
        self.is_login = True
        self.close()

    @pyqtSlot()
    def on_backButton_clicked(self):
        self.w_main_menu = main_menu.MainMenu(self.user_list)
        self.w_main_menu.show()
        self.close()
