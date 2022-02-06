#!/bin/python

from pprint import pprint
from typing import List, Union


width = int(input())
height = int(input())
cutoutWidth = int(input())
cutoutHeight = int(input())
steps = int(input())

# Grid indexed by y, x
grid: List[List[Union[bool, None]]] = [
    [False for _ in range(width)] for _ in range(height)
]

for row in range(cutoutHeight):
    for col in range(cutoutWidth):
        grid[row][col] = None
        grid[row][-col - 1] = None
        grid[-row - 1][col] = None
        grid[-row - 1][-col - 1] = None

# Coords are 0 indexed
x = cutoutWidth
y = 0

grid[y][x] = True

lastDirection = None

for remainingSteps in range(steps, 0, -1):
    if lastDirection == None or lastDirection == "r":
        if y - 1 >= 0 and grid[y - 1][x] == False:
            grid[y - 1][x] = True
            y -= 1
            lastDirection = "u"
        elif x + 1 < len(grid[0]) and grid[y][x + 1] == False:
            grid[y][x + 1] = True
            x += 1
            lastDirection = "r"
        elif y + 1 < len(grid) and grid[y + 1][x] == False:
            grid[y + 1][x] = True
            y += 1
            lastDirection = "d"
        else:
            break
    elif lastDirection == "l":
        if y + 1 < len(grid) and grid[y + 1][x] == False:
            grid[y + 1][x] = True
            y += 1
            lastDirection = "d"
        elif x - 1 >= 0 and grid[y][x - 1] == False:
            grid[y][x - 1] = True
            x -= 1
            lastDirection = "l"
        elif y - 1 >= 0 and grid[y - 1][x] == False:
            grid[y - 1][x] = True
            y -= 1
            lastDirection = "u"
        else:
            break
    elif lastDirection == "u":
        if x - 1 >= 0 and grid[y][x - 1] == False:
            grid[y][x - 1] = True
            x -= 1
            lastDirection = "l"
        elif y - 1 >= 0 and grid[y - 1][x] == False:
            grid[y - 1][x] = True
            y -= 1
            lastDirection = "u"
        elif x + 1 < len(grid[0]) and grid[y][x + 1] == False:
            grid[y][x + 1] = True
            x += 1
            lastDirection = "r"
        else:
            break
    elif lastDirection == "d":
        if x + 1 < len(grid[0]) and grid[y][x + 1] == False:
            grid[y][x + 1] = True
            x += 1
            lastDirection = "r"
        elif y + 1 < len(grid) and grid[y + 1][x] == False:
            grid[y + 1][x] = True
            y += 1
            lastDirection = "d"
        elif x - 1 >= 0 and grid[y][x - 1] == False:
            grid[y][x - 1] = True
            x -= 1
            lastDirection = "l"

        else:
            break

print(x + 1)
print(y + 1)
