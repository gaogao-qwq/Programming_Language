from typing import Dict
import secrets
import string


class User:
    def __init__(self, name: str, identity: str, phone: str, prestore: float, password: str):
        self.name = name
        self.identity = identity
        self.phone = phone
        self.balance = prestore
        self.password = password
        self.wrong_pwd_cnt = 0


class UserList:
    def __init__(self, user_list: Dict[str, User]):
        self.user_list = user_list

    def generateCardNum(self, user: User) -> str:
        while True:
            tmp = "".join(secrets.choice(string.digits) for _ in range(6))
            if self.user_list.get(tmp) is None:
                self.user_list[tmp] = user
                return tmp
