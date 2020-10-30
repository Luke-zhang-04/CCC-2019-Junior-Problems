#!/usr/bin/env python3

rows = int(input())
columns = int(input())

squares = {}

for i in range(rows):
    vals = input().split(" ")

    for (index, val) in enumerate(vals):
        squares[f"{i}, {index}"] = int(val)

print(squares)


