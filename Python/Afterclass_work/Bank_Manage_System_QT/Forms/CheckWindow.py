# Form implementation generated from reading ui file '.\check_window.ui'
#
# Created by: PyQt6 UI code generator 6.4.0
#
# WARNING: Any manual changes made to this file will be lost when pyuic6 is
# run again.  Do not edit this file unless you know what you are doing.


from PyQt6 import QtCore, QtGui, QtWidgets


class Ui_CheckWindow(object):
    def setupUi(self, CheckWindow):
        CheckWindow.setObjectName("CheckWindow")
        CheckWindow.resize(384, 261)
        self.gridLayout = QtWidgets.QGridLayout(CheckWindow)
        self.gridLayout.setObjectName("gridLayout")
        self.cardNumLabel = QtWidgets.QLabel(CheckWindow)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.cardNumLabel.setFont(font)
        self.cardNumLabel.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.cardNumLabel.setObjectName("cardNumLabel")
        self.gridLayout.addWidget(self.cardNumLabel, 0, 0, 1, 1)
        self.nameLabel = QtWidgets.QLabel(CheckWindow)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.nameLabel.setFont(font)
        self.nameLabel.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.nameLabel.setObjectName("nameLabel")
        self.gridLayout.addWidget(self.nameLabel, 1, 0, 1, 1)
        self.phoneLabel = QtWidgets.QLabel(CheckWindow)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.phoneLabel.setFont(font)
        self.phoneLabel.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.phoneLabel.setObjectName("phoneLabel")
        self.gridLayout.addWidget(self.phoneLabel, 2, 0, 1, 1)
        self.balanceLabel = QtWidgets.QLabel(CheckWindow)
        font = QtGui.QFont()
        font.setPointSize(12)
        self.balanceLabel.setFont(font)
        self.balanceLabel.setAlignment(QtCore.Qt.AlignmentFlag.AlignLeading|QtCore.Qt.AlignmentFlag.AlignLeft|QtCore.Qt.AlignmentFlag.AlignVCenter)
        self.balanceLabel.setObjectName("balanceLabel")
        self.gridLayout.addWidget(self.balanceLabel, 3, 0, 1, 1)
        self.backButton = QtWidgets.QPushButton(CheckWindow)
        font = QtGui.QFont()
        font.setPointSize(16)
        self.backButton.setFont(font)
        self.backButton.setObjectName("backButton")
        self.gridLayout.addWidget(self.backButton, 4, 0, 1, 1)

        self.retranslateUi(CheckWindow)
        QtCore.QMetaObject.connectSlotsByName(CheckWindow)

    def retranslateUi(self, CheckWindow):
        _translate = QtCore.QCoreApplication.translate
        CheckWindow.setWindowTitle(_translate("CheckWindow", "查询"))
        self.cardNumLabel.setText(_translate("CheckWindow", "卡号：000000"))
        self.nameLabel.setText(_translate("CheckWindow", "持卡人姓名："))
        self.phoneLabel.setText(_translate("CheckWindow", "预留手机号："))
        self.balanceLabel.setText(_translate("CheckWindow", "余额：0"))
        self.backButton.setText(_translate("CheckWindow", "返回"))
