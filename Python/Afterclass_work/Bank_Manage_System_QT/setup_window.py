from PyQt6 import QtGui
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import *
from Forms.SetupWindow import Ui_SetupWindow
import main_menu
from user import *


class SetupWindow(QWidget, Ui_SetupWindow):
    def __init__(self, user_list: UserList, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.setupUi(self)
        self.icon = QtGui.QIcon("Images:icon.png")
        assert not self.icon.isNull()
        self.setWindowIcon(self.icon)
        self.user_list = user_list

    @pyqtSlot()
    def on_setupButton_clicked(self):
        user = User(self.nameTextEdit.toPlainText(),
                    self.identityTextEdit.toPlainText(),
                    self.phoneTextEdit.toPlainText(),
                    float(self.balanceTextEdit.toPlainText()),
                    self.passwordTextEdit.toPlainText())
        QMessageBox.warning(self,
                            "喜报",
                            "开户成功，你的卡号为：" + self.user_list.generateCardNum(user),
                            QMessageBox.StandardButton.Ok,
                            QMessageBox.StandardButton.Ok)
        self.nameTextEdit.clear()
        self.identityTextEdit.clear()
        self.phoneTextEdit.clear()
        self.balanceTextEdit.clear()
        self.passwordTextEdit.clear()

    @pyqtSlot()
    def on_backButton_clicked(self):
        self.w_main_menu = main_menu.MainMenu(self.user_list)
        self.w_main_menu.show()
        self.close()
