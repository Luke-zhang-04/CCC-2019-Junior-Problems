#!/bin/python3

# NOTE: all rotations calculated counter-clockwise

import sys
from typing import List

size = int(sys.stdin.readline(), 10)  # Grid size

sunflowers = [
    [int(val, 10) for val in sys.stdin.readline().split(" ")] for _ in range(size)
]  # Grid of sunflowers


def printGrid(grid: List[List[int]]) -> None:
    """Prints `grid` to stdout"""

    for row in grid:
        print(*row)


def rotate(grid: List[List[int]], amt: int = 0) -> List[List[int]]:
    """Rotates `grid` clockwise by `amt` degrees (must be a multiple of 90) and
    returns it

    Prepare for some monstrous one statement code
    """

    if amt == 90 or amt == 270:
        # For accessing last index if `amt == 90`
        multiplier, increment = (-1, 1) if amt == 90 else (1, 0)

        return [
            list(
                map(
                    # Put all the numbers in one column in a row
                    lambda row: row[multiplier * (index + increment)],
                    grid,
                )
            )[:: multiplier * -1]
            for index in range(len(grid))  # For each column in the grid
        ]

    elif amt == 180:
        return list(
            map(
                lambda row: row[::-1],  # Go through each row and reverse the contents
                grid,
            )
        )[::-1]

    return grid  # `amt` = 0, return grid


def gridIsValid(grid: List[List[int]]) -> bool:
    """Tests if `grid` is a valid sunflower grid by testing each row and then
    each columns's numbers

    returns whether or not `grid` is a valid sunflower grid
    """
    for index in range(len(grid)):
        for row in range(len(grid) - 1):  # Check vertically
            if grid[row][index] > grid[row + 1][index]:  # Next value is greater
                return False

        for column in range(len(grid) - 1):  # Check horizontally
            if grid[index][column] > grid[index][column + 1]:  # Next value is greater
                return False

    return True


for orientation in (0, 90, 180, 270):
    newGrid = rotate(sunflowers, orientation)

    if gridIsValid(newGrid):
        printGrid(newGrid)

        break
