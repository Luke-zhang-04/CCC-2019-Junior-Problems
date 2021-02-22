#!/bin/python3

import sys

numberOfBoards = int(sys.stdin.readline(), 10)

boardHeights = tuple(map(int, sys.stdin.readline().split()))  # Height of all the boads
boardWidths = tuple(map(int, sys.stdin.readline().split()))  # Width of all the boards

totalArea = sum(
    # Iterate through each board and callculate the area
    [
        boardWidths[i] * ((boardHeights[i] + boardHeights[i + 1]) / 2)
        for i in range(len(boardWidths))
    ]
)

print(totalArea)
