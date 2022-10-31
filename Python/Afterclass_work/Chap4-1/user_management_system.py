user = {"Wangwu": "123456", "Zhangsan": "456789", "Lisi": "789123"}


def menu() -> None:
    print("{:+^30}".format("欢迎使用用户账户管理系统"))
    print("1.打印已有账号")
    print("2.添加新账号")
    print("3.删除账号")
    print("4.查询账号对应密码")
    print("5.修改密码")
    print("0.退出")
    print("+" * 38)


def print_user() -> None:
    for i in user:
        print("账号：" + i + " 密码：" + user[i])


def add_user() -> None:
    act = input("请输入新的账号：")
    if user.get(act) is not None:
        print("你输入的账号已经存在")
        return
    user[act] = input("请输入密码：")
    print("账号添加成功")


def delete_user() -> None:
    act = input("请输入要删除的账号：")
    if user.get(act) is None:
        print("你输入的账号不存在")
        return
    user.pop(act)
    print("账号删除成功")


def search_user() -> None:
    act = input("请输入要查找的账号：")
    if user.get(act) is None:
        print("你输入的账号不存在")
        return
    print("账号：" + act + " 当前密码是：" + user[act])


def change_pwd() -> None:
    act = input("请输入要更改密码的账号：")
    if user.get(act) is None:
        print("你输入的账号不存在")
        return
    user[act] = input("请输入新密码：")


while True:
    menu()
    match (input("请输入要进行的操作：")):
        case "1":
            print_user()
        case "2":
            add_user()
        case "3":
            delete_user()
        case "4":
            search_user()
        case "5":
            change_pwd()
        case "0":
            break
        case _:
            ValueError("Illegal num")
