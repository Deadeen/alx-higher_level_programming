#!/usr/bin/python3
import random
number = random.randint(-10000, 10000)
bnum = int(str(number)[-1])
if (bnum > 5):
    res = "greater than 5"
elif (bnum < 6) and (bnum > 0):
    res = "less than 6 and not 0"
else:
    res = "0"
print(f"Last digit of {number} is {bnum} and is {res}")
