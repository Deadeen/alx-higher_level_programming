#!/usr/bin/python3
import random
number = random.randint(-10000, 10000)
bnum = int(str(number)[-1]) if number >= 0 else -int(str(-number)[-1])
if (bnum > 5):
    res = "greater than 5"
elif (bnum == 0):
    res = 0
else:
    res = "less than 6 and not 0"
print(f"Last digit of {number} is {bnum} and is {res}")
