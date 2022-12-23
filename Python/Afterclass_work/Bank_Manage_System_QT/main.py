from PyQt6.QtWidgets import *
from main_menu import MainMenu
from user import *
import sys


def main():
    application = QApplication(sys.argv)
    # debug 用
    user_list = UserList({"123456": User("Pixy", "000002", "10001", 114514.0, "123456"),
                          "654321": User("Cipher", "000001", "10086", 1919810.0, "654321")})

    w_main_menu = MainMenu(user_list)
    w_main_menu.show()

    application.exec()


if __name__ == '__main__':
    main()
