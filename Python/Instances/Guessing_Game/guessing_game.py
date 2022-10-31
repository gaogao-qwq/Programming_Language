import random

var1 = random.randrange(1, 10)
var2 = int(input("Guess a num:"))
while var1 != var2:
    if var2 < var1:
        print("Smaller than the num")
    else:
        print("Bigger than the num")
    var2 = int(input("Guess a num:"))
print("You win, the number is:", var2)
