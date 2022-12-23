from PyQt6 import QtGui
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import *
from Forms.DepositWindow import Ui_deposit_window
from user import *
import main_menu
import verification_window


class DepositWindow(QWidget, Ui_deposit_window):
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
        self.card_num = self.w_verification_window.cardNumTextEdit.toPlainText()
        self.balanceLabel.setText("余额：" + str(self.user_list.user_list[self.card_num].balance))
        self.show()

    @pyqtSlot()
    def on_depositButton_clicked(self):
        if float(self.depositTextEdit.toPlainText()) <= 0.0:
            QMessageBox.warning(self, "喜报", "转账金额不得为 0 或负数", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)
            return

        self.user_list.user_list[self.card_num].balance += float(self.depositTextEdit.toPlainText())
        self.balanceLabel.setText("余额：" + str(self.user_list.user_list[self.card_num].balance))
        QMessageBox.warning(self, "喜报", "存款成功", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)

    @pyqtSlot()
    def on_backButton_clicked(self):
        self.w_main_menu = main_menu.MainMenu(self.user_list)
        self.w_main_menu.show()
        self.close()
