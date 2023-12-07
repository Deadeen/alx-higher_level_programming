#!/usr/bin/python3
def weight_average(my_list=[]):
    if not my_list:
        return 0

    num = 0
    den = 0

    for tupes in my_list:
        num += tupes[0] * tupes[1]
        den += tupes[1]

    return (num / den)
