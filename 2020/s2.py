#!/bin/python3
import sys

# Recursion limit needs to be high, but the grader won't accept numbers such as 1 000 000
sys.setrecursionlimit(300_000)


rows = int(sys.stdin.readline())  # No. of rows
columns = int(sys.stdin.readline())  # No. of columns

"""Visited squares.
We only need one visited set because if the square has been visited we know
there's no way that square will take us to the end.
This way, we don't look through the same path multiple times.
"""
visited = set()

"""Squares to be stored in the following way:
{valueOfSquare: [productOfCoords...]}
"""
squares = {}

for i in range(rows):
    vals = list(
        map(int, sys.stdin.readline().split())
    )  # Split input by space and convert values to an integer

    for index, val in enumerate(vals):  # Add squares to the squares dictionary
        squareValue = (i + 1) * (index + 1)
        squares.setdefault(val, []).append(squareValue)


def solve(squareValue: int) -> bool:
    # If the value of the square is 1, it can only go to (1, 1).
    # Therefore, we have reached the end.
    if squareValue == 1:
        return True

    for index in squares.setdefault(squareValue, []):
        if index not in visited:  # If square hasn't been visited
            visited.add(index)  # Add to visited
            if solve(index):  # Solve
                return True

    return False


print("yes" if solve(rows * columns) else "no")
