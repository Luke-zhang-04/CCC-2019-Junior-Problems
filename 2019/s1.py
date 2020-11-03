#!/bin/python3

flips = input()  # Get flip input

hCount = flips.count("H")  # Get count of "h"
vCount = len(flips) - hCount  # Get count of "v"

"""If vCount is even, it's just the grid
Otherwise, it's a grid flipped on the vertical axis
"""
grid = [[1, 2], [3, 4]] if vCount % 2 == 0 else [[2, 1], [4, 3]]

"""If hCount is even, skip
Otherwise, it's a grid flipped on the horizontal axis
"""
if hCount % 2 == 1:
    grid[0], grid[1] = grid[1], grid[0]

print(*grid[0])
print(*grid[1])
