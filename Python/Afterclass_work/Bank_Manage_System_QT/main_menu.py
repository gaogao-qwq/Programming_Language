from pathlib import Path
from PyQt6 import QtCore, QtGui
from PyQt6.QtCore import pyqtSlot
from PyQt6.QtWidgets import *
from Forms.MainMenu import Ui_MainWindow
from user import UserList

import os
import setup_window
import check_window
import deposit_window
import withdraw_window
import transfer_window

CURRENT_DIRECTORY = Path(__file__).resolve().parent
QtCore.QDir.addSearchPath("Images", os.fspath(CURRENT_DIRECTORY / "Images"))


class MainMenu(QMainWindow, Ui_MainWindow):
    def __init__(self, user_list: UserList, *args, **kwargs):
        super().__init__(*args, **kwargs)
        self.setupUi(self)
        self.icon = QtGui.QIcon("Images:icon.png")
        assert not self.icon.isNull()
        self.setWindowIcon(self.icon)
        self.user_list = user_list

    @pyqtSlot()
    def on_setupButton_clicked(self):
        self.w_setup_window = setup_window.SetupWindow(self.user_list)
        self.w_setup_window.show()
        self.close()

    @pyqtSlot()
    def on_checkButton_clicked(self):
        self.w_check_window = check_window.CheckWindow(self.user_list)
        self.close()

    @pyqtSlot()
    def on_depositButton_clicked(self):
        self.w_deposit_window = deposit_window.DepositWindow(self.user_list)
        self.close()

    @pyqtSlot()
    def on_withdrawButton_clicked(self):
        self.w_withdraw_window = withdraw_window.WithdrawWindow(self.user_list)
        self.close()

    @pyqtSlot()
    def on_transferButton_clicked(self):
        self.w_transfer_window = transfer_window.TransferWindow(self.user_list)
        self.close()

    @pyqtSlot()
    def on_quitButton_clicked(self):
        self.close()
        exit(0)
