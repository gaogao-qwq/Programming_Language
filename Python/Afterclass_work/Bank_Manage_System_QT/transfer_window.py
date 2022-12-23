from PyQt6 import QtGui
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import *
from Forms.TransferWindow import Ui_transfer_window
from user import *
import main_menu
import verification_window


class TransferWindow(QWidget, Ui_transfer_window):
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
    def on_transferButton_clicked(self):
        if self.user_list.user_list.get(self.targetCardTextEdit.toPlainText()) is None:
            QMessageBox.warning(self, "喜报", "收款卡号不存在", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)
            return

        if float(self.transferTextEdit.toPlainText()) <= 0:
            QMessageBox.warning(self, "喜报", "转账金额不得为 0 或负数", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)
            return

        if self.user_list.user_list[self.card_num].balance < float(self.transferTextEdit.toPlainText()):
            QMessageBox.warning(self, "喜报", "余额不足", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)
            return

        self.user_list.user_list[self.targetCardTextEdit.toPlainText()].balance += \
            float(self.transferTextEdit.toPlainText())
        self.user_list.user_list[self.card_num].balance -= float(self.transferTextEdit.toPlainText())
        self.balanceLabel.setText("余额：" + str(self.user_list.user_list[self.card_num].balance))
        self.transferTextEdit.setPlainText("0")
        QMessageBox.warning(self, "喜报", "转账成功", QMessageBox.StandardButton.Ok, QMessageBox.StandardButton.Ok)

    @pyqtSlot()
    def on_backButton_clicked(self):
        self.w_main_menu = main_menu.MainMenu(self.user_list)
        self.w_main_menu.show()
        self.close()
