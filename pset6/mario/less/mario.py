#!/usr/bin/env python3
# -*- encoding: utf-8 -*-

from cs50 import get_int
from cs50 import get_string

height = 0

while height < 1 or height > 8:
    height = get_int("Height: ")

for i in range(height):
    print(f" " * (height - 1 - i), end="")
    print(f"#" * (i + 1))