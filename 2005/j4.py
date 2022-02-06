#!/bin/python

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


def moveRight():
    global x, y, lastDirection

    grid[y][x + 1] = True
    x += 1
    lastDirection = "r"


def canMoveRight():
    return x + 1 < len(grid[0]) and grid[y][x + 1] == False


def moveLeft():
    global x, y, lastDirection

    grid[y][x - 1] = True
    x -= 1
    lastDirection = "l"


def canMoveLeft():
    return x - 1 >= 0 and grid[y][x - 1] == False


def moveUp():
    global x, y, lastDirection

    grid[y - 1][x] = True
    y -= 1
    lastDirection = "u"


def canMoveUp():
    return y - 1 >= 0 and grid[y - 1][x] == False


def moveDown():
    global x, y, lastDirection

    grid[y + 1][x] = True
    y += 1
    lastDirection = "d"


def canMoveDown():
    return y + 1 < len(grid) and grid[y + 1][x] == False


for _ in range(steps):
    if lastDirection == None or lastDirection == "r":
        if canMoveUp():
            moveUp()
        elif canMoveRight():
            moveRight()
        elif canMoveDown():
            moveDown()
        else:
            break
    elif lastDirection == "l":
        if canMoveDown():
            moveDown()
        elif canMoveLeft():
            moveLeft()
        elif canMoveUp():
            moveUp()
        else:
            break
    elif lastDirection == "u":
        if canMoveLeft():
            moveLeft()
        elif canMoveUp():
            moveUp()
        elif canMoveRight():
            moveRight()
        else:
            break
    elif lastDirection == "d":
        if canMoveRight():
            moveRight()
        elif canMoveDown():
            moveDown()
        elif canMoveLeft():
            moveLeft()

        else:
            break

print(x + 1)
print(y + 1)
