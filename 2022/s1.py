#!/bin/python

num = int(input())

possibilities = 0

while num >= 0:
    if num % 4 == 0:
        possibilities += 1

    num -= 5

print(possibilities)
