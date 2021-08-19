#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

import cs50
import math

counter = 0
money = 0

while money <= 0:
    money = round(cs50.get_float("Change owde: ") * 100)

while True:

    if money >= 25:
        money -= 25
        counter += 1
    elif money >= 10:
        money -= 10
        counter += 1
    elif money >= 5:
        money -= 5
        counter += 1
    elif money >= 1:
        money -= 1
        counter += 1
    else:
        break

print(f"Minimum amount of coins: {counter}\n")