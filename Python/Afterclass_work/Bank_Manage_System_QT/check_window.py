from PyQt6 import QtGui
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import *
from Forms.CheckWindow import Ui_CheckWindow
from user import *
import main_menu
import verification_window


class CheckWindow(QWidget, Ui_CheckWindow):
    def __init__(self, user_list: UserList, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.setupUi(self)
        self.icon = QtGui.QIcon("Images:icon.png")
        assert not self.icon.isNull()
        self.setWindowIcon(self.icon)
        self.hide()
        self.user_list = user_list

        self.w_verification_window = verification_window.VerificationWindow(self.user_list, self)
        self.w_verification_window.exec()
        if self.w_verification_window.is_login is False:
            self.close()
            return

        card_num = self.w_verification_window.cardNumTextEdit.toPlainText()
        self.cardNumLabel.setText("卡号：" + card_num)
        self.nameLabel.setText("持卡人姓名：" + self.user_list.user_list[card_num].name)
        self.phoneLabel.setText("预留手机号：" + self.user_list.user_list[card_num].phone)
        self.balanceLabel.setText("余额：" + str(self.user_list.user_list[card_num].balance))
        self.show()

    @pyqtSlot()
    def on_backButton_clicked(self):
        self.w_main_menu = main_menu.MainMenu(self.user_list)
        self.w_main_menu.show()
        self.close()
