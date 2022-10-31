class Friend:
    id = ""
    name = ""

    def __init__(self, _id, _name):
        self.name = _name
        self.id = _id


friends = [Friend("114514", "李田所"), Friend("1919", "朴秀"), Friend("810", "德川")]


def menu() -> None:
    print("欢迎使用好友管理系统")
    print("1.添加好友")
    print("2.删除好友")
    print("3.修改好友")
    print("4.展示好友")
    print("0.退出")


def add_friend() -> None:
    friends.append(Friend(input("请输入好友ID号："), input("请输入好友昵称：")))


def delete_friend() -> None:
    _id = input("请输入要删除的好友ID号：")
    for i in range(len(friends)):
        if friends[i].id == _id:
            friends.pop(i)
            return
    print("未找到该ID")


def edit_friend() -> None:
    _id = input("请输入要修改的好友ID号：")
    for i in range(len(friends)):
        if friends[i].id == _id:
            friends[i].id = input("请输入修改后好友ID号：")
            friends[i].name = input("请输入修改后好友昵称：")
            return
    print("未找到该ID")


def print_friend() -> None:
    for i in friends:
        print("好友ID号：" + i.id + " 好友昵称：" + i.name)


while True:
    menu()
    match (input("请输入选项：")):
        case "1":
            add_friend()
        case "2":
            delete_friend()
        case "3":
            edit_friend()
        case "4":
            print_friend()
        case "0":
            break
        case _:
            ValueError("Illegal num")
