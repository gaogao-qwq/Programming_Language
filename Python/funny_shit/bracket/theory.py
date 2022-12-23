import ast


def myPrint(string: str):
    tab = 0
    tab_str = "    "
    for char in string:
        if char in "([{":
            print(char, end="")
            tab += 1
            print("\n", end=tab_str * tab)
        elif char in ")]}":
            print()
            tab -= 1
            print(tab_str * tab, end=char)
        elif char == ",":
            print(char)
            print(tab_str * tab, end="")
        else:
            print(char, end="")


string = """
a = 15
if (a == 15):{
    print(a)
}
else:{
    print("no")
}

"""

myPrint(ast.dump(ast.parse(string)))
